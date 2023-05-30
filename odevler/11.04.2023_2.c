#include<stdio.h>
#include<stdlib.h>

/*
11.04.2023 Soru-2: (x+y/z) – (A^2+4*B) ifadesine ilişkin ikili ağacı çizdiren fonksiyonu yazınız.
*/
struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* Dugum;
Dugum newNode(char value) {
    Dugum node = (Dugum) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Dugum constructTree() {
    Dugum kok = newNode('-');
    kok->left = newNode('+');
    kok->right = newNode('*');
    kok->left->left = newNode('x');
    kok->left->right = newNode('/');
    kok->left->right->left = newNode('y');
    kok->left->right->right = newNode('z');
    kok->right->left = newNode('^');
    kok->right->left->left = newNode('A');
    kok->right->left->right = newNode('2');
    kok->right->right = newNode('*');
    kok->right->right->left = newNode('4');
    kok->right->right->right = newNode('B');
    return kok;
}

void printTree(Dugum node) {
    if (node == NULL) {
        return;
    }
    printf("%c ", node->value);
    printTree(node->left);
    printTree(node->right);
}

int main() {
    Dugum kok = constructTree();
    printf("İkili Ağaç:\n");
    printTree(kok);
    return 0;
}
