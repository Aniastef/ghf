#include <stdio.h>
#include <stdlib.h>
typedef struct obiecte
{
    int greutate;
    int cost;
    float raptaiere;

} obiect_t;

int cmp(const void *ob1, const void *ob2)
{
    obiect_t o1=*(obiect_t*)ob1;
    obiect_t o2=*(obiect_t*)ob2;
    return o1.greutate/o1.cost-o2.greutate/o2.cost;
}

int main(int argv, char **argc)
{
    int nrobiecte;
    int gmax;

    if(argv!=3)
    {
        perror("..");
        return -1;
    }

    FILE *in=NULL;
    in=fopen(argc[1],"r");

    if(in==NULL)
    {
        perror("...");
        return -2;
    }

    FILE *out=NULL;
    out=fopen(argc[2],"w");

    if(out==NULL)
    {
        perror("...");
        return -2;
    }

    fscanf(in,"%d %d", &nrobiecte, &gmax);

    obiect_t o[nrobiecte];
    int solutii[nrobiecte];

    for(int i=0; i<nrobiecte; i++)
        fscanf(in,"%d",&o[i].greutate);

    for(int i=0; i<nrobiecte; i++)
        fscanf(in,"%d",&o[i].cost);

    qsort(o,nrobiecte,sizeof(o[0]),cmp);

    int k=0;
    float costadunat=0;

    for(int i=0; i<nrobiecte; i++)
    {
        if(o[i].greutate<=gmax)
        {
            gmax=gmax-o[i].greutate;
            costadunat=costadunat+o[i].cost;
            solutii[k]=i;
            o[i].raptaiere=1;
            k++;


        }
        else if(o[i].greutate>gmax && gmax!=0)
        {

            o[i].raptaiere=(float)gmax/o[i].greutate;
            gmax=0;
            costadunat=costadunat+(float)o[i].cost*o[i].raptaiere;
            solutii[k]=i;
            k++;

        }
        if(gmax==0)
            break;
    }

    for(int i=0; i<k; i++)
    {

        printf("%d %d %f\n",o[solutii[i]].greutate,o[solutii[i]].cost,o[solutii[i]].raptaiere);
    }
    printf("%f",costadunat);

    fclose(in);
    fclose(out);

}
