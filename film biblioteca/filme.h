#ifndef FILME_H
#define FILME_H

typedef struct Site* Site_t; //struct Site e protejata (neaccesabila in client.c)

Site_t initializare();
Site_t adaugare(Site_t, char*, char*, int, int);
void afisareFilme(Site_t);
void afisareMaxim(Site_t);
void free_all(Site_t);

#endif // FILME_H
