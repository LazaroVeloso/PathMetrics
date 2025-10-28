#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdbool.h>
#include "ponto.h"
#include "objeto.h"


float calcDeslocamento(Ponto* inicio, Ponto* fim);
float calcTrajetoria(Objeto* objeto, int n);

void mergerec(Objeto* objetos, int l, int r);
double round2(double valor);
void merge(Objeto* objetos, int l, int m, int r);
void MergeSort(Objeto* objetos, int n);

void imprimeOrdenado(Objeto* objeto, int n);

#endif