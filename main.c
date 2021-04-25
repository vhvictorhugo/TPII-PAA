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

    if(argc == 2) //exec caverna1.txt
    {
      
    }

    
    char nomeArquivo[30] = "teste.txt";
    TipoApontadorTabela tabelaPassos; //Tipo tabela tipo char
    TipoApontador caverna;
     
    leituraArquivo(&caverna);
    inicializaTabela(&caverna,&tabelaPassos);
    movimentaEstudante(&caverna,&tabelaPassos);
    mostrarCaverna(&caverna);
    EscritaArquivo(&caverna,&tabelaPassos);
    
    

/*
  int main( int argc, char *argv[ ] )

  Onde:

  argc – é um valor inteiro que indica a quantidade de argumentos que foram passados ao chamar o programa.

  argv – é um vetor de char que contém os argumentos, um para cada string passada na linha de comando.

  argv[0] armazena o nome do programa que foi chamado no prompt, sendo assim, argc é pelo menos igual a 1, pois no mínimo existirá um argumento.

*/
     /*
void main(int argc, char **argv){
 
  strcpy(nomeArquivo, argv[1] );
  if(argc == 2) //gcc -o teste main.c montador.c src/include/montador.h
    imprimirNoTerminal(nomeArquivo); //teste entrada.asm
  else
    imprimirNoArquivo(nomeArquivo, argv[3]); //teste entrada.asm -o saida
    

}
*/

    return 0;
}