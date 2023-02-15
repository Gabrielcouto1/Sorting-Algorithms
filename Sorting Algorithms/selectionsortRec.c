#include <stdlib.h>
#include <string.h>
#include "Headers/product.h"

void SelectionSortRecInt(Product p[], int start, int size){
    int min, j, smallest;

    if(start==size)
        return;

    min=start;
    for(j=start+1;j<size;j++)
        if(p[j].number<p[min].number)
            min=j;
    smallest=p[min].number;
    p[min].number=p[start].number;
    p[start].number=smallest;
    SelectionSortRecInt(p,start+1,size);
}

void SelectionSortRecString(Product p[], int start, int size){
    int min, j;
    char smallest[30];

    if(start==size)
        return;

    min=start;
    for(j=start+1;j<size;j++)
        if(strcmp(p[j].string,p[min].string)<0)
            min=j;
    strcpy(smallest, p[min].string);
    strcpy(p[min].string,p[start].string);
    strcpy(p[start].string,smallest);
    SelectionSortRecString(p,start+1,size);
}