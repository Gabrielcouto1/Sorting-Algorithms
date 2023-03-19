#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "product.h"
int left(int pos);
int right(int pos);
void heapMaxPosInt(Product p[], int pos, int heapSize);
void buildMaxHeapInt(Product p[], int end);
void heapSortInt(Product p[], int end);
void heapMaxPosString(Product p[], int pos, int heapSize);
void buildMaxHeapString(Product p[], int end);
void heapSortString(Product p[], int end);

#endif