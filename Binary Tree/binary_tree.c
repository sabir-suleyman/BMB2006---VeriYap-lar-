#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Dugum;


// newNode() fonksiyonu yeni bir dugum olusturmak ve bu dugumun adresini dondurmek gorevlerini ustlenir.
Dugum *newNode(int data)
{
    Dugum *new = (Dugum *)malloc(sizeof(Dugum));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
} 



int main()
{
    // Once kok dugum olusturalim

    Dugum *root = newNode(1);     //                                    1
                                  //                          /                  \
                                  //                         2                    3
                                  //                    /         \          /         \
                                                       4           5        6           7
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Root: %d \n", root->data);
    printf("Root->Left: %d \n", root->left->data);
    printf("Root->Right: %d \n", root->right->data);

    printf("Root->Left->Left: %d \n", root->left->left->data);
    printf("Root->Left->Right: %d \n", root->left->right->data);

    printf("Root->Right->Left: %d \n", root->right->left->data);
    printf("Root->Right->Right: %d \n", root->right->right->data);

    return 0;
}
