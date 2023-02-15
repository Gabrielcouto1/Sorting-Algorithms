#include <stdlib.h>
#include <string.h>
#include "Headers/bogosort.h"
#include "Headers/auxiliar_functions.h"

int isSortedInt(Product p[], int size){
    while(--size>=1){
        if(p[size].number<p[size-1].number)
            return 0;
    }
    return 1;
}

void shuffleInt(Product p[], int size){
    int i;
    for(i=0;i<size;i++)
        switchInt(p,i,rand()%size);
}

void BogoSortInt(Product p[], int size){
    while(!isSortedInt(p,size))
        shuffleInt(p,size);
}

int isSortedString(Product p[], int size){
    while(--size>=1){
        if(strcmp(p[size].string,p[size-1].string)<0)
            return 0;
    }
    return 1;
}

void shuffleString(Product p[], int size){
    int i;
    
    for(i=0;i<size;i++)
        switchString(p,i,rand()%size);
}

void BogoSortString(Product p[], int size){
    while(!isSortedString(p,size))
        shuffleString(p,size);
}