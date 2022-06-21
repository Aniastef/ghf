#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

typedef struct Film
{
    char nume[41];
    unsigned durata;
    unsigned cost_productie;
    char genuri[33]; //"actiune,comedie,romance,thriller" e maximul care poate fi (33 caractere cu '\0')
}Film_t;

struct Site
{
    Film_t *filme;
    unsigned numar_filme; //Folosit pentru realloc
};

Site_t initializare()
{
    //Alocare spatiu site
    Site_t site = (Site_t)malloc(sizeof(struct Site));

    //Initializari
    site -> filme = NULL;
    site -> numar_filme = 0;
    return site;
}
Site_t adaugare(Site_t site, char *nume, char *genuri, int minute, int cost)
{
    //Alocare spatiu
    site -> filme = (Film_t*)realloc(site -> filme, (site -> numar_filme + 1) * sizeof(Film_t));

    //Copiere film in vector
    strcpy(site -> filme[site -> numar_filme].nume, nume);
    strcpy(site -> filme[site -> numar_filme].genuri, genuri);
    site -> filme[site -> numar_filme].durata = minute;
    site -> filme[site -> numar_filme].cost_productie = cost;

    //Incrementare numar filme
    site -> numar_filme++;

    return site;
}
void afisareFilme(Site_t site)
{
    unsigned i, j;
    float raport1, raport2;
    Film_t aux;
    //sortare dupa raport cost / durata
    for(i = 0; i < site -> numar_filme; ++i)
        for(j = i + 1; j < site -> numar_filme; ++j)
        {
            //Aflare raport filme[i] si filme[j] separat
            raport1 = (float) site -> filme[i].cost_productie / site -> filme[i].durata;
            raport2 = (float) site -> filme[j].cost_productie / site -> filme[j].durata;

            //Sortare descrescatoare
            if(raport1 < raport2)
            {
               aux = site -> filme[i];
               site -> filme[i] = site -> filme[j];
               site -> filme[j] = aux;
            }
        }
    //Afisare filme
    for(i = 0; i < site -> numar_filme; ++i)
    {
        printf("Titlu: %s Durata: %d Cost: %d Genuri: %s\n", site -> filme[i].nume, site -> filme[i].durata, site -> filme[i].cost_productie, site -> filme[i].genuri);
    }
    puts("");
}
void afisareMaxim(Site_t site)
{
    //Initializare maxime durate cu 0 si variabile pentru a stoca filmele
    unsigned durata_thriller = 0, durata_comedie = 0, durata_actiune = 0, durata_romance = 0;
    Film_t film_thriller, film_comedie, film_actiune, film_romance, film;

    unsigned i;

    //Folosit pentru strtok
    char *gen = NULL;
    for(i = 0; i < site -> numar_filme; ++i)
    {
        film = site -> filme[i];

        //Extragere prim gen
        gen = strtok(film.genuri, ",");
        while(gen)
        {
            //Selectie in functie de gen
            if(strcmp(gen, "thriller") == 0)
            {
                //Daca durata e mai mare decat maximul se inlocuieste filmul
                if(film.durata > durata_thriller)
                {
                    durata_thriller = film.durata;
                    film_thriller = film;
                }
            }
            if(strcmp(gen, "comedie") == 0)
            {
                //Daca durata e mai mare decat maximul se inlocuieste filmul
                if(film.durata > durata_comedie)
                {
                    durata_comedie = film.durata;
                    film_comedie = film;
                }
            }
            if(strcmp(gen, "actiune") == 0)
            {
                //Daca durata e mai mare decat maximul se inlocuieste filmul
                if(film.durata > durata_actiune)
                {
                    durata_actiune = film.durata;
                    film_actiune = film;
                }
            }
            if(strcmp(gen, "romance") == 0)
            {
                //Daca durata e mai mare decat maximul se inlocuieste filmul
                if(film.durata > durata_romance)
                {
                    durata_romance = film.durata;
                    film_romance = film;
                }
            }

            //Extragere urmatorul gen
            gen = strtok(NULL, ",");
        }
    }

    //Daca durata_thriller e > 0, adica daca s-a gasit un film gen thriller
    if(durata_thriller)
    {
        puts("Filmul thriller cu durata cea mai lunga: ");
        printf("Titlu: %s \nDurata: %d \nCost: %d \nGenuri: %s\n\n", film_thriller.nume, film_thriller.durata, film_thriller.cost_productie, film_thriller.genuri);
    }
    else puts("Nu exista filme thriller\n");

    //Daca durata_comedie e > 0, adica daca s-a gasit un film gen comedie
    if(durata_comedie)
    {
        puts("Filmul comedie cu durata cea mai lunga: ");
        printf("Titlu: %s \nDurata: %d \nCost: %d \nGenuri: %s\n\n", film_comedie.nume, film_comedie.durata, film_comedie.cost_productie, film_comedie.genuri);
    }
    else puts("Nu exista filme comedie\n");

    //Daca durata_actiune e > 0, adica daca s-a gasit un film gen actiune
    if(durata_actiune)
    {
        puts("Filmul actiune cu durata cea mai lunga: ");
        printf("Titlu: %s \nDurata: %d \nCost: %d \nGenuri: %s\n\n", film_actiune.nume, film_actiune.durata, film_actiune.cost_productie, film_actiune.genuri);
    }
    else puts("Nu exista filme actiune\n");

    //Daca durata_romance e > 0, adica daca s-a gasit un film gen romance
    if(durata_romance)
    {
        puts("Filmul romance cu durata cea mai lunga: ");
        printf("Titlu: %s \nDurata: %d \nCost: %d \nGenuri: %s\n\n", film_romance.nume, film_romance.durata, film_romance.cost_productie, film_romance.genuri);
    }
    else puts("Nu exista filme romance\n");
}
void free_all(Site_t site)
{
    free(site -> filme);
    free(site);
}
