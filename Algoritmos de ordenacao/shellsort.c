#include <stdlib.h>
#include <string.h>
#include "Headers/produto.h"

void ShellSortInt(Produto v[], int tamanho) {
    int i, j, k, h = 1;
    int aux;

    do{
        h = h * 3 + 1;
    } while (h < tamanho);

    do {
        h /= 3;
        for(i = h ; i < tamanho ; i++) {
            aux = v[i].numero;
            j = i;
            while (v[j - h].numero > aux) {
                v[j].numero = v[j - h].numero;
                j -= h;
                if (j < h) break;
            }
            v[j].numero = aux;
        }
    }while (h != 1);
}

void ShellSortString(Produto v[], int tamanho) {
    int i, j, k, h = 1;
    char aux[30];

    do{
        h = h * 3 + 1;
    } while (h < tamanho);

    do {
        h /= 3;
        for(i = h ; i < tamanho ; i++) {
            strcpy(aux,v[i].descricao);
            j = i;
            while (strcmp(v[j - h].descricao,aux)>0) {
                strcpy(v[j].descricao,v[j - h].descricao);
                j -= h;
                if (j < h) break;
            }
            strcpy(v[j].descricao,aux);
        }
    }while (h != 1);
}