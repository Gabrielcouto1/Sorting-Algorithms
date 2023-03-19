#include <stdlib.h>
#include <string.h>
#include "Headers/combsort.h"
#include "Headers/auxiliar_functions.h"

void CombSortInt(Product p[], int sz){
    int i, j, interval, aux, sw;
    sw=1;
    interval=sz;

    while(interval>1||sw==1){
        interval=interval*10/13;

        if(interval==9||interval==10)
            interval = 11;

        if(interval<1)
            interval = 1;
        sw = 0;

        for(i=0,j=interval;j<sz;i++,j++){
            if(p[i].number>p[j].number){
                aux=p[i].number;
                p[i].number=p[j].number;
                p[j].number=aux;
                sw=1;
            }
        }
    }
}

void CombSortString(Product p[], int sz){
    int i, j, interval, sw;
    char aux[30];
    sw=1;
    interval=sz;

    while(interval>1||sw==1){
        interval=interval*10/13;
        if(interval==9||interval==10)
            interval=11;
        
        if(interval<1)
            interval=1;
        sw=0;

        for(i=0,j=interval;j<sz;i++,j++){
            if(strcmp(p[i].string,p[j].string)>0){
                strcpy(aux,p[i].string);
                strcpy(p[i].string,p[j].string);
                strcpy(p[j].string,aux);
                sw=1;
            }
        }
    }
}