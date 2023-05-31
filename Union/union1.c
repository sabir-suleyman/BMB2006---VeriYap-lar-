# include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Union - ortak kullanim alani saglayan bir veri yapisidir.
/*
   Union veri yapisi icin bellekte yer ayrilirken icinde bulunan 
   en cok yer kaplayan degiskenin tuttugu bellek miktari kadar yer ayrilir. 
*/
union ogrenci   
{
    char isim[20];
    int no;
    float ort;
};

typedef union
{
    char isim[20];
    int yas;
} ogretmen;



int main()
{
    printf("Boyut: %ld Byte \n", sizeof(union ogrenci));

    union ogrenci sabir;

    strcpy(sabir.isim,"Sabir");
    printf("Isim: %s", sabir.isim); 
    
    sabir.no = 148;
    printf("\nNo: %d", sabir.no);

    sabir.ort = 3.45;
    printf("\nOrtalama: %f",sabir.ort);

    // Typedef ile kullanim
    ogretmen koray;

    strcpy(koray.isim,"Koray");
    printf("\nIsim: %s", koray.isim); 
    
    koray.yas = 30;
    printf("\nYas: %d",koray.yas);
    
    return 0;
}
