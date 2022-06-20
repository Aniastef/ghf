typedef struct
{
  unsigned width, height;
  char ext[6];
}Fotografie_t;

typedef struct
{
  Fotografie_t *array;
  unsigned size;
}Album_t;

Album_t* adaugare (Album_t*, Fotografie_t);
void afisare(Album_t*);
void redimensionare(Album_t* a, unsigned w, unsigned p);
