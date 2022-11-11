#ifdef _WIN32
    #define clean "cls"
#elif __linux__
    #define clean "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(){
    
    double fim, ini, tempo, aux;
    int op, TAM, preenchimento;

    while(1){
        printf("\nEscolha o tamanho do vetor a ser criado e ordenado (ou digite -1 para sair): ");
        scanf("%d",&TAM);
        if(TAM==-1)
            break;
        if(TAM<=0)
            TAM=100;
        Produto p[TAM];
        system(clean);
        
        printf("\nComo deseja preencher o vetor de inteiros?");
        printf("\n[1]: Com elementos aleatorios;");
        printf("\n[2]: Com elementos em ordem crescente;");
        printf("\n[3]: Com elementos em ordem decrescente;");
        printf("\n[4]: Com poucas chaves unicas;");
        printf("\nInsira a opcao: ");
        scanf("%d", &preenchimento);
        if(preenchimento<1||preenchimento>4)
            preenchimento=1;
        system(clean);

        aux=1;
        printf("\nEscolha o metodo desejado: ");
        printf("\n[1]: BubbleSort;");
        printf("\n[2]: InsertionSort;");
        printf("\n[3]: SelectionSort;");
        printf("\n[4]: SelectionSort por recursividade;");
        printf("\n[5]: QuickSort;");
        printf("\n[6]: QuickSort com mediana de 3;");
        printf("\n[7]: ShellSort;");
        printf("\n[8]: MergeSort;");
        printf("\n[9]: CountingSort (serve apenas para numeros inteiros, logo apenas o tempo destes sera contado);");
        printf("\n[10]: BucketSort (serve apenas para numeros inteiros, logo apenas o tempo destes sera contado);");
        printf("\n[11]: CombSort;");
        printf("\n[12]: PancakeSort;");
        printf("\n[13]: HeapSort;");
        printf("\n[14]: CocktailSort;");
        printf("\n[15]: StoogeSort;");
        printf("\n[16]: BogoSort (NAO UTILIZE VETORES COM MAIS DE 10 ELEMENTOS);");
        printf("\n[99]: Sair do programa.");

        printf("\nInsira a opcao: ");
        scanf("%d",&op);
        if(op==99)
            break;
        preencheVetor(p,TAM,preenchimento);
        ini=clock();
        switch(op){
            case 1: 
                BubbleSortInt(p,TAM);
                BubbleSortString(p,TAM);
                break;

            case 2:
                InsertionSortInt(p,TAM);
                InsertionSortString(p,TAM);   
                break;

            case 3:
                SelectionSortInt(p,TAM);
                SelectionSortString(p,TAM);
                break;

            case 4:
                SelectionSortRecInt(p,0,TAM);
                SelectionSortRecString(p,0,TAM);
                break;

            case 5:
                QuickSortInt(p,0,TAM-1);
                QuickSortString(p,0,TAM-1);
                break;
            case 6:
                Quick3Int(p,0,TAM-1);
                Quick3String(p,0,TAM-1);

                break;

            case 7:
                ShellSortInt(p,TAM);
                ShellSortString(p,TAM);
                break;
            
            case 8:
                MergeSortInt(p, 0, TAM-1);
                MergeSortString(p, 0, TAM-1);
                break;

            case 9: 
                CountingSort(p,TAM);
                break;

            case 10:
                BucketSort(p,TAM);
                break;

            case 11:
                CombSortInt(p,TAM);
                CombSortString(p,TAM);
                break;
                
            case 12:
                PancakeSortInt(p,TAM);
                PancakeSortString(p,TAM);
                break;

            case 13:
                heapSortInt(p,TAM-1);
                heapSortString(p,TAM-1);
                break;

            case 14:
                CocktailSortInt(p,TAM);
                CocktailSortString(p,TAM);
                break;

            case 15:
                StoogeSortInt(p,0,TAM-1);
                StoogeSortString(p,0,TAM-1);
                break;

            case 16:
                BogoSortInt(p,TAM);
                BogoSortString(p,TAM);
                break;

            default:
                aux=0;
                printf("\nInsira opcoes validas.");
                break;
        }
        if(aux==0)
            getchar();

        else{
            fim=clock();
            tempo=(fim-ini)/CLOCKS_PER_SEC;
            imprimeVetor(p,TAM,tempo,op,preenchimento);
        }
        
        printf("\nPressione ENTER para continuar...\n");
        getchar();
        system(clean);
    }
    system(clean);
    return 1;
}