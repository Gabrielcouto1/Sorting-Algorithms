#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers/produto.h"
#include "Headers/preenche_imprime.h"

void preencheVetor(Produto p[] , int tamanho, int tipo){
    int i, j, tam_prod, pos_char;
    char caracteres[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));

    for(j=0;j<tamanho;j++){
        tam_prod=(rand()%25)+5;

        for(i=0;i<tam_prod;i++){
            pos_char=rand()%62;
            p[j].descricao[i]=caracteres[pos_char];
        }
        p[j].descricao[i]='\0';
    }

    switch(tipo){
        case 1:
            for(i=0;i<tamanho;i++)
                p[i].numero=rand()%1001;
            break;

        case 2:
            for(i=0;i<tamanho;i++)
                p[i].numero=i+1000;
            break;

        case 3:
            for(i=tamanho,j=0;i>0;i--,j++)
                p[j].numero=i+1000;
            break;
        
        case 4:
            for(i=0; i<tamanho; i++)
                p[i].numero=(rand()%3)+1000;
            break;
    }
}

void imprimeVetor(Produto p[], int tamanho, double tempo, int tipo, int preenchimento){
    int j;
    FILE *fp;

    fp = fopen("vetor_ordenado.txt", "w+");
    fprintf(fp, "Tempo gasto para ordenar o vetor ");
    switch(preenchimento){
        case 1:
            fprintf(fp,"preenchido de maneira aleatoria,");
            break;
        case 2:
            fprintf(fp,"preenchido em ordem crescente,");
            break;
        case 3:
            fprintf(fp,"preenchido em ordem decrescente,");
            break;
        case 4:
            fprintf(fp,"preenchido com poucas chaves unicas,");
            break;
    }
    fprintf(fp," de tamanho %d, utilizando o metodo ", tamanho);
    fprintf(fp, "%s: %.5f\n",tipoAlgoritmo(tipo),tempo);
    
    for(j=0;j<tamanho;j++)
        fprintf( fp, "\n> %d %s",p[j].numero, p[j].descricao);
    printf("\nO vetor ordenado foi escrito no arquivo \"vetor_ordenado.txt\"\n");
    fclose(fp);

    printf("Deseja imprimir o vetor ordenado na tela? [0/1]: ");
    scanf("%d",&j);
    getchar();
    if(j==1)
        imprimeVetorTela(p,tamanho,tempo,tipo,preenchimento);
}

void imprimeVetorTela(Produto p[],int tamanho, double tempo, int tipo, int preenchimento){
    int i;

    if(tipo==9||tipo==10)
        for(i=0;i<tamanho-1;i++)
            printf("\n> %d",p[i].numero);
    else
        for(i=0;i<tamanho;i++)
            printf("\n> %d %s",p[i].numero, p[i].descricao);

    printf("\n\nTempo gasto para ordenar o vetor ");
    switch(preenchimento){
        case 1:
            printf("preenchido de maneira aleatoria,");
            break;
        case 2:
            printf("preenchido em ordem crescente,");
            break;
        case 3:
            printf("preenchido em ordem decrescente,");
            break;
        case 4:
            printf("preenchido com poucas chaves unicas,");
            break;
    }
    
    printf(" de tamanho %d, utilizando o metodo ", tamanho);
    printf("%s: %.5f\n",tipoAlgoritmo(tipo),tempo);
}

char* tipoAlgoritmo(int tipo){
    switch(tipo){
        case 1:
            return "BubbleSort";
        case 2:
            return "InsertionSort";
        case 3:
            return "SelectionSort";
        case 4:
            return "SelectionSort pro recursividade";
        case 5:
            return "QuickSort";
        case 6:
            return "QuickSort com mediana de 3";
        case 7:
            return "ShellSort";
        case 8:
            return "MergeSort";
        case 9:
            return "CountingSort";
        case 10:
            return "BucketSort";
        case 11:
            return "CombSort";
        case 12:
            return "PancakeSort";
        case 13:
            return "HeapSort";
        case 14:
            return "CocktailSort";
        case 15:
            return "StoogeSort";
        case 16:
            return "BogoSort";
        default:
            break;
    }
    return "\0";
}