#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char takimAdi[30];
    int kurulus;
} takim;

typedef struct 
{
    char adSoyad[30];
    int yas;
    takim *team;    // Pointer kullanmak
} futbolcu;

int main()
{
    takim *chelsea = (takim *)malloc(sizeof(takim));
    strcpy(chelsea->takimAdi,"Chelsea");
    chelsea->kurulus = 1855;

     futbolcu hazard;
     strcpy(hazard.adSoyad, "Eden Hazard");
     hazard.yas = 28;
     hazard.team = chelsea;

     printf("Bilgiler: %s %d", hazard.team->takimAdi, hazard.team->kurulus); 
    return 0;
}
