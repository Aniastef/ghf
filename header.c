#include<stdio.h>
#include<stdlib.h>
#include"header.h"

Album_t adaugare(Album_t a, Fotografie_t f)
{
  Fotografie_t *aux=NULL;
  aux=(Fotografie_t*)realloc(a->array, (a->size+1)*sizeof(Fotografie_t));
  if(aux == NULL)
    {
      printf("out of memory\n");
      exit(-1);
    }
  a->array=aux;
  a->array[(a->size)++]=f;
  return a;
}

/gradul de complexitate este O(1)/

void afisare (Album_t *a)
{
    printf("se afiseaza pozele:\n");
  for (int i=0; i<a->size; i++)
    {
      if(a->array[i].width >= a->array[i].height)
	printf("dimensiunea:%dx%d, formatul=%s, peisaj\n", a->array[i].height, a->array[i].width, a->array[i].ext);
      else
	printf("dimensiunea:%dx%d, formatul=%s, portret\n", a->array[i].height, a->array[i].width, a->array[i].ext);
	
    }
}

/gradul de complexitate este O(n) deoarece se itereaza prin tot vectorul/

int cautare (Album_t *a, unsigned w)
{
  for (int i=0; i<a->size; i++)
    {
      if (a->array[i].width == w)
	return i;
    }
  return -1;
}

/*
Gradul de complexitate este O(n), deoarece se itereaza pentru toate elementele din vector, si pentru fiecare se executa comparatia.
*/

void redimensionare(Album_t *a, unsigned w, unsigned p)
{
  int poz=0;
  printf("width=%d is searching...\n", w);
  if ((poz=cautare(a,w)) != (-1)) 
    {
      a->array[poz].width = a->array[poz].width*p/100;
      printf("width found,new width: %d\n", a->array[poz].width);
    }
  else
    printf("width not found\n");
}
