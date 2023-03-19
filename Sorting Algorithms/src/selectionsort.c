#include <stdlib.h>
#include <string.h>
#include "Headers/product.h"

void SelectionSortInt(Product p[], int size){
    int min, i, j, smallest;
    
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++)
            if(p[j].number<p[min].number)
                min=j;
        smallest=p[min].number;
        p[min].number=p[i].number;
        p[i].number=smallest;
    }
}

void SelectionSortString(Product p[], int size){
    int min, i, j;
    char smallest[30];

    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++)
            if(strcmp(p[j].string, p[min].string)<0)
                min=j;
        strcpy(smallest, p[min].string);
        strcpy(p[min].string,p[i].string);
        strcpy(p[i].string,smallest);
    }
}