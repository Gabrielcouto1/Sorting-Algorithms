#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "produto.h"
int particaoInt(Produto p[], int esq, int dir);
void QuickSortInt(Produto p[], int esq, int dir);
int particaoString(Produto p[], int esq, int dir);
void QuickSortString(Produto p[], int esq, int dir);

#endif