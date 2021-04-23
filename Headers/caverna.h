#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

typedef int ** Caverna;

typedef struct 
{
    Caverna caverna;
    int qtLinhas, qtColunas, qtVida;
}TipoCaverna;

typedef TipoCaverna *TipoApontador;

void inicializaCaverna(TipoApontador *ponteiro, int linha, int coluna, int vida);
void inserirCaverna(TipoApontador *ponteiro);
void mostrarCaverna(TipoApontador *apCaverna);

