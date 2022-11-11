#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void SelectionSortInt(Produto p[], int tamanho){
    int min, i, j, menor;
    
    for(i=0;i<tamanho-1;i++){
        min=i;
        for(j=i+1;j<tamanho;j++)
            if(p[j].numero<p[min].numero)
                min=j;
        menor=p[min].numero;
        p[min].numero=p[i].numero;
        p[i].numero=menor;
    }
}

void SelectionSortString(Produto p[], int tamanho){
    int min, i, j;
    char menor[30];

    for(i=0;i<tamanho-1;i++){
        min=i;
        for(j=i+1;j<tamanho;j++)
            if(strcmp(p[j].descricao, p[min].descricao)<0)
                min=j;
        strcpy(menor, p[min].descricao);
        strcpy(p[min].descricao,p[i].descricao);
        strcpy(p[i].descricao,menor);
    }
}