#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct kitap
{
    char kitapAdi[30];
    float fiyat;
    int sayfa;    
};

// Typedef kullanimi
typedef struct 
{
    char isim[30];
    int yas;
} yazar;



int main()
{
    // Dogrudan kullanma
    struct kitap turktarihi;
    strcpy(turktarihi.kitapAdi, "Turklerin Tarihi");
    turktarihi.fiyat = 17.50;
    turktarihi.sayfa = 350;

    printf("\nBilgiler: %s %.2f %d\n", turktarihi.kitapAdi, turktarihi.fiyat, turktarihi.sayfa);
    
    // Pointer yardimiyla
    struct kitap *matkitap = (struct kitap *)malloc(sizeof(struct kitap));
    strcpy(matkitap->kitapAdi, "Matematik");
    matkitap->fiyat = 22.5;
    matkitap->sayfa = 500;
    printf("Bilgiler: %s %.2f %d\n\n", matkitap->kitapAdi, matkitap->fiyat, matkitap->sayfa);

    // Typedef ile dogrudan kullanim
    yazar ilberOrtayli;
    strcpy(ilberOrtayli.isim,"Ilber Ortayli");
    ilberOrtayli.yas = 76;

    //Typedef'i pointer ile kullanma
    yazar *celalSengor = (yazar *)malloc(sizeof(yazar));
    strcpy(celalSengor->isim,"Celal Sengor");
    celalSengor->yas = 74;

    printf("1.yazar bilgisi: %s %d\n2.yazar bilgisi: %s %d", ilberOrtayli.isim, ilberOrtayli.yas, celalSengor->isim, celalSengor->yas);
    return 0;
}
