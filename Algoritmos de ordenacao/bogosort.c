#include <stdlib.h>
#include <string.h>
#include "Headers/bogosort.h"
#include "Headers/troca.h"

int isSortedInt(Produto p[], int tamanho){
    while(--tamanho>=1){
        if(p[tamanho].numero<p[tamanho-1].numero)
            return 0;
    }
    return 1;
}

void shuffleInt(Produto p[], int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        trocaInt(p,i,rand()%tamanho);
}

void BogoSortInt(Produto p[], int tamanho){
    while(!isSortedInt(p,tamanho))
        shuffleInt(p,tamanho);
}

int isSortedString(Produto p[], int tamanho){
    while(--tamanho>=1){
        if(strcmp(p[tamanho].descricao,p[tamanho-1].descricao)<0)
            return 0;
    }
    return 1;
}

void shuffleString(Produto p[], int tamanho){
    int i;
    
    for(i=0;i<tamanho;i++)
        trocaString(p,i,rand()%tamanho);
}

void BogoSortString(Produto p[], int tamanho){
    while(!isSortedString(p,tamanho))
        shuffleString(p,tamanho);
}