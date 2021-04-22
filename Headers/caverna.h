/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#ifndef CAVERNA_H
#define CAVERNA_H

#include "includes.h"

typedef int **Caverna;
typedef struct
{
    Caverna caverna;
    int qtLinhas, qtColunas, qtVida;
} TipoCaverna;

typedef TipoCaverna *TipoApontador;

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int vida);
void mostraCaverna(TipoApontador *apCaverna);

#endif