#ifndef  FILL_PRINT_H
#define  FILL_PRINT_H

#include "product.h"
void fillArray(Product p[] , int size, int type);
void printArray(Product p[], int size, double time, int type, int filling_type);
void printArrayScreen(Product p[],int size, double time, int type, int filling_type);
char* methodType(int type);

#endif