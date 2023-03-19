#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "product.h"
int partitionInt(Product p[], int left, int right);
void QuickSortInt(Product p[], int left, int right);
int partitionString(Product p[], int left, int right);
void QuickSortString(Product p[], int left, int right);

#endif