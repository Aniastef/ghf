#include <stdio.h>
#include "filme.h"

int main()
{
    Site_t site = initializare();
    site = adaugare(site, "Marvel", "actiune,thriller", 13, 100);
    site = adaugare(site, "Adel", "actiune,thriller,comedie", 1, 10);
    afisareFilme(site);
    afisareMaxim(site);
    free_all(site);
    return 0;
}
