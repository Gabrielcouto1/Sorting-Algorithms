#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(){
    clock_t end, start;
    double time;
    int op, size, filling_type;
    system(clean);

    while(1){
        printf("Type the size of the array to be sorted (or enter -1 to exit): ");
        scanf("%d",&size);
        if(size==-1)
            break;
        if(size<=0)
            size=100;

        Product p[size];
        system(clean);
        
        printf("How would you like to fill the integer array?");
        printf("\n[1]: With randomly generated numbers;");
        printf("\n[2]: With ascending order numbers;");
        printf("\n[3]: With descending order numbers;");
        printf("\n[4]: With few unique keys;");
        printf("\nType the option: ");

        scanf("%d", &filling_type);
        if(filling_type<1||filling_type>4)
            filling_type=1;
        system(clean);

        printf("Choose the sorting algorithm: ");
        printf("\n[1]: BubbleSort;");
        printf("\n[2]: InsertionSort;");
        printf("\n[3]: SelectionSort;");
        printf("\n[4]: Recursive SelectionSort;");
        printf("\n[5]: QuickSort;");
        printf("\n[6]: 3 way QuickSort;");
        printf("\n[7]: ShellSort;");
        printf("\n[8]: MergeSort;");
        printf("\n[9]: CountingSort (it's only used to sort integers);");
        printf("\n[10]: BucketSort (it's only used to sort integers);");
        printf("\n[11]: CombSort;");
        printf("\n[12]: PancakeSort;");
        printf("\n[13]: HeapSort;");
        printf("\n[14]: CocktailSort;");
        printf("\n[15]: StoogeSort;");
        printf("\n[16]: BogoSort (DON'T USE IN ARRAYS WITH MORE THAN 10 ELEMENTS);");
        printf("\n[99]: Exit.");
        printf("\nType the option: ");
        
        scanf("%d",&op);
        if(op==99)
            break;
        
        fillArray(p,size,filling_type); 
        start=clock();

        sortArray(p,size,op);

        end=clock();
        time=((double)(end-start))/CLOCKS_PER_SEC;
        printArray(p,size,time,op,filling_type);
        
        clear();
    }

    clear();
    return 1;
}