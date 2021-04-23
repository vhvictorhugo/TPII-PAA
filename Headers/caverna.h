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
} TipoCaverna;

typedef TipoCaverna *TipoApontador;

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int vida);
void mostrarCaverna(TipoApontador *apCaverna);

#endif