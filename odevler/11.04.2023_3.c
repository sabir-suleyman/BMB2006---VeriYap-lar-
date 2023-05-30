#include <stdio.h>
#include <stdlib.h>

/*
11.04.2023 Soru-3: Rastgele sayı üreterek 5 derinliğinde bir ikili ağaç oluşturan, preorder, inorder ve postorder
gezinti sonuçlarını veren fonksiyonu yazınız.
*/
struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node* Dugum;

Dugum newNode(int data) {
    Dugum node = (Dugum)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Preorder gezintisi
void preOrder(Dugum node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// Inorder gezintisi
void inOrder(Dugum node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Postorder gezintisi
void postOrder(Dugum node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

// Yeni bir düğüm oluşturma ve rastgele veri atama
Dugum insertRandom(Dugum node, int derinlik) {
    if (derinlik == 0) 
        return NULL;
    int data = rand() % 100;
    node = newNode(data);
    node->left = insertRandom(node->left, derinlik - 1);
    node->right = insertRandom(node->right, derinlik - 1);
    return node;
}

int main() {
    Dugum kok = NULL;
    int derinlik = 5;
    kok = insertRandom(kok, derinlik);

    printf("Preorder: ");
    preOrder(kok);
    printf("\n");

    printf("Inorder: ");
    inOrder(kok);
    printf("\n");

    printf("Postorder: ");
    postOrder(kok);
    printf("\n");

    return 0;
}
