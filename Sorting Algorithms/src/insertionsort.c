#include <stdlib.h>
#include <string.h>
#include "Headers/product.h"

void InsertionSortInt(Product p[], int size){
    int i, j, aux;

    for(i=1;i<size;i++){
        aux=p[i].number;
        j=i-1;
        
        while(j>=0&&p[j].number>aux){
            p[j+1].number=p[j].number;
            j=j-1;
        }
        p[j+1].number=aux;
    }
}

void InsertionSortString(Product p[], int size){
    int i, j;
    char aux[30];

    for(i=1;i<size;i++){
        strcpy(aux, p[i].string);
        j=i-1;
        
        while((j>=0)&&(strcmp(p[j].string,aux)>0)){
            strcpy(p[j+1].string,p[j].string);
            j=j-1;
        }
        strcpy(p[j+1].string,aux);
    }
}