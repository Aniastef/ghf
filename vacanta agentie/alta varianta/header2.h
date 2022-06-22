
typedef struct agentie Agentie_t;

Agentie_t* initializare();
Agentie_t* adaugare(Agentie_t*,char*,int,float,int);
void afisare(Agentie_t*);
int filtrare(Agentie_t*, char*);
void free_all(Agentie_t*);
