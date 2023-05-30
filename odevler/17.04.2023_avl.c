#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// Max'i bulan fonksiyon
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Agac yuksekligini geri donen fonksiyon
int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Verilen anahtarla yeni dugum olusturan fonksiyon
struct node *newNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// alt agaci saga dondurmek icin kullanilan fonksiyon (y)
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;


    x->right = y;
    y->left = T2;

    // Yukseklik guncellenmesi
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    
    return x;
}

// alt agaci sola dondurmek icin kullanilan fonksiyon (x)
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    
    y->left = x;
    x->right = T2;

    // Yukseklik guncellenmesi
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    
    return y;
    
}

int main()
{
    
    return 0;
}
