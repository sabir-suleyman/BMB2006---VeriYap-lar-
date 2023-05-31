#include <stdio.h>
#include <stdlib.h>

//Linked List (Bagli Liste)

struct node
{
    int data;
    struct node *next;
};

typedef struct node Dugum;

// Head ve Tail tanimlanmasi
struct node *head = NULL;
struct node *tail = NULL;

// Add Node to Tail fonksiyonu (Linked List'in sonuna dugum eklenmesini saglar)
int addNodetoTail(int data){
    // Oncelikle Linked List'imizin bos veya dolu oldugunu kontrol etmemiz gerekiyor.

    if (head == NULL) // Linked List'imizin bos oldugu durum
    {
        Dugum *dugum1 = (Dugum *)malloc(sizeof(Dugum));
        dugum1->data = data;
        dugum1->next = NULL;   // Bir sonraki dugum olusturulanadek NULL atiyoruz.
        head = tail = dugum1;  // Bos oldugu icin head ve tail degerlerimiz yeni olusturdugumuz dugumu gostermekte. 

    } else  // Linked List'imizin dolu oldugu durum
    {   
        Dugum *dugum1 = (Dugum *)malloc(sizeof(Dugum));  // Yeni dugum olusturduk.
        dugum1->data = data;                             // Dugumun data degerine fonksiyona gonderilen datayi aktardik.
        dugum1->next  = NULL;                            // Dugumumuzu Linked List'in sonuna ekledigimiz icin next degerine gecici olarak NULL atadik.
        tail->next = dugum1;                             // Yeni olusturdugumuz dugumu Linked List'in sonuna bagladik.    
        tail = dugum1;                                   // Linked List'imizin sonunu isaret eden tail degerine yeni olusturdugumuz dugumumuzu atadik.
    }
    
    
    return 1;
}


// Add Node to Head fonksiyonu (Linked List'in basina dugum eklenmesini saglar)
int addNodetoHead(int data){
    // Oncelikle Linked List'imizin bos veya dolu oldugunu kontrol etmemiz gerekiyor.

    if (head == NULL) // Linked List'imizin bos oldugu durum
    {
        Dugum *dugum1 = (Dugum *)malloc(sizeof(Dugum));
        dugum1->data = data;
        dugum1->next = NULL;   // Bir sonraki dugum olusturulanadek NULL atiyoruz.
        head = tail = dugum1;  // Bos oldugu icin head ve tail degerlerimiz yeni olusturdugumuz dugumu gostermekte. 

    } else  // Linked List'imizin dolu oldugu durum
    {   
        Dugum *dugum1 = (Dugum *)malloc(sizeof(Dugum));  // Yeni dugum olusturduk.
        dugum1->data = data;                             // Dugumun data degerine fonksiyona gonderilen datayi aktardik.
        dugum1->next  = head;                            // Dugumumuzu Linked List'in basina ekledigimiz icin next degerine head'i atadik. 
        head = dugum1;                                   // Linked List'imizin basini isaret eden head degerine yeni olusturdugumuz dugumumuzu atadik.
    }

    return 1;
}


// Remove Node fonksiyonu (Linked List'den eleman silinmesini saglar)
int removeNode(int data){

    Dugum *dugum = NULL;
    Dugum *index = head;  // index Linked List'in basindaki elemani gostermis olacak.


    // Linked List'in bos olup olmadigini kontrol ediyoruz.
    if( head == NULL){  
        printf("Linked List bostur!!..");
        return 1; 
    }

    // Linked List'ten silinecek olan dugum Linked List'in basinda ise:
    if(head->data == data) {  
        Dugum *temp = head;   // Head dugumunu gecici bir dugume atadik.
        head = head->next;
        free(temp);           // Gecici temp dugumunu bellekten sildik.
        return 1;
    }

    // Diger tum ihtimaller
    while (index != NULL && index->data != data)  // indexin adresi NULL degil ise(yani liste sonuna gelmediysek)
    {                                             // ve aradigimiz deger indexin degerine esit degilse
        dugum = index;
        index = index->next;
    }

    if (index == NULL)
    {
        printf("Aranan eleman bu listede yoktur.."); 
        return 1;
    }
    // Eger index NULL'a kadar gitmediyse demek ki aradigimiz deger Linked List'te bulunuyor. 
     
    dugum->next = index->next;

    //Eger sildigimiz eleman Linked List'in sonunda yer aliyorsa ozaman tail'i de guncellememmizz gerekecektir:
    if (tail->data == data)
    {
        tail = dugum;
    }
    
    return 1;
}


// Linked List'i yazdirma
int printList(){
    printf("Linked List elemanlari: ");
    Dugum *index = head;
    while (index != NULL)
    {
        printf("%d -> ", index->data);
        index = index->next;
    }
    
    free(index);  // Tum islemler bittikten sonra index dugumumuzu de silelim
    return 1;
}


int main()
{
    addNodetoTail(10);    
    addNodetoTail(15);
    addNodetoTail(20);

    addNodetoHead(25);
    addNodetoHead(30);
    addNodetoHead(35);
    addNodetoHead(40);  

    addNodetoTail(45);
    addNodetoTail(50);

    printList();

    removeNode(40);   // Listenin basindan silelim
    removeNode(15);   // Liste ortalarindan silelim
    removeNode(50);   // Liste sonundan silelim

    printf("\nGuncel ");
    printList();
    return 0;
}
