#ifndef CAVERNA_H
#define CAVERNA_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

typedef int **Caverna;

typedef struct
{
    Caverna caverna;
    int qtLinhas, qtColunas, qtVida;
    int xSaida, ySaida;         // coordenadas da saida
    int xEstudante, yEstudante; // coordenadas da entrada inicial
} TipoCaverna;

typedef TipoCaverna *TipoApontador;

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int vida);
void mostrarCaverna(TipoApontador *apCaverna);
int max(int a, int b);
void movimentaEstudante(TipoApontador *apCaverna); 
int verificaPosicao(TipoApontador *apCaverna, int x, int y);
 

#endif