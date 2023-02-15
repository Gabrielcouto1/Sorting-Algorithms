#include <stdlib.h>
#include "Headers/countingsort.h"

void CountingSort(Product p[],int size){
    int i, j, h, k=p[0].number;

    for(i=0;i<size;i++)
        if(p[i].number>k)
            k=p[i].number;

    int buckets[k+1];

    for(i=0;i<k;i++)
        buckets[i]=0;
        
    
    for(i=0;i<size;i++)
        buckets[p[i].number]++;

    for(i=0,j=0;j<k;j++)
        for(h=buckets[j];h>0;h--)
            p[i++].number=j;
}