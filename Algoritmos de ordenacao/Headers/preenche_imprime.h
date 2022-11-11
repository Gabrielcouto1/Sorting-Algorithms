#ifndef  PREENCHE_IMPRIME_H
#define  PREENCHE_IMPRIME_H

#include "produto.h"
void preencheVetor(Produto p[], int tamanho, int tipo);
void imprimeVetor(Produto p[], int tamanho, double tempo, int tipo, int preenchimento);
void imprimeVetorTela(Produto p[],int tamanho, double tempo, int tipo, int preenchimento);
char* tipoAlgoritmo(int tipo);

#endif