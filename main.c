/*
*   Programa: PROBLEMA DE PROGRAMAÇÃO DINÂMICA FUGA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/caverna.h"
#include "./Headers/auxiliares.h"

int main(int argc, char const *argv[])
{
    TipoApontadorTabela tabelaPassos; // tabela que armazenara as decisoes, tem as mesmas dimensoes do problema original
    TipoApontador caverna;

    char nomeArquivo[70];

    if (argc == 2) //exec caverna1.txt(se tiver na msm pasta que o main) ou exec ./arquivos/caverna1.txt
    {
        strcpy(nomeArquivo, argv[1]);

        leituraArquivo(&caverna, nomeArquivo);
        inicializaTabela(&caverna, &tabelaPassos);
        movimentaEstudante(&caverna, &tabelaPassos);
        EscritaArquivo(&caverna, &tabelaPassos);
    }
    return 0;
}
