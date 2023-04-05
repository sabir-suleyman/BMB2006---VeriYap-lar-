#include <stdio.h>
#include<stdlib.h>

// Dugum dizayn edilmesi

struct Dugum {
      int data;
      struct Dugum* ileri;
    };
typedef struct Dugum Dugum;    
typedef struct Dugum* DugumPointer;

//Dugum olusturma fonksiyonu
DugumPointer yeniDugum(int veri){
    
    // Bellekte dugum icin yer ayirma
    DugumPointer n = (DugumPointer)malloc(sizeof(Dugum));
    
    n->data = veri;
    n->ileri= NULL;
}


int main() {
    
    DugumPointer n1,n2;
    n1 = yeniDugum(10);
    n2 = yeniDugum(20);
    printf("%d\n",n1->data);
    printf("%p\n",n1->ileri);
    printf("%d\n",n2->data);
    printf("%p\n",n2->ileri);
    return 0;
}