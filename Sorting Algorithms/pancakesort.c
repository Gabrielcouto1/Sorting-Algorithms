#include <stdlib.h>
#include <string.h>
#include "Headers/pancakesort.h"
#include "Headers/auxiliar_functions.h"

void flipInt(Product p[], int i){
    int start=0;

    while(start<i){
        switchInt(p,start, i);
        start++;
        i--;
    }
}

int findMaxInt(Product p[], int t){
    int mi, i;
    
    for(mi=0,i=0;i<t;i++)
        if(p[i].number>p[mi].number)
            mi=i;
    
    return mi;
}

void PancakeSortInt(Product p[], int size){
    int current_size;

    for(current_size=size;current_size>1;current_size--){
        int mi=findMaxInt(p,current_size);
        if(mi!=current_size-1){
            flipInt(p, mi);
            flipInt(p,current_size-1);
        }
    }
}

void flipString(Product p[], int i){
    int start=0;

    while(start<i){
        switchString(p, start, i);
        start++;
        i--;
    }
}

int findMaxString(Product p[], int t){
    int mi, i;

    for(mi=0,i=0;i<t;i++)
        if(strcmp(p[i].string,p[mi].string)>0)
            mi=i;

    return mi;
}

void PancakeSortString(Product p[], int size){
    int current_size;

    for(current_size=size;current_size>1;current_size--){
        int mi=findMaxString(p,current_size);
        if(mi!=current_size){
            flipString(p,mi);
            flipString(p,current_size-1);
        }
    }
}