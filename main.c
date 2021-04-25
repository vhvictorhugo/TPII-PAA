

#include "./Headers/caverna.h"
#include "./Headers/auxiliares.h"

int main(int argc, char const *argv[])
{
    TipoApontadorTabela tabelaPassos;
    TipoApontador caverna;
    char nomeArquivo[70];
    if (argc == 2)//exec caverna1.txt(se tiver na msm pasta que o main) ou exec ./arquivos/caverna1.txt
    {
        strcpy(nomeArquivo,argv[1]);
        leituraArquivo(&caverna,nomeArquivo);
        inicializaTabela(&caverna,&tabelaPassos);
        movimentaEstudante(&caverna,&tabelaPassos);
        mostrarCaverna(&caverna);
        EscritaArquivo(&caverna,&tabelaPassos);
    }
    /*
    int main( int argc, char *argv[ ] )

    Onde:

    argc – é um valor inteiro que indica a quantidade de 
    argumentos que foram passados ao chamar o programa.

    argv – é um vetor de char que contém os argumentos, 
    um para cada string passada na linha de comando.

    argv[0] armazena o nome do programa que foi chamado 
    no prompt, sendo assim, argc é pelo menos igual a 1, 
    pois no mínimo existirá um argumento.
    */   
    return 0;   
}
