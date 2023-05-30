#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MIN_DEGREE 3

struct BTreeNode {
    int *keys;
    struct BTreeNode **child_ptrs;
    int n;
    bool leaf;
};

struct BTreeNode* create_node(bool leaf) {
    struct BTreeNode* node = (struct BTreeNode*) malloc(sizeof(struct BTreeNode));
    node->keys = (int*) malloc((MIN_DEGREE-1) * sizeof(int));
    node->child_ptrs = (struct BTreeNode**) malloc(MIN_DEGREE * sizeof(struct BTreeNode*));
    node->leaf = leaf;
    node->n = 0;
    return node;
}

void split_child(struct BTreeNode* parent, int i, struct BTreeNode* child) {
    struct BTreeNode* new_child = create_node(child->leaf);
    new_child->n = MIN_DEGREE - 1;
    for (int j = 0; j < MIN_DEGREE-1; j++)
        new_child->keys[j] = child->keys[j+MIN_DEGREE];
    if (child->leaf == false) {
        for (int j = 0; j < MIN_DEGREE; j++)
            new_child->child_ptrs[j] = child->child_ptrs[j+MIN_DEGREE];
    }

    child->n = MIN_DEGREE - 1;

    for (int j = parent->n; j >= i+1; j--)
        parent->child_ptrs[j+1] = parent->child_ptrs[j];
    
    parent->child_ptrs[i+1] = new_child;

    for (int j = parent->n-1; j >= i; j--)
        parent->keys[j+1] = parent->keys[j];
    
    parent->keys[i] = child->keys[MIN_DEGREE-1];
    parent->n = parent->n + 1;
}

void borrow_from_prev(struct BTreeNode* node, int idx) {
    struct BTreeNode* child = node->child_ptrs[idx];
    struct BTreeNode* sibling = node->child_ptrs[idx-1];
    
    for (int i = child->n-1; i >= 0; i--)
        child->keys[i+1] = child->keys[i];

    if (child->leaf == false) {
        for(int i = child->n; i >= 0; i--)
            child->child_ptrs[i+1] = child->child_ptrs[i];
    }
    
    child->keys[0] = node->keys[idx-1];
    
    if (child->leaf == false)
        child->child_ptrs[0] = sibling->child_ptrs[sibling->n];
    
    node->keys[idx-1] = sibling->keys[sibling->n-1];
    child->n += 1;
    sibling->n -= 1;
}

void borrow_from_next(struct BTreeNode* node, int idx) {
    struct BTreeNode* child = node->child_ptrs[idx];
    struct BTreeNode* sibling = node->child_ptrs[idx+1];
    
    child->keys[child->n] = node->keys[idx];
    
    if (child->leaf == false)
        child->child_ptrs[child->n+1] = sibling->child_ptrs[0];
    
    node->keys[idx] = sibling->keys[0];
    
    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i-1] = sibling->keys[i];
    
    if (sibling->leaf == false) {
        for(int i = 0; i < sibling->n; i++)
        sibling->child_ptrs[i-1] = sibling->child_ptrs[i];
            child->n += 1;
            sibling->n -= 1;
    }
 }

void merge(struct BTreeNode* node, int idx) {
struct BTreeNode* child = node->child_ptrs[idx];
struct BTreeNode* sibling = node->child_ptrs[idx+1];

child->keys[MIN_DEGREE-1] = node->keys[idx];

for (int i = 0; i < sibling->n; i++)
    child->keys[i+MIN_DEGREE] = sibling->keys[i];

if (child->leaf == false) {
for(int i = 0; i <= sibling->n; i++)
child->child_ptrs[i+MIN_DEGREE] = sibling->child_ptrs[i];
}

for (int i = idx+1; i < node->n; i++)
node->keys[i-1] = node->keys[i];

for (int i = idx+2; i <= node->n; i++)
node->child_ptrs[i-1] = node->child_ptrs[i];

child->n += sibling->n + 1;

node->n -= 1;
free(sibling->keys);
free(sibling->child_ptrs);
free(sibling);
}

void fill_child(struct BTreeNode* node, int idx) {
if (idx != 0 && node->child_ptrs[idx-1]->n >= MIN_DEGREE)
    borrow_from_prev(node, idx);
else if (idx != node->n && node->child_ptrs[idx+1]->n >= MIN_DEGREE)
    borrow_from_next(node, idx);
else {
    if (idx != node->n)
        merge(node, idx);
    else
        merge(node, idx-1);
}
}

struct BTreeNode* delete_key(struct BTreeNode* node, int key) {
int idx = 0;
while (idx < node->n && node->keys[idx] < key)
    idx++;
if (node->leaf == true) {
    if (idx < node->n && node->keys[idx] == key) {
        for (int i = idx+1; i < node->n; i++)
            node->keys[i-1] = node->keys[i];
            node->n -= 1;
    }

return node;
}

if (idx < node->n && node->keys[idx] == key) {
    if (node->child_ptrs[idx]->n >= MIN_DEGREE) {
        int predecessor = get_predecessor(node, idx);
            node->keys[idx] = predecessor;
            node->child_ptrs[idx] = delete_key(node->child_ptrs[idx], predecessor);
}
else if (node->child_ptrs[idx+1]->n >= MIN_DEGREE) {
int successor = get_successor(node, idx);
node->keys[idx] = successor;
node->child_ptrs[idx+1] = delete_key(node->child_ptrs[idx+1], successor);
}
else {
merge_nodes(node, idx);
node->child_ptrs[idx] = delete_key(node->child_ptrs[idx], key);
}
}
else {
if (node->child_ptrs[idx]->n < MIN_DEGREE)
fill_child(node, idx);
node->child_ptrs[idx] = delete_key(node->child_ptrs[idx], key);
}
return node;
}
