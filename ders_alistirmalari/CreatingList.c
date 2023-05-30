#include <stdio.h>
#include <stdlib.h>

// Creating Node
struct Node
{
    int data;
    struct Node* foward;
};

typedef struct Node Node;

//Typedef of Node Pointer
typedef struct  Node* NodePtr;

// Creating new Node function
NodePtr newNode(int data1) {
   NodePtr n = (NodePtr)malloc(sizeof(Node));
   n->data  = data1;
   n->foward = NULL;
   return n;
}

// Creating List which it contains connected Nodes
struct List
{
    NodePtr start;
    NodePtr end;
};

typedef struct List List;
typedef struct List* ListPtr;

// Creating List function
ListPtr newList(){
    ListPtr n = (ListPtr)(malloc(sizeof(List)));

    n->start = NULL;
    n->end = NULL;
    return n;
}

//Add Node to top of List O(1)
void addHead(ListPtr list, NodePtr node){
    if(list->end == NULL)
        list->end = node;

    node->foward = list->start;
    list->start = node;
    
    
}

void addtoTail(){
    
}

// Print list
void printList(ListPtr list){
   NodePtr temp = list->start;
   while (temp)
   {
    printf("%d ", temp->data);
    temp = temp->foward;
   }
    
}

// Main Function
int main(){
    NodePtr node1, node2, node3;
    node1 = newNode(10);
    node2 = newNode(20);
    node3 = newNode(30);
 // printf("%d\n",node1->data);
 // printf("%d\n",node2->data);

    ListPtr list1;
    list1 = newList();

    addHead(list1,node1);
    addHead(list1,node2);
    addHead(list1,node3);
    addtoTail();
    printList(list1);

    return 0;
}