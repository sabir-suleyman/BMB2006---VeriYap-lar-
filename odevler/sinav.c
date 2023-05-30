#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;
typedef struct node_t* Liste;


void printList(Liste head) {
    node_t* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Bağlı listeden  N’ye bölünen elemanları silen ve yeni bir listeye ekleyen fonksiyon
Liste katlariSil(node_t* head, int N) {
    node_t *current = head, *new_head = NULL, *new_tail = NULL;

    while (current != NULL) {
        if (current->data % N != 0) {
            if (new_head == NULL) {
                new_head = malloc(sizeof(node_t));
                new_tail = new_head;
            } else {
                new_tail->next = malloc(sizeof(node_t));
                new_tail = new_tail->next;
            }
            new_tail->data = current->data;
            new_tail->next = NULL;
        }

        current = current->next;
    }
    
    //Döndürdüğü yeni liste
    return new_head;
}

int main() {
    node_t* head = malloc(sizeof(node_t));
    node_t* node1 = malloc(sizeof(node_t));
    node_t* node2 = malloc(sizeof(node_t));
    node_t* node3 = malloc(sizeof(node_t));
    node_t* node4 = malloc(sizeof(node_t));

    head->data = 1;
    node1->data = 2;
    node2->data = 3;
    node3->data = 4;
    node4->data = 5;

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("Orjinal liste: ");
    printList(head);

    int N = 2;
    node_t* new_head = katlariSil(head, N);

    printf("Yeni liste: ");
    printList(new_head);

    node_t* current = new_head;
    while (current != NULL) {
        node_t* tmp = current;
        current = current->next;
        free(tmp);
    }

    return 0;
}