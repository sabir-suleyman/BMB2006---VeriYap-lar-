#include <stdio.h>
#include <stdlib.h>

// Stack LİFO

struct node {
    int data;
    struct node *next;
};

typedef struct node Dugum;

// Top
Dugum *top = NULL;

//Push
int push(int data) {
    // Stack bos mu
    if (top == NULL)
    {
        Dugum *new = (Dugum *)malloc(sizeof(Dugum));
        new->data = data; 
        new->next = NULL;

        top = new;
    } else   // Stack bos degil ise
    {
        Dugum *new = (Dugum *)malloc(sizeof(Dugum));
        new->data = data; 

        new->next = top;
        top  = new;
    }
    
    return 0;
}

// Stack'imizi yazdirmak icin kullanacagimiz fonksiyon
int display(){
    // Stack bos ise
    if (top == NULL) {
        printf("Stack bostur!!..");
        return 1;
    }

    Dugum *index = top;
    while (index != NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }
    
    printf("\n");
}


//Stack'den eleman silmek icin kullandigimiz fonksiyon
int removefromStack(){
    //Stack bos ise
    if (top == NULL)
    {
    printf("Stack bos!!..");
    return 0;
    }

    Dugum *temp = top;
    top = top->next;
    free(temp);   

    return 0;
}


int main()
{
    push(10);
    push(15);
    push(20);
    
    display();

    removefromStack();
    display();

    removefromStack();
    display();

    removefromStack();
    display();
    

    push(25);
    push(30);
    push(35);

    printf("\n");
    display();

    return 0;
}
