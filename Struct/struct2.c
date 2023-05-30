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
    takim team;    // Struct icinde struct kullandik
} futbolcu;

int main()
{
    futbolcu footballer;
    strcpy(footballer.adSoyad," Sabir Suleymanli");
    footballer.yas = 21;
    strcpy(footballer.team.takimAdi,"Bursaspor");
    footballer.team.kurulus = 1965;

    printf("Bilgiler: %s %d", footballer.team.takimAdi,footballer.team.kurulus);


    return 0;
}
