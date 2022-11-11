#include <stdlib.h>
#include <string.h>
#include "Headers/mergesort.h"

void intercalaInt(Produto p[], int e, int m, int d){
    int i=e;
    int j=m+1;
    int k=0;
    Produto *r=malloc (((d+1)-e)*sizeof(Produto));

    while(i<=m && j<=d){
        if(p[i].numero<=p[j].numero){
            r[k].numero=p[i].numero;
            i++;
        }
        else{
            r[k].numero=p[j].numero;
            j++;
        }
        k++;
    }

    while(i<=m){
        r[k].numero=p[i].numero;
        i++;
        k++;
    }

    while(j<=d){
        r[k].numero=p[j].numero;
        j++;
        k++;
    }

    for(i=e,j=0;i<=d;i++,j++)
        p[i].numero=r[j].numero;
    
    free(r);
}

void MergeSortInt(Produto p[], int e, int d){
    int m;
    if(e<d){
        m=(e+d)/2;
        MergeSortInt(p, e, m);
        MergeSortInt(p, m+1, d);
        intercalaInt(p, e, m, d);
    }
}

void intercalaString(Produto p[], int e, int m, int d){
    int i=e;
    int j=m+1;
    int k=0;
    Produto *r=malloc(((d+1)-e)*sizeof(Produto));

    while(i<=m && j<=d){
        if(strcmp(p[i].descricao,p[j].descricao)<=0){
            strcpy(r[k].descricao,p[i].descricao);
            i++;
        }
        else{
            strcpy(r[k].descricao,p[j].descricao);
            j++;
        }
        k++;
    }

    while(i<=m){
        strcpy(r[k].descricao,p[i].descricao);
        i++;
        k++;
    }

    while(j<=d){
        strcpy(r[k].descricao,p[j].descricao);
        j++;
        k++;
    }

    for(i=e,j=0;i<=d;i++,j++)
        strcpy(p[i].descricao,r[j].descricao);

    free(r);
}

void MergeSortString(Produto p[], int e, int d){
    int m;

    if(e<d){
        m=(e+d)/2;
        MergeSortString(p, e, m);
        MergeSortString(p, m+1, d);
        intercalaString(p, e, m, d);
    }
}