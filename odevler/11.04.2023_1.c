#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
 /*
   11.04.2023 Soru-1: Verilen bir modelin ağaç olup olmadığını kontrol eden fonksiyonu yazınız.
 */
struct Node { 
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* Dugum;

Dugum newNode(int data) {
    Dugum node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


bool isTree(Dugum node) { 
    if (node == NULL) { 
        return true;
    }
    if (node->left != NULL && node->left->data > node->data) { 
        return false;
    }
    if (node->right != NULL && node->right->data < node->data) { 
        return false;
    }
    if (!isTree(node->left) || !isTree(node->right)) { 
        return false;
    }
    return true; 
}
int main()
{
    Dugum kok1 = newNode(4);    // Agac yapisi
    kok1->left = newNode(2);
    kok1->right = newNode(5);
    kok1->left->left = newNode(1);
    kok1->left->right = newNode(3);

    Dugum kok2 = newNode(4);    // Hatali yapi
    kok2->left = newNode(5);
    kok2->right = newNode(2);
    kok2->left->left = newNode(3);
    kok2->left->right = newNode(4);


    if (isTree(kok1)) // Ekrana "Kok1 ornegi agac yapisidir." yazdirmasi gerek
        printf("%s\n","Kok1 ornegi agac yapisidir.");
    else
        printf("%s\n","Kok1 ornegi agac yapisi degildir.");

    if (isTree(kok2)) // Ekrana "Kok1 ornegi agac yapisi degildir." yazdirmasi gerek
        printf("%s\n","Kok2 ornegi agac yapisidir.");
    else
        printf("%s\n","Kok2 ornegi agac yapisi degildir.");
    return 0;
}
