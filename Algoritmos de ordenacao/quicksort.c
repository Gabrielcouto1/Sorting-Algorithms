#include <stdlib.h>
#include <string.h>
#include "Headers/quicksort.h"
#include "Headers/troca.h"

int particaoInt(Produto p[], int esq, int dir){
    int i, fim=esq;

    for(i=esq+1;i<=dir;i++)
        if(p[i].numero<p[esq].numero){
            fim++;
            trocaInt(p,fim,i);
        }    
    trocaInt(p,esq,fim);
    return fim;
}

void QuickSortInt(Produto p[], int esq, int dir){
    int i;
    if(esq>=dir)
        return;

    i=particaoInt(p,esq,dir);
    QuickSortInt(p,esq,i-1);
    QuickSortInt(p,i+1,dir);
}

int particaoString(Produto p[], int esq, int dir){
    int i, fim=esq;

    for(i=esq+1;i<=dir;i++)
        if(strcmp(p[i].descricao, p[esq].descricao)<0){
            fim++;
            trocaString(p,fim,i);
        }
    trocaString(p,esq,fim);
    return fim;
}

void QuickSortString(Produto p[], int esq, int dir){
    int i;
    if(esq>=dir)
        return;
    
    i=particaoString(p,esq,dir);
    QuickSortString(p,esq,i-1);
    QuickSortString(p,i+1,dir);
}