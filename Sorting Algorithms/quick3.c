#include <stdlib.h>
#include <string.h>
#include "Headers/quick3.h"
#include "Headers/auxiliar_functions.h"

int partitionInt3(Product p[], int left, int right){
    int i, end=left;
    for(i=left+1;i<=right;i++)
        if(p[i].number<p[left].number){
            end++;
            switchInt(p,end,i);
        }
    switchInt(p,left,end);
    return end;
}

void Quick3Int(Product p[], int left, int right){
    int i;
    if(right<=left)
        return;

    switchInt(p, (left+right)/2, left+1);

    if(p[left].number>p[left+1].number)
        switchInt(p,left,left+1);

    if(p[left].number>p[right].number)
        switchInt(p,left,right);
    
    if(p[left+1].number>p[right].number)
        switchInt(p, left+1, right);

    i=partitionInt3(p,left+1, right-1);
    Quick3Int(p,left,i-1);
    Quick3Int(p,i+1,right);
}

int partitionString3(Product p[], int left, int right){
    int i, end=left;

    for(i=left+1;i<=right;i++)
        if(strcmp(p[i].string,p[left].string)<0){
            end++; 
            switchString(p, end, i);
        }
        switchString(p, left, end);
        return end;
}

void Quick3String(Product p[], int left, int right){
    int i;
    if(right<=left)
        return;

    switchString(p,(left+right)/2,left+1);

    if(strcmp(p[left].string,p[left+1].string)>0)
        switchString(p, left, left+1);
    
    if(strcmp(p[left].string, p[right].string)>0)
        switchString(p, left, right);

    if(strcmp(p[left+1].string, p[right].string)>0)
        switchString(p, left+1, right);

    i=partitionString3(p, left+1, right-1);
    Quick3String(p,left,i-1);
    Quick3String(p,i+1,right);
}