#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "produto.h"
int esq(int pos);
int dir(int pos);
void heapMaxPosInt(Produto p[], int pos, int tamHeap);
void construirMaxHeapInt(Produto p[], int fim);
void heapSortInt(Produto p[], int fim);
void heapMaxPosString(Produto p[], int pos, int tamHeap);
void construirMaxHeapString(Produto p[], int fim);
void heapSortString(Produto p[], int fim);

#endif