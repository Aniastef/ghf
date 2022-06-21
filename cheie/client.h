#ifndef CLIENT_H
#define CLIENT_H

typedef struct
{
    unsigned cheie;
    float valoare;
}El_t;

typedef struct
{
    El_t *colectie;
    unsigned nr_elem;
}KVS_t;

KVS_t* initializare();
void dealloc(KVS_t*);
El_t creeareEl_t(unsigned, float);
KVS_t* adauga(KVS_t*,  El_t);
void printKVS(KVS_t*);
int cauta(KVS_t*, unsigned);

#endif // CLIENT_H
