#include <stdio.h>
#include <stdlib.h>
#include "objeto.h"
#include "ponto.h"

Objeto* alocaObjetos(int numObjetos, int numPontos) {
    Objeto* objetos = (Objeto*)malloc(sizeof(Objeto) * numObjetos);
    if (!objetos) 
        return NULL; 
    
    for (int i = 0; i < numObjetos; i++) {
        objetos[i].ponto = (Ponto*)malloc(sizeof(Ponto) * numPontos);
        if (objetos[i].ponto == NULL) {
            for (int j = 0; j < i; j++) 
                free(objetos[j].ponto);
            
            free(objetos);
            return NULL;
        }
    }

    return objetos;
}


void destroiObjetos(Objeto* objetos, int numObjetos) {
    for (int i = 0; i < numObjetos; i++)
        free(objetos[i].ponto);
    free(objetos);
}
