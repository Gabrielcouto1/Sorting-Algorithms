#include <stdlib.h>
#include <string.h>
#include "Headers/product.h"

void ShellSortInt(Product v[], int size) {
    int i, j, k, h = 1;
    int aux;

    do{
        h = h * 3 + 1;
    } while (h < size);

    do {
        h /= 3;
        for(i = h ; i < size ; i++) {
            aux = v[i].number;
            j = i;
            while (v[j - h].number > aux) {
                v[j].number = v[j - h].number;
                j -= h;
                if (j < h) break;
            }
            v[j].number = aux;
        }
    }while (h != 1);
}

void ShellSortString(Product v[], int size) {
    int i, j, k, h = 1;
    char aux[30];

    do{
        h = h * 3 + 1;
    } while (h < size);

    do {
        h /= 3;
        for(i = h ; i < size ; i++) {
            strcpy(aux,v[i].string);
            j = i;
            while (strcmp(v[j - h].string,aux)>0) {
                strcpy(v[j].string,v[j - h].string);
                j -= h;
                if (j < h) break;
            }
            strcpy(v[j].string,aux);
        }
    }while (h != 1);
}