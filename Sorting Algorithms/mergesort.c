#include <stdlib.h>
#include <string.h>
#include "Headers/mergesort.h"

void mergeInt(Product p[], int r, int m, int l){
    int i=r;
    int j=m+1;
    int k=0;
    Product *pr=malloc (((l+1)-r)*sizeof(Product));

    while(i<=m && j<=l){
        if(p[i].number<=p[j].number){
            pr[k].number=p[i].number;
            i++;
        }
        else{
            pr[k].number=p[j].number;
            j++;
        }
        k++;
    }

    while(i<=m){
        pr[k].number=p[i].number;
        i++;
        k++;
    }

    while(j<=l){
        pr[k].number=p[j].number;
        j++;
        k++;
    }

    for(i=r,j=0;i<=l;i++,j++)
        p[i].number=pr[j].number;
    
    free(pr);
}

void MergeSortInt(Product p[], int r, int l){
    int m;
    if(r<l){
        m=(r+l)/2;
        MergeSortInt(p, r, m);
        MergeSortInt(p, m+1, l);
        mergeInt(p, r, m, l);
    }
}

void mergeString(Product p[], int r, int m, int l){
    int i=r;
    int j=m+1;
    int k=0;
    Product *pr=malloc(((l+1)-r)*sizeof(Product));

    while(i<=m && j<=l){
        if(strcmp(p[i].string,p[j].string)<=0){
            strcpy(pr[k].string,p[i].string);
            i++;
        }
        else{
            strcpy(pr[k].string,p[j].string);
            j++;
        }
        k++;
    }

    while(i<=m){
        strcpy(pr[k].string,p[i].string);
        i++;
        k++;
    }

    while(j<=l){
        strcpy(pr[k].string,p[j].string);
        j++;
        k++;
    }

    for(i=r,j=0;i<=l;i++,j++)
        strcpy(p[i].string,pr[j].string);

    free(pr);
}

void MergeSortString(Product p[], int r, int l){
    int m;

    if(r<l){
        m=(r+l)/2;
        MergeSortString(p, r, m);
        MergeSortString(p, m+1, l);
        mergeString(p, r, m, l);
    }
}