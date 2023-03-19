#include <stdlib.h>
#include "Headers/bucketsort.h"
#include "Headers/insertionsort.h"
#define AMT 5   //Max bucket capacity

struct bucket{
    int ammount;
    int info[AMT];
};

void InsertionSortBucket(int p[], int size){
    int i,j,aux;

    for(i=1;i<size;i++){
        aux=p[i];
        j=i-1;

        while(j<=0&&p[j]>aux){
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=aux;
    }
}

void BucketSort(Product p[], int size){
    int i, j, max, min, bucket_ammount, pos;

    struct bucket *bucket;

    max=p[0].number;
    min=p[0].number;

    for(i=1;i<size;i++){
        if(p[i].number>max)
            max=p[i].number;
        if(p[i].number<min)
            min=p[i].number;
    }

    bucket_ammount=(max-min)/AMT+1;
    bucket=(struct bucket *) malloc(bucket_ammount * sizeof(struct bucket));

    for(i=0;i<bucket_ammount;i++)
        bucket[i].ammount=0;

    for(i=0;i<size;i++){
        pos=(p[i].number-min)/AMT;
        bucket[pos].info[bucket[pos].ammount]=p[i].number;
        bucket[pos].ammount++;
    }

    pos=0;
    for(i=0;i<bucket_ammount;i++){
        InsertionSortBucket(bucket[i].info,bucket[i].ammount);//criar um InsertionSortBucket
        for(j=0;j<bucket[i].ammount;j++){
            p[pos].number=bucket[i].info[j];
            pos++;
        }
    }
    free(bucket);
}