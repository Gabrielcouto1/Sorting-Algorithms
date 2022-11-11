#ifndef BOGOSORT_H
#define BOGOSORT_H

#include "produto.h"
int isSortedInt(Produto p[], int tamanho);
void shuffleInt(Produto p[], int tamanho);
void BogoSortInt(Produto p[], int tamanho);
int isSortedString(Produto p[], int tamanho);
void shuffleString(Produto p[], int tamanho);
void BogoSortString(Produto p[], int tamanho);

#endif