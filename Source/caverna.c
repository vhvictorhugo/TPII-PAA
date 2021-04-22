/*
*   Programa: 
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/includes.h"

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int chave)
{

    (*apCaverna)->qtLinhas = linha;
    (*apCaverna)->qtColunas = coluna;
    (*apCaverna)->qtVida = chave;
    puts("a");

    (*apCaverna)->caverna = (int **)calloc(((*apCaverna)->qtLinhas + 1), sizeof(int *));
    puts("b");
    for (int i = 0; i < (*apCaverna)->qtLinhas; i++)
    {
        (*apCaverna)->caverna[i] = (int *)calloc(((*apCaverna)->qtColunas + 1), sizeof(int));
        puts("c");
    }

    return;
}

void mostraCaverna(TipoApontador *apCaverna)
{
    for (int i = 0; i < (*apCaverna)->qtLinhas; i++)
    {
        for (int j = 0; j < (*apCaverna)->qtLinhas; j++)
        {
            (*apCaverna)->caverna[i][j] = 0;
            printf("%d ", (*apCaverna)->caverna[i][j]);
        }
        puts("");
    }
}