#include <stdlib.h>
#include <string.h>
#include "Headers/pancakesort.h"
#include "Headers/troca.h"

void flipInt(Produto p[], int i){
    int start=0;

    while(start<i){
        trocaInt(p,start, i);
        start++;
        i--;
    }
}

int achaMaxInt(Produto p[], int t){
    int mi, i;
    
    for(mi=0,i=0;i<t;i++)
        if(p[i].numero>p[mi].numero)
            mi=i;
    
    return mi;
}

void PancakeSortInt(Produto p[], int tamanho){
    int tamanho_atual;

    for(tamanho_atual=tamanho;tamanho_atual>1;tamanho_atual--){
        int mi=achaMaxInt(p,tamanho_atual);
        if(mi!=tamanho_atual-1){
            flipInt(p, mi);
            flipInt(p,tamanho_atual-1);
        }
    }
}

void flipString(Produto p[], int i){
    int start=0;

    while(start<i){
        trocaString(p, start, i);
        start++;
        i--;
    }
}

int achaMaxString(Produto p[], int t){
    int mi, i;

    for(mi=0,i=0;i<t;i++)
        if(strcmp(p[i].descricao,p[mi].descricao)>0)
            mi=i;

    return mi;
}

void PancakeSortString(Produto p[], int tamanho){
    int tamanho_atual;

    for(tamanho_atual=tamanho;tamanho_atual>1;tamanho_atual--){
        int mi=achaMaxString(p,tamanho_atual);
        if(mi!=tamanho_atual){
            flipString(p,mi);
            flipString(p,tamanho_atual-1);
        }
    }
}