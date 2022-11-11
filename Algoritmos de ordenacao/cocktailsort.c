#include <stdlib.h>
#include <string.h>
#include "Headers/cocktailsort.h"
#include "Headers/troca.h"

void CocktailSortInt(Produto p[], int tamanho){
    int tam, ini, fim, troca, i;
    tam=tamanho;
    ini=0;
    fim=tamanho-1;
    troca=0;

    while(troca==0&&ini<fim){
        troca=1;
        for(i=ini;i<fim;i++)
            if(p[i].numero>p[i+1].numero){
                trocaInt(p,i,i+1);
                troca=0;    
            }
        fim--;
        for(i=fim;i>ini;i--)
            if(p[i].numero<p[i-1].numero){
                trocaInt(p,i,i-1);
                troca=0;
            }
        ini++;
    }
}

void CocktailSortString(Produto p[], int tamanho){
    int tam, ini, fim, troca, i;
    tam=tamanho;
    ini=0;
    fim=tamanho-1;
    troca=0;

    while(troca==0&&ini<fim){
        troca=1;
        for(i=ini;i<fim;i++)
            if(strcmp(p[i].descricao,p[i+1].descricao)>0){
                trocaString(p,i,i+1);
                troca=0;    
            }
        fim--;
        for(i=fim;i>ini;i--)
            if(strcmp(p[i].descricao,p[i-1].descricao)<0){
                trocaString(p,i,i-1);
                troca=0;
            }
        ini++;
    }
}