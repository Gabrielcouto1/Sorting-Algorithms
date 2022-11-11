#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void InsertionSortInt(Produto p[], int tamanho){
    int i, j, aux;

    for(i=1;i<tamanho;i++){
        aux=p[i].numero;
        j=i-1;
        
        while(j>=0&&p[j].numero>aux){
            p[j+1].numero=p[j].numero;
            j=j-1;
        }
        p[j+1].numero=aux;
    }
}

void InsertionSortString(Produto p[], int tamanho){
    int i, j;
    char aux[30];

    for(i=1;i<tamanho;i++){
        strcpy(aux, p[i].descricao);
        j=i-1;
        
        while((j>=0)&&(strcmp(p[j].descricao,aux)>0)){
            strcpy(p[j+1].descricao,p[j].descricao);
            j=j-1;
        }
        strcpy(p[j+1].descricao,aux);
    }
}