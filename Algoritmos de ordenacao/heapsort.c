#include <stdlib.h>
#include <string.h>
#include "Headers/heapsort.h"
#include "Headers/troca.h"

int esq(int pos){
    return (pos*2)+1;
}

int dir(int pos){
    return (pos*2)+2;
}

void heapMaxPosInt(Produto p[], int pos, int tamHeap){
    int e, d, maior;
    e=esq(pos);
    d=dir(pos);

    if((e<=tamHeap)&&(p[e].numero>p[pos].numero))
        maior=e;
    else 
        maior=pos;
    
    if((d<=tamHeap)&&(p[d].numero>p[maior].numero))
        maior=d;

    if(maior!=pos){
        trocaInt(p,pos,maior);
        heapMaxPosInt(p,maior,tamHeap);
    }
}

void construirMaxHeapInt(Produto p[], int fim){
    int i;
    for(i=(fim-1)/2;i>=0;i--)
        heapMaxPosInt(p,i,fim);
}

void heapSortInt(Produto p[], int fim){
    int i, j, tamHeap;
    tamHeap=fim;
    construirMaxHeapInt(p,fim);

    for(i=fim;i>=0;i--){
        trocaInt(p,0,i);
        tamHeap--;
        heapMaxPosInt(p,0,tamHeap);
    }
}

void heapMaxPosString(Produto p[], int pos, int tamHeap){
    int e, d, maior;
    e=esq(pos);
    d=dir(pos);

    if((e<=tamHeap)&&(strcmp(p[e].descricao,p[pos].descricao)>0))
        maior=e;
    else
        maior=pos;

    if((d<=tamHeap)&&(strcmp(p[d].descricao,p[maior].descricao)>0))
        maior=d;
    
    if(maior!=pos){
        trocaString(p,pos,maior);
        heapMaxPosString(p,maior,tamHeap);
    }
}

void construirMaxHeapString(Produto p[], int fim){
    int i;
    for(i=(fim-1)/2;i>=0;i--)
        heapMaxPosString(p,i,fim);
}

void heapSortString(Produto p[], int fim){
    int i, j, tamHeap;
    tamHeap=fim;

    construirMaxHeapString(p,fim);
    for(i=fim;i>=0;i--){
        trocaString(p,0,i);
        tamHeap--;
        heapMaxPosString(p,0,tamHeap);
    }
}