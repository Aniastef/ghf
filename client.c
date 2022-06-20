#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#define SIZE_MAX 500

int main (void)
{
  Album_t *a=(Album_t *)malloc(SIZE_MAX*sizeof(Album_t));
  if(a == NULL)
    {
      printf("out of memory\n");
      exit(-1);
    }
  Fotografie_t f1;
  f1.width=10;
  f1.height=14;
  strcpy(f1.ext,".png");
  Fotografie_t f2;
  f2.width=900;
  f2.height=8;
  strcpy(f2.ext,".jpeg");
  Fotografie_t f3;
  f3.width=18;
  f3.height=18;
  strcpy(f3.ext, ".png");
  adaugare(a, f1);
  adaugare(a, f2);
  adaugare(a, f3);
  afisare(a);
  redimensionare(a, 900, 5);
  redimensionare(a, 7, 4);
  return 0;
}
