#include <stdio.h>
#include <stdlib.h>
#include "header2.h"
#include <string.h>

typedef struct vacanta{
    char locatia[50];
    int durata;
    float cost;
    int tip;

}Vacanta_t;

struct agentie{
    Vacanta_t *v;
    int nrv;
};

Agentie_t* initializare()
{
    Agentie_t *a=NULL;
    a=(Agentie_t*)malloc(sizeof(Agentie_t));

    if(a==NULL)
    {
        perror("...");
        exit(-1);
    }
    
    a->v=NULL;
    a->nrv=0;

    return a;
}

Agentie_t* adaugare(Agentie_t* a, char *locatia, int durata, float cost, int tip)
{
    Vacanta_t *aux=NULL;
    aux=(Vacanta_t*)realloc(a->v,(a->nrv+1)*sizeof(Vacanta_t));
    if(aux==NULL)
    {
        perror("...");
        exit(-2);
    }
    else
    {
        a->v=aux;
        a->v[a->nrv].durata=durata;
        a->v[a->nrv].cost=cost;
        a->v[a->nrv].tip=tip;
        strcpy(a->v[a->nrv].locatia,locatia);
        a->nrv++;
    }

    return a;

}

void afisare(Agentie_t*a)
{
    if(a->nrv==0)
    printf("Nu sunt vacante");
    
    Vacanta_t aux;

    for(int i=0;i<a->nrv;i++)
    for(int j=i+1;j<a->nrv-1;j++)
    {
        if((float)(a->v[i].durata*a->v[i].cost)>(float)(a->v[j].durata*a->v[j].cost))
        {
            aux=a->v[i];
            a->v[i]=a->v[j];
            a->v[j]=aux;
        }
    }

    for(int i=0;i<a->nrv;i++)
    {
        printf("%s %d %f ",a->v[i].locatia,a->v[i].durata,a->v[i].cost);
        if(a->v[i].tip==1)
        printf("all inclusive");
        if(a->v[i].tip==2)
        printf("mic dejun+cina");
        if(a->v[i].tip==3)
        printf("mic dejun");
        if(a->v[i].tip==4)
        printf("nimic inclus");
        printf("\n");
    }
}

int filtrare(Agentie_t *a, char *oras)
{
    
    Vacanta_t aux;
    int nr=0;

    for(int i=0;i<a->nrv;i++)
    for(int j=i+1;j<a->nrv-1;j++)
    {
        if(strcmp(a->v[i].locatia,a->v[j].locatia)>0)
        {
            aux=a->v[i];
            a->v[i]=a->v[j];
            a->v[j]=aux;
        }
    }

    for(int i=0;i<a->nrv;i++)
    if(strstr(a->v[i].locatia,oras))
    {
        printf("%s",a->v[i].locatia);
        printf("\n");
        nr++;
    }
    return nr;
}

void free_all(Agentie_t* a)
{
    free(a->v);
    free(a);
}