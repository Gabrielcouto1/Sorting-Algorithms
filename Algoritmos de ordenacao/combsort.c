#include <stdlib.h>
#include <string.h>
#include "Headers/combsort.h"
#include "Headers/troca.h"

void CombSortInt(Produto p[], int tamanho){
    int i, j, intervalo, aux, trocado;
    trocado=1;
    intervalo=tamanho;

    while(intervalo>1||trocado==1){
        intervalo=intervalo*10/13;

        if(intervalo==9||intervalo==10)
            intervalo = 11;

        if(intervalo<1)
            intervalo = 1;
        trocado = 0;

        for(i=0,j=intervalo;j<tamanho;i++,j++){
            if(p[i].numero>p[j].numero){
                aux=p[i].numero;
                p[i].numero=p[j].numero;
                p[j].numero=aux;
                trocado=1;
            }
        }
    }
}

void CombSortString(Produto p[], int tamanho){
    int i, j, intervalo, trocado;
    char aux[30];
    trocado=1;
    intervalo=tamanho;

    while(intervalo>1||trocado==1){
        intervalo=intervalo*10/13;
        if(intervalo==9||intervalo==10)
            intervalo=11;
        
        if(intervalo<1)
            intervalo=1;
        trocado=0;

        for(i=0,j=intervalo;j<tamanho;i++,j++){
            if(strcmp(p[i].descricao,p[j].descricao)>0){
                strcpy(aux,p[i].descricao);
                strcpy(p[i].descricao,p[j].descricao);
                strcpy(p[j].descricao,aux);
                trocado=1;
            }
        }
    }
}