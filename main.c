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


    TipoApontadorTabela tabelaPassos; //Tipo tabela tipo char
    TipoApontador caverna;
     
    leituraArquivo(&caverna);
    //mostrarCaverna(&caverna);
    inicializaTabela(&caverna,&tabelaPassos);



    movimentaEstudante(&caverna,&tabelaPassos);
    
     /*
void main(int argc, char **argv){

  char nomeArquivo[30];
  printf("=====================================================================\n");
  printf("=       *******     *   ********   ********       *         *       =\n");
  printf("=      *       *        *          *               *       *        =\n");
  printf("=      *       *    *   ********   *         ****   *     *         =\n");
  printf("=      *     *      *          *   *                 *   *          =\n");
  printf("=      *       *    *   ********   ********            *            =\n");
  printf("=====================================================================\n");
  strcpy(nomeArquivo, argv[1] );
  if(argc == 2) //gcc -o teste main.c montador.c src/include/montador.h
    imprimirNoTerminal(nomeArquivo); //teste entrada.asm
  else
    imprimirNoArquivo(nomeArquivo, argv[3]); //teste entrada.asm -o saida
    

}
*/

    return 0;
}