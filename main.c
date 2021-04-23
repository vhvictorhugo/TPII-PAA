/*
*   Programa: PROBLEMA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/caverna.h"
#include "./Headers/auxiliares.h"

//gcc -o exec main.c ./Sources/caverna.c
//Como rodar o makefile no windows mingw32-make <enter>  exec <enter>

int main(int argc, char const *argv[])
{
    TipoApontador caverna;

    leituraArquivo(&caverna);
    //mostrarCaverna(&caverna);

    movimentaEstudante(&caverna);

    return 0;
}