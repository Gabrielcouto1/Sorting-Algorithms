#include <stdlib.h>
#include <string.h>
#include "Headers/cocktailsort.h"
#include "Headers/auxiliar_functions.h"

void CocktailSortInt(Product p[], int size){
    int sz, start, end, sw, i;
    sz=size;
    start=0;
    end=size-1;
    sw=0;

    while(sw==0&&start<end){
        sw=1;
        for(i=start;i<end;i++)
            if(p[i].number>p[i+1].number){
                switchInt(p,i,i+1);
                sw=0;    
            }
        end--;
        for(i=end;i>start;i--)
            if(p[i].number<p[i-1].number){
                switchInt(p,i,i-1);
                sw=0;
            }
        start++;
    }
}

void CocktailSortString(Product p[], int size){
    int sz, start, end, sw, i;
    sz=size;
    start=0;
    end=size-1;
    sw=0;

    while(sw==0&&start<end){
        sw=1;
        for(i=start;i<end;i++)
            if(strcmp(p[i].string,p[i+1].string)>0){
                switchString(p,i,i+1);
                sw=0;    
            }
        end--;
        for(i=end;i>start;i--)
            if(strcmp(p[i].string,p[i-1].string)<0){
                switchString(p,i,i-1);
                sw=0;
            }
        start++;
    }
}