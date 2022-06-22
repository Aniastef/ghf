
/*Un student are in sesiune n examene fiecare avand asociat un numar de credite. Pentru a promova sesiunea el trebuie sa acumuleze cel putin s credite.
Gasiti toate nodurile in care poate el sa isi aleaga examenele pentru a promova sesiunea astfel incat sa faca un efort minim, adica sa nu mearga la examene fara de care oricum promoveaza.
Ordinea examenelor nu este importanta, iar daca studentul isi aleage un examen se considera ca il promoveaza.
Ex:
n=6
creditele: 7 8 10 10 2 6
s=30
Solutii:
10 10 8 7
10 10 8 6
10 10 8 2
10 10 7 6
10 8 7 6
10 8 7 6 (se repeta deoarece poate alege oricare din cele 2 examene cu 10 credite)*/

#include <stdio.h>
#include <stdlib.h>

int st[100]= {0};

int valid(int st[],int credite[],int k)
{
    if(k>1)
    {
        for(int i=1; i<k; i++)
            if(st[i]==st[k])
                return 0;
        if(st[k-1]<st[k])
            return 0;
    }
    if(k>6)
        return 0;

    return 1;
}

int solutii(int credite[],int st[],int k)
{
    int s=0;
    for(int i=1; i<=k; i++)
    {
        s=s+credite[st[i]];
        if(s>=30)
            return 1;
    }
    if(s<30)
        return 0;
}

void tipar(int st[],int credite[],int k)
{
    for(int i=1; i<=k; i++)
        printf("%d ",credite[st[i]]);
    printf("\n");

}

int back(int k, int st[],int n,int credite[])
{
    for(int i=0; i<6; i++)
    {
        st[k]=i;
        if(valid(st,credite,k))
            if(solutii(credite,st,k))
                tipar(st,credite,k);
            else
                back(k+1,st,n,credite);
    }
}

int main()
{
    int credite[6]= {2,6,7,8,10,10};


    back(1,st,6,credite);
    return 0;
}
