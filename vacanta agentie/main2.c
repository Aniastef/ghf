#include <stdio.h>
#include <stdlib.h>
#include "header2.h"
int main()
{
    Agentie_t *a=NULL;
    a=initializare();
    a=adaugare(a,"continental - timisoara",100,35.5,2);
    a=adaugare(a,"complex - timisoara",200,12.5,4);
    a=adaugare(a,"complex - bucuresti",50,11.20,1);
    a=adaugare(a,"solo - bucuresti",340,1.5,2);
    a=adaugare(a,"navodari - bucuresti",1200,2.5,3);
    a=adaugare(a,"idk - iasi",240,16.5,3);
    afisare(a);
    printf("\n");
    int n=filtrare(a,"timisoara");
    printf("%d",n);
    printf("\n");
    n=filtrare(a,"bucuresti");
    printf("%d",n);

    free_all(a);

    return 0;

}