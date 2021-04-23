/*
*   Programa: PROBLEMA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/caverna.h"

//gcc -o exec main.c ./Sources/caverna.c 
//Como rodar o makefile no windows mingw32-make <enter>  exec <enter>

int main(int argc, char const *argv[])
{
 
     
    
    TipoApontador caverna;
    int linha = 3, coluna = 3, vida = 40;
    inicializaCaverna(&caverna,linha,coluna,vida);
    inserirCaverna(&caverna);
    mostrarCaverna(&caverna);
    return 0;
}