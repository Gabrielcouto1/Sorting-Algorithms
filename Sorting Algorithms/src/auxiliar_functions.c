#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int sortArray(Product p[], int size, int type){
    int aux;
    switch(type){
            case 1: 
                BubbleSortInt(p,size);
                BubbleSortString(p,size);
                break;

            case 2:
                InsertionSortInt(p,size);
                InsertionSortString(p,size);   
                break;

            case 3:
                SelectionSortInt(p,size);
                SelectionSortString(p,size);
                break;

            case 4:
                SelectionSortRecInt(p,0,size);
                SelectionSortRecString(p,0,size);
                break;

            case 5:
                QuickSortInt(p,0,size-1);
                QuickSortString(p,0,size-1);
                break;
            case 6:
                Quick3Int(p,0,size-1);
                Quick3String(p,0,size-1);

                break;

            case 7:
                ShellSortInt(p,size);
                ShellSortString(p,size);
                break;
            
            case 8:
                MergeSortInt(p, 0, size-1);
                MergeSortString(p, 0, size-1);
                break;

            case 9: 
                CountingSort(p,size);
                break;

            case 10:
                BucketSort(p,size);
                break;

            case 11:
                CombSortInt(p,size);
                CombSortString(p,size);
                break;
                
            case 12:
                PancakeSortInt(p,size);
                PancakeSortString(p,size);
                break;

            case 13:
                heapSortInt(p,size-1);
                heapSortString(p,size-1);
                break;

            case 14:
                CocktailSortInt(p,size);
                CocktailSortString(p,size);
                break;

            case 15:
                StoogeSortInt(p,0,size-1);
                StoogeSortString(p,0,size-1);
                break;

            case 16:
                BogoSortInt(p,size);
                BogoSortString(p,size);
                break;

            default:
                aux=0;
                printf("\nInvalid option.");
                break;
        }
}

void clear(){
    printf("\nPress ENTER to continue...\n");
    getchar();
    system(clean);
}

void switchInt(Product p[], int i, int j){
    int aux;
    aux=p[i].number;
    p[i].number=p[j].number;
    p[j].number=aux;
}

void switchString(Product p[], int i, int j){
    char aux[30];
    strcpy(aux, p[i].string);
    strcpy(p[i].string, p[j].string);
    strcpy(p[j].string, aux);
}