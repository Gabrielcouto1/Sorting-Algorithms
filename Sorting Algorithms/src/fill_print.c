#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers/product.h"
#include "Headers/fill_print.h"

void fillArray(Product p[] , int size, int type){
    int i, j, prod_size, pos_char;
    char characters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(NULL));

    for(j=0;j<size;j++){
        prod_size=(rand()%25)+5;

        for(i=0;i<prod_size;i++){
            pos_char=rand()%62;
            p[j].string[i]=characters[pos_char];
        }
        p[j].string[i]='\0';
    }

    switch(type){
        case 1:
            for(i=0;i<size;i++)
                p[i].number=rand()%100001;
            break;

        case 2:
            for(i=0;i<size;i++)
                p[i].number=i+100000;
            break;

        case 3:
            for(i=size,j=0;i>0;i--,j++)
                p[j].number=i+100000;
            break;
        
        case 4:
            for(i=0; i<size; i++)
                p[i].number=(rand()%3)+100000;
            break;
    }
}

void printArray(Product p[], int size, double time, int type, int filling_type){
    int j;
    FILE *fp;

    fp = fopen("sorted_array.txt", "w+");
    fprintf(fp, "Time spent to sort the array ");
    switch(filling_type){
        case 1:
            fprintf(fp,"filled randomly,");
            break;
        case 2:
            fprintf(fp,"filled in ascending order,");
            break;
        case 3:
            fprintf(fp,"filled in descending order,");
            break;
        case 4:
            fprintf(fp,"filled using few unique keys,");
            break;
    }
    fprintf(fp," with size %d, using the ", size);
    fprintf(fp, "%s method: %.5f\n",methodType(type),time);
    
    for(j=0;j<size;j++)
        fprintf( fp, "\n> %d %s",p[j].number, p[j].string);
    printf("\nThe sorted array was stored in \"sorted_array.txt\"\n");
    fclose(fp);

    printf("Would you like to print the sorted array in the screen? [0/1]: ");
    scanf("%d",&j);
    getchar();
    if(j==1)
        printArrayScreen(p,size,time,type,filling_type);
}

void printArrayScreen(Product p[],int size, double time, int type, int filling_type){
    int i;

    if(type==9||type==10)
        for(i=0;i<size-1;i++)
            printf("\n> %d",p[i].number);
    else
        for(i=0;i<size;i++)
            printf("\n> %d %s",p[i].number, p[i].string);

    printf("\n\nTime spent to sort the array ");
    switch(filling_type){
        case 1:
            printf("filled randomly,");
            break;
        case 2:
            printf("filled in ascending order,");
            break;
        case 3:
            printf("filled in descending order,");
            break;
        case 4:
            printf("filled using few unique keys,");
            break;
    }
    
    printf(" with size %d, using the ", size);
    printf("%s method: %.5f\n",methodType(type),time);
}

char* methodType(int type){
    switch(type){
        case 1:
            return "BubbleSort";
        case 2:
            return "InsertionSort";
        case 3:
            return "SelectionSort";
        case 4:
            return "Recursive SelectionSort";
        case 5:
            return "QuickSort";
        case 6:
            return "3 way QuickSort";
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