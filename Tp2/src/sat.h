#include "filaClau.h"
#ifndef SAT_H
#define SAT_H

void semPreconceito();
void truthTable(int n, int leng);
//void verifica(TItem* pItem);
int verifica(TFila* pFila);
void percorre(TCelula* pCell, int (*mat)[50], int C, int N);
void printaLinha();

#endif 