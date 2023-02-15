#include <stdlib.h>
#include <string.h>
#include "Headers/heapsort.h"
#include "Headers/auxiliar_functions.h"

int left(int pos){
    return (pos*2)+1;
}

int right(int pos){
    return (pos*2)+2;
}

void heapMaxPosInt(Product p[], int pos, int heapSize){
    int e, d, max;
    e=left(pos);
    d=right(pos);

    if((e<=heapSize)&&(p[e].number>p[pos].number))
        max=e;
    else 
        max=pos;
    
    if((d<=heapSize)&&(p[d].number>p[max].number))
        max=d;

    if(max!=pos){
        switchInt(p,pos,max);
        heapMaxPosInt(p,max,heapSize);
    }
}

void buildMaxHeapInt(Product p[], int end){
    int i;
    for(i=(end-1)/2;i>=0;i--)
        heapMaxPosInt(p,i,end);
}

void heapSortInt(Product p[], int end){
    int i, j, heapSize;
    heapSize=end;
    buildMaxHeapInt(p,end);

    for(i=end;i>=0;i--){
        switchInt(p,0,i);
        heapSize--;
        heapMaxPosInt(p,0,heapSize);
    }
}

void heapMaxPosString(Product p[], int pos, int heapSize){
    int e, d, max;
    e=left(pos);
    d=right(pos);

    if((e<=heapSize)&&(strcmp(p[e].string,p[pos].string)>0))
        max=e;
    else
        max=pos;

    if((d<=heapSize)&&(strcmp(p[d].string,p[max].string)>0))
        max=d;
    
    if(max!=pos){
        switchString(p,pos,max);
        heapMaxPosString(p,max,heapSize);
    }
}

void buildMaxHeapString(Product p[], int end){
    int i;
    for(i=(end-1)/2;i>=0;i--)
        heapMaxPosString(p,i,end);
}

void heapSortString(Product p[], int end){
    int i, j, heapSize;
    heapSize=end;

    buildMaxHeapString(p,end);
    for(i=end;i>=0;i--){
        switchString(p,0,i);
        heapSize--;
        heapMaxPosString(p,0,heapSize);
    }
}