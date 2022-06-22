#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fheader.h"

typedef struct Film{
    char numefilm[40];
    int durata;
    int cost;
    char gen[40];
}Film_t;

struct Site{
    Film_t *film;
    int nrfilme;
};

Site_t* initializare()
{
    Site_t* a=NULL;
    a=(Site_t*)malloc(sizeof(Site_t));

    if(a==NULL)
    {
        exit(-1);
    }
    else
    {
        a->film=NULL;
        a->nrfilme=0;
    }

    return a;

}

Site_t* adaugare(Site_t* a, char *numefilm, char *gen, int cost, int durata)
{
    Film_t *aux=NULL;
    aux=(Film_t*)realloc(a->film,(a->nrfilme+1)*sizeof(Film_t));
    if(aux==NULL)
    {
        exit(-1);
    }
    else
    {
        a->film=aux;
        strcpy(a->film[a->nrfilme].numefilm,numefilm);
        strcpy(a->film[a->nrfilme].gen,gen);
        a->film[a->nrfilme].cost=cost;
        a->film[a->nrfilme].durata=durata;
        a->nrfilme++;
    }

    return a;

}

void afisareFilme(Site_t* a)
{
    int i,j;
    Film_t aux;

    for(i=0;i<a->nrfilme;i++)
    for(j=0;j<a->nrfilme-1;j++)
    {
        if((float)a->film[i].cost/a->film[i].durata>(float)a->film[j].cost/a->film[j].durata)
        {
            aux=a->film[i];
            a->film[i]=a->film[j];
            a->film[j]=aux;
        }
    }

    for(int i=0;i<a->nrfilme;i++)
    {
       (float)a->film[i].cost/a->film[i].durata; //asa se scrie
        printf("%s %d %d %f", a->film[i].numefilm,a->film[i].cost,a->film[i].durata,(float)a->film[i].cost/a->film[i].durata);
        printf("\n");
    }

}

void afisareMaxim(Site_t *a)
{
    int gen1=-1;
    int gen2=-1;
    int gen3=-1;
    int gen4=-1;

    for(int i=0;i<a->nrfilme;i++)
    {
        if(strstr(a->film[i].gen,"actiune") && a->film[i].durata>gen1)
        gen1=i;
        
        if(strstr(a->film[i].gen,"comedie") && a->film[i].durata>gen2)
        gen2=i;

        if(strstr(a->film[i].gen,"romance") && a->film[i].durata>gen3)
        gen3=i;

        if(strstr(a->film[i].gen,"thriller") && a->film[i].durata>gen4)
        gen4=i;

    }


    if(gen1==-1)
    printf("Nu avem filme de actiune \n");
    else
    printf("Cel mai lung film de actiune este: %s \n",a->film[gen1].numefilm);

    if(gen2==-1)
    printf("Nu avem filme de comedie \n");
    else
    printf("Cel mai lung film de comedie este: %s \n",a->film[gen2].numefilm);

    if(gen3==-1)
    printf("Nu avem filme de romance \n");
    else
    printf("Cel mai lung film de romance este: %s \n",a->film[gen3].numefilm);

    if(gen4==-1)
    printf("Nu avem filme de thriller \n");
    else
    printf("Cel mai lung film de thriller este: %s \n",a->film[gen4].numefilm);



}

