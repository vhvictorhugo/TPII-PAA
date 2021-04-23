/*
*   Programa: PROBLEMA DO LABIRINTO
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/caverna.h"
 
void inicializaCaverna(TipoApontador *ponteiro, int linha, int coluna, int vida){
    (*ponteiro) = (TipoCaverna*)malloc(sizeof(TipoCaverna));

    (*ponteiro)->qtColunas = coluna;
    (*ponteiro)->qtLinhas = linha;
    (*ponteiro)->qtVida = vida;

    (*ponteiro)->caverna = (int **)calloc(((*ponteiro)->qtLinhas + 1),sizeof(int*));

    for(int i = 0; i < linha; i++){
        (*ponteiro)->caverna[i] = (int *)calloc(((*ponteiro)->qtColunas + 1),sizeof(int));
    }
 
    printf("Inicializou sem explodir\n");
}

void inserirCaverna(TipoApontador *ponteiro){
    for (int i = 0; i < (*ponteiro)->qtLinhas; i++)
    {
        for (int j = 0; j < (*ponteiro)->qtColunas; j++)
        {
            (*ponteiro)->caverna[i][j] = -1;
        }
        
    }
    
}

void mostrarCaverna(TipoApontador *ponteiro){
    printf("linha: %d\n",(*ponteiro)->qtLinhas);
    printf("Coluna: %d\n",(*ponteiro)->qtColunas);
    printf("Vida: %d\n",(*ponteiro)->qtVida);

     
    for (int i = 0; i < (*ponteiro)->qtLinhas; i++)
    {
        printf("\n");
        for (int j = 0; j < (*ponteiro)->qtColunas; j++)
        {
            printf("%d ",(*ponteiro)->caverna[i][j]);
        }
    }

}
