#include <stdlib.h>
#include "Headers/countingsort.h"

void CountingSort(Produto p[],int t){
    int i, j, h, k=p[0].numero;

    for(i=0;i<t;i++)
        if(p[i].numero>k)
            k=p[i].numero;

    int baldes[k+1];

    for(i=0;i<k;i++)
        baldes[i]=0;
        
    
    for(i=0;i<t;i++)
        baldes[p[i].numero]++;

    for(i=0,j=0;j<k;j++)
        for(h=baldes[j];h>0;h--)
            p[i++].numero=j;
}