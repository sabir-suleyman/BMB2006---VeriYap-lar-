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
    takim galatasaray;
    strcpy(galatasaray.takimAdi,"Galatasaray");
    galatasaray.kurulus = 1905;


    futbolcu footballer;
    strcpy(footballer.adSoyad,"Elmar Suleymanov");
    footballer.yas = 46;
    footballer.team = galatasaray;

    printf("Bilgiler: %s %d", footballer.team.takimAdi,footballer.team.kurulus);
    return 0;
}
