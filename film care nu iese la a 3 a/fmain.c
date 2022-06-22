
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fheader.h"

int main()
{
    Site_t *a=NULL;
    a=initializare();
    a=adaugare(a,"Iron Man", "thriller, actiune", 1202, 123);
    a=adaugare(a,"Supernatural", "thriller, actiune, romance", 3402, 60);
    a=adaugare(a,"101 dalmatieni", "actiune", 5602, 30);
    a=adaugare(a,"Divergent", "romance, actiune, thriller", 5012, 441);
    a=adaugare(a,"Daredevil", "thriller, actiune, romance", 1923, 100);

    afisareFilme(a);
    printf("\n");

    afisareMaxim(a);


    return 0;
}