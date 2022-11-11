#include <stdlib.h>
#include <string.h>
#include "Headers/stoogesort.h"
#include "Headers/troca.h"

void StoogeSortInt(Produto p[], int i, int j){
    int t;

    if(p[j].numero<p[i].numero)
        trocaInt(p,i,j);

    if(j-i>1){
        t=(j-i+1)/3;
        StoogeSortInt(p,i,j-t);
        StoogeSortInt(p,i+t,j);
        StoogeSortInt(p,i,j-t);
    }
}

void StoogeSortString(Produto p[], int i, int j){
    int t;

    if(strcmp(p[j].descricao,p[i].descricao)<0)
        trocaString(p,i,j);

    if(j-i>1){
        t=(j-i+1)/3;
        StoogeSortString(p,i,j-t);
        StoogeSortString(p,i+t,j);
        StoogeSortString(p,i,j-t);
    }
}