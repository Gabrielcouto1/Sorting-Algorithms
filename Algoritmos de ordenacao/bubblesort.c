#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void BubbleSortInt(Produto p[],int tamanho){
    int i, j, aux;

    for(i=tamanho;i>0;i--)
        for(j=0;j<i-1;j++)
            if(p[j].numero>p[j+1].numero){
                aux=p[j].numero;
                p[j].numero=p[j+1].numero;
                p[j+1].numero=aux;
            }
}

void BubbleSortString(Produto p[], int tamanho){
    int i, j;
    char aux[30];

    for(i=tamanho;i>0;i--)
        for(j=0;j<i-1;j++)
            if(strcmp(p[j].descricao,p[j+1].descricao)>0){
                strcpy(aux,p[j].descricao);
                strcpy(p[j].descricao,p[j+1].descricao);
                strcpy(p[j+1].descricao,aux);
            }
}