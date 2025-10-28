#ifndef OBJETO_H
#define OBJETO_H
#include <stdio.h>
#include "ponto.h"

typedef struct objeto
{
    char nome[5];
    Ponto* ponto;
    float deslocamento;
    float trajetoria;
} Objeto;

Objeto* alocaObjetos(int numObjetos, int numPontos);
void destroiObjetos(Objeto* objetos, int numObjetos);

#endif