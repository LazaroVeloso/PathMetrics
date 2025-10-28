#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "objeto.h"
#include "ordenacao.h"
#include "ponto.h"

typedef enum {
    MENOR=1,
    IGUAL,
    MAIOR
} COMPARACAO;

float calcDeslocamento(Ponto* inicio, Ponto* fim) {
    float dx = fim->x - inicio->x;
    float dy = fim->y - inicio->y;
    float aux = sqrt((dx * dx) + (dy * dy));
    return aux;
}

float calcTrajetoria(Objeto* objeto, int n) {
    
    double soma = 0;
    for (int i = 0; i < n - 1; i++)
        soma += calcDeslocamento(&objeto->ponto[i], &objeto->ponto[i + 1]);

    return soma;    
}


COMPARACAO ItemCompara(float i1, float i2) {

    if (i1 > i2)
        return MENOR;
    else if (i1 < i2)
        return MAIOR;
    return IGUAL;
    
}

COMPARACAO ItemComparaV2(char* nome1, char* nome2) {
    if (strcmp(nome1, nome2) < 0)
         return MENOR;
    else if (strcmp(nome1, nome2) > 0)
         return MAIOR;
     return IGUAL;
}

void MergeSort(Objeto* objetos, int n) {
    mergerec(objetos, 0, n - 1);
}


void mergerec(Objeto* objetos, int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        mergerec(objetos, l, m);
        mergerec(objetos, m + 1, r);
        merge(objetos, l, m, r);
    }
}


double round2(double valor) {
    return round(valor * 100) / 100;  // Ex: 3.1415 → 3.14
}


void merge(Objeto* objetos, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    Objeto* L = (Objeto*)malloc(n1 * sizeof(Objeto));
    Objeto* R = (Objeto*)malloc(n2 * sizeof(Objeto));

    for (int i = 0; i < n1; i++) L[i] = objetos[l + i];
    for (int j = 0; j < n2; j++) R[j] = objetos[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        // Arredonda para 2 casas decimais antes de comparar
        double trajL = round2(L[i].trajetoria);
        double trajR = round2(R[j].trajetoria);
        double deslL = round2(L[i].deslocamento);
        double deslR = round2(R[j].deslocamento);

        // 1º Critério: Trajetória (decrescente)
        if (fabs(trajL - trajR) > 1e-9) {  // Pequena tolerância para evitar erros de arredondamento
            if (trajL > trajR) {
                objetos[k++] = L[i++];
            } else {
                objetos[k++] = R[j++];
            }
        } 
        // 2º Critério: Deslocamento (crescente)
        else if (fabs(deslL - deslR) > 1e-9) {
            if (deslL < deslR) {
                objetos[k++] = L[i++];
            } else {
                objetos[k++] = R[j++];
            }
        } 
        // 3º Critério: Nome (alfabético)
        else {
            if (strcmp(L[i].nome, R[j].nome) < 0) {
                objetos[k++] = L[i++];
            } else {
                objetos[k++] = R[j++];
            }
        }
    }

    while (i < n1) objetos[k++] = L[i++];
    while (j < n2) objetos[k++] = R[j++];

    free(L);
    free(R);
}


void imprimeOrdenado(Objeto* objetos, int n) {
    for(int i = 0; i < n; i++) 
        printf("%s %.2f %.2f\n", objetos[i].nome, objetos[i].trajetoria, objetos[i].deslocamento);
}
