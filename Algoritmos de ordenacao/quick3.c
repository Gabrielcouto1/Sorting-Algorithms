#include <stdlib.h>
#include <string.h>
#include "Headers/quick3.h"
#include "Headers/troca.h"

int particaoInt3(Produto p[], int esq, int dir){
    int i, fim=esq;
    for(i=esq+1;i<=dir;i++)
        if(p[i].numero<p[esq].numero){
            fim++;
            trocaInt(p,fim,i);
        }
    trocaInt(p,esq,fim);
    return fim;
}

void Quick3Int(Produto p[], int esq, int dir){
    int i;
    if(dir<=esq)
        return;

    trocaInt(p, (esq+dir)/2, esq+1);

    if(p[esq].numero>p[esq+1].numero)
        trocaInt(p,esq,esq+1);

    if(p[esq].numero>p[dir].numero)
        trocaInt(p,esq,dir);
    
    if(p[esq+1].numero>p[dir].numero)
        trocaInt(p, esq+1, dir);

    i=particaoInt3(p,esq+1, dir-1);
    Quick3Int(p,esq,i-1);
    Quick3Int(p,i+1,dir);
}

int particaoString3(Produto p[], int esq, int dir){
    int i, fim=esq;

    for(i=esq+1;i<=dir;i++)
        if(strcmp(p[i].descricao,p[esq].descricao)<0){
            fim++; 
            trocaString(p, fim, i);
        }
        trocaString(p, esq, fim);
        return fim;
}

void Quick3String(Produto p[], int esq, int dir){
    int i;
    if(dir<=esq)
        return;

    trocaString(p,(esq+dir)/2,esq+1);

    if(strcmp(p[esq].descricao,p[esq+1].descricao)>0)
        trocaString(p, esq, esq+1);
    
    if(strcmp(p[esq].descricao, p[dir].descricao)>0)
        trocaString(p, esq, dir);

    if(strcmp(p[esq+1].descricao, p[dir].descricao)>0)
        trocaString(p, esq+1, dir);

    i=particaoString3(p, esq+1, dir-1);
    Quick3String(p,esq,i-1);
    Quick3String(p,i+1,dir);
}