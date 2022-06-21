#include <stdio.h>
#include <stdlib.h>
#include "client.h"

KVS_t* initializare()
{
    KVS_t *el = NULL;
    el = (KVS_t*)malloc(sizeof(KVS_t));
    if(el == NULL)
    {
        printf("Nu exista suficienta memorie\n");
        exit(-1);
    }
    el -> colectie = NULL;
    el -> nr_elem = 0;
    return el;
}
El_t creeareEl_t(unsigned cheie, float valoare)
{
    El_t el;
    el.cheie = cheie;
    el.valoare = valoare;
    return el;
}
KVS_t* adauga(KVS_t *v,  El_t el)
{
    El_t *aux = v -> colectie;
    v -> nr_elem++;
    v -> colectie = (El_t*)realloc(v -> colectie, sizeof(El_t) * v -> nr_elem); //Spatiul alocat este de O(N)
    if(v -> colectie == NULL)
    {
        free(aux);
        printf("Nu exista suficienta memorie\n");
        exit(-1);
    }
    v -> colectie[v -> nr_elem - 1] = el;
    return v;
}
void printKVS(KVS_t *v)
{
    unsigned i;
    for(i = 0; i < v -> nr_elem; i++) //Complexitatea este de O(n)
    {
        printf("%d = %f\n", v -> colectie[i].cheie, v -> colectie[i].valoare);
    }
}
int cauta(KVS_t *v, unsigned k)
{
    unsigned i;
    for(i = 0; i < v -> nr_elem; i++) //Complexitatea este de O(n)
    {
        if(v -> colectie[i].cheie == k) return i;
    }
    return -1;
}
void dealloc(KVS_t* v)
{
    free(v -> colectie);
    free(v);
}
