#include <stdio.h>
#include "client.h"
int main()
{
    KVS_t *colectie = initializare();
    adauga(colectie, creeareEl_t(10, 1.2));
    adauga(colectie, creeareEl_t(20, 2.0));
    adauga(colectie, creeareEl_t(30, 5.2));
    printKVS(colectie);
    printf("%d\n", cauta(colectie, 20));
    dealloc(colectie);
    return 0;
}
