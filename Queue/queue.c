#include <stdio.h>
#include <stdlib.h>

             /*    QUEUE FIFO    */
             
// Queue dugumu
struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

// Front ve Rear tanimlanmasi (Kuyrugumuzun basi ve sonunu isaretlemek icin)
Node *front;
Node *rear;


// Kuyruga veri ekleyecek fonksiyonun tanimlayalim
int addtoQueue(int data){

    // Kuyrugun bos olup olmamasinin kontrolu
    if(front == NULL){                              // Bos ise
        Node *new = (Node *)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL; 

        front = rear = new;
    } else 
    {                                              // Bos degil ise      
        Node *new = (Node *)malloc(sizeof(Node));
        new->data = data;
        new->next = NULL;

        rear->next = new;   // Elemani kutrugun sonuna ekledik

        rear = new;         // Kutrugun sonunu gosteren rear isaretcisini gercekten kuyrugun sonuna tasidik
    }

    return 0;
}

int printQueue(){
        Node *index = front;

        // Kuyruk bos mu
        if (front == NULL)
        {
            printf("Kuyruk bos...\n");
            return 0;
        }
        
        printf("Kuyruk: ");
        while (index != NULL) {
            printf("%d -", index->data);
            index = index->next;
        }
        printf("\n");
        return 0;
    }

int removefromQueue(){

    //Kuyruk bos mu
    if(front == NULL){
        printf("Kuyruk bos...\n");
        return 0;
    }
       
        Node *temp = front;     // front'u gecici bir dugume atadik
        front = front->next;    // front'u guncelledik
        free(temp);             // gecici dugume atadigimiz eski front dugumunu bellekten sildik
    
    
    return 0;
}

int main()
{
    
    addtoQueue(5);
    addtoQueue(10);
    addtoQueue(15);
    addtoQueue(20);
    
    printQueue();

    removefromQueue();

    printQueue();

    removefromQueue();

    printQueue();

    removefromQueue();

    printQueue();

    removefromQueue();

    printQueue();

    return 0;
}
