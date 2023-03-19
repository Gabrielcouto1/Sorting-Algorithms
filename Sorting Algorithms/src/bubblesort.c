#include <stdlib.h>
#include <string.h>
#include "Headers/product.h"

void BubbleSortInt(Product p[],int size){
    int i, j, aux;

    for(i=size;i>0;i--)
        for(j=0;j<i-1;j++)
            if(p[j].number>p[j+1].number){
                aux=p[j].number;
                p[j].number=p[j+1].number;
                p[j+1].number=aux;
            }
}

void BubbleSortString(Product p[], int size){
    int i, j;
    char aux[30];

    for(i=size;i>0;i--)
        for(j=0;j<i-1;j++)
            if(strcmp(p[j].string,p[j+1].string)>0){
                strcpy(aux,p[j].string);
                strcpy(p[j].string,p[j+1].string);
                strcpy(p[j+1].string,aux);
            }
}