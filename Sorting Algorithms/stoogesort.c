#include <stdlib.h>
#include <string.h>
#include "Headers/stoogesort.h"
#include "Headers/auxiliar_functions.h"

void StoogeSortInt(Product p[], int i, int j){
    int t;

    if(p[j].number<p[i].number)
        switchInt(p,i,j);

    if(j-i>1){
        t=(j-i+1)/3;
        StoogeSortInt(p,i,j-t);
        StoogeSortInt(p,i+t,j);
        StoogeSortInt(p,i,j-t);
    }
}

void StoogeSortString(Product p[], int i, int j){
    int t;

    if(strcmp(p[j].string,p[i].string)<0)
        switchString(p,i,j);

    if(j-i>1){
        t=(j-i+1)/3;
        StoogeSortString(p,i,j-t);
        StoogeSortString(p,i+t,j);
        StoogeSortString(p,i,j-t);
    }
}