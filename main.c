/*
*   Programa: 
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/includes.h"

int main(int argc, char const *argv[])
{
    // char valor [3] = {"+20"};
    // int valorInteiro = valor[];

    // if(20 == +20){
    //     puts("yes");
    // }

    TipoApontador caverna;
    int qtLinhas = 10, qtColunas = 10, qtVida = 10;
    puts("main");

    inicializaCaverna(&caverna, qtLinhas, qtColunas, qtVida);
    puts("inicializou");
    mostraCaverna(&caverna);

    return 0;
}
