#include <stdlib.h>
#include "Headers/bucketsort.h"
#include "Headers/insertionsort.h"
#define QTD 5   //Capacidade do balde

struct balde{
    int qtd;
    int valores[QTD];
};

void InsertionSortBucket(int p[], int tamanho){
    int i,j,aux;

    for(i=1;i<tamanho;i++){
        aux=p[i];
        j=i-1;

        while(j<=0&&p[j]>aux){
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=aux;
    }
}

void BucketSort(Produto p[], int tamanho){
    int i, j, maior, menor, num_baldes, pos;

    struct balde *bd;

    maior=p[0].numero;
    menor=p[0].numero;

    for(i=1;i<tamanho;i++){
        if(p[i].numero>maior)
            maior=p[i].numero;
        if(p[i].numero<menor)
            menor=p[i].numero;
    }

    num_baldes=(maior-menor)/QTD+1;
    bd=(struct balde *) malloc(num_baldes * sizeof(struct balde));

    for(i=0;i<num_baldes;i++)
        bd[i].qtd=0;

    for(i=0;i<tamanho;i++){
        pos=(p[i].numero-menor)/QTD;
        bd[pos].valores[bd[pos].qtd]=p[i].numero;
        bd[pos].qtd++;
    }

    pos=0;
    for(i=0;i<num_baldes;i++){
        InsertionSortBucket(bd[i].valores,bd[i].qtd);//criar um InsertionSortBucket
        for(j=0;j<bd[i].qtd;j++){
            p[pos].numero=bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}