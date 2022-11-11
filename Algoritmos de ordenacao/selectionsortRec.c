#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void SelectionSortRecInt(Produto p[], int ini, int tamanho){
    int min, j, menor;

    if(ini==tamanho)
        return;

    min=ini;
    for(j=ini+1;j<tamanho;j++)
        if(p[j].numero<p[min].numero)
            min=j;
    menor=p[min].numero;
    p[min].numero=p[ini].numero;
    p[ini].numero=menor;
    SelectionSortRecInt(p,ini+1,tamanho);
}

void SelectionSortRecString(Produto p[], int ini, int tamanho){
    int min, j;
    char menor[30];

    if(ini==tamanho)
        return;

    min=ini;
    for(j=ini+1;j<tamanho;j++)
        if(strcmp(p[j].descricao,p[min].descricao)<0)
            min=j;
    strcpy(menor, p[min].descricao);
    strcpy(p[min].descricao,p[ini].descricao);
    strcpy(p[ini].descricao,menor);
    SelectionSortRecString(p,ini+1,tamanho);
}