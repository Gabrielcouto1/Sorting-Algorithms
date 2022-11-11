#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void trocaInt(Produto p[], int i, int j){
    int aux;
    aux=p[i].numero;
    p[i].numero=p[j].numero;
    p[j].numero=aux;
}

void trocaString(Produto p[], int i, int j){
    char aux[30];
    strcpy(aux, p[i].descricao);
    strcpy(p[i].descricao, p[j].descricao);
    strcpy(p[j].descricao, aux);
}