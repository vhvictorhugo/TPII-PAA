/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/caverna.h"

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int vida)
{
    (*apCaverna) = (TipoCaverna *)malloc(sizeof(TipoCaverna)); // aloca a estrutura

    (*apCaverna)->qtColunas = coluna;
    (*apCaverna)->qtLinhas = linha;
    (*apCaverna)->qtVida = vida;

    (*apCaverna)->caverna = (int **)calloc(((*apCaverna)->qtLinhas + 1), sizeof(int *));

    for (int i = 0; i < linha; i++)
    {
        (*apCaverna)->caverna[i] = (int *)calloc(((*apCaverna)->qtColunas + 1), sizeof(int));
    }
}

void mostrarCaverna(TipoApontador *apCaverna)
{
    printf("linha: %d\n", (*apCaverna)->qtLinhas);
    printf("Coluna: %d\n", (*apCaverna)->qtColunas);
    printf("Vida: %d\n", (*apCaverna)->qtVida);

    for (int i = 0; i < (*apCaverna)->qtLinhas; i++)
    {
        printf("\n");
        for (int j = 0; j < (*apCaverna)->qtColunas; j++)
        {
            printf("%d ", (*apCaverna)->caverna[i][j]);
        }
    }
}
