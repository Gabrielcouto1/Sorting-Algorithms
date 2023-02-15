#include <stdlib.h>
#include <string.h>
#include "Headers/quicksort.h"
#include "Headers/auxiliar_functions.h"

int partitionInt(Product p[], int left, int right){
    int i, end=left;

    for(i=left+1;i<=right;i++)
        if(p[i].number<p[left].number){
            end++;
            switchInt(p,end,i);
        }    
    switchInt(p,left,end);
    return end;
}

void QuickSortInt(Product p[], int left, int right){
    int i;
    if(left>=right)
        return;

    i=partitionInt(p,left,right);
    QuickSortInt(p,left,i-1);
    QuickSortInt(p,i+1,right);
}

int partitionString(Product p[], int left, int right){
    int i, end=left;

    for(i=left+1;i<=right;i++)
        if(strcmp(p[i].string, p[left].string)<0){
            end++;
            switchString(p,end,i);
        }
    switchString(p,left,end);
    return end;
}

void QuickSortString(Product p[], int left, int right){
    int i;
    if(left>=right)
        return;
    
    i=partitionString(p,left,right);
    QuickSortString(p,left,i-1);
    QuickSortString(p,i+1,right);
}