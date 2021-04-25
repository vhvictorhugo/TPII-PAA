/*
*   Programa: PROBLEMA DE PROGRAMAÇÃO DINÂMICA FUGA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#ifndef CAVERNA_H
#define CAVERNA_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>



typedef char **Tabela;

typedef struct 
{
   Tabela tabela;
   int qtLinhas, qtColunas;
}TipoTabela;
typedef TipoTabela * TipoApontadorTabela;

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
 
int verificaPosicao(TipoApontador *apCaverna, int x, int y);
 
void movimentaEstudante(TipoApontador *apCaverna, TipoApontadorTabela *apTabelaPassos);
void inicializaTabela(TipoApontador *apCaverna, TipoApontadorTabela *apTabela);


#endif