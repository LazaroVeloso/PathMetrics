#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#include "objeto.h"
#include "ponto.h"


int main() {

    int numObjetos, totalPontos;
    scanf("%d%d", &numObjetos, &totalPontos);

    Objeto* objetos = alocaObjetos(numObjetos, totalPontos);
    for (int i = 0; i < numObjetos; i++)
    {
        scanf("%s", objetos[i].nome);
        for (int j = 0; j < totalPontos; j++)
            scanf("%d%d", &objetos[i].ponto[j].x, &objetos[i].ponto[j].y); 
        
        objetos[i].deslocamento = calcDeslocamento(&objetos[i].ponto[0], &objetos[i].ponto[totalPontos - 1]);
        objetos[i].trajetoria = calcTrajetoria(&objetos[i], totalPontos);
    }
    
    MergeSort(objetos, numObjetos);
    imprimeOrdenado(objetos, numObjetos);

    destroiObjetos(objetos, numObjetos);
    return 0;
}