/*
*   Programa: PROBLEMA DE PROGRAMAÇÃO DINÂMICA FUGA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/auxiliares.h"

void leituraArquivo(TipoApontador *apCaverna, char *nomeArquivo)
{
    char valorLeitura[10]; // valor pode ser de até 10 digitos (deve ser inteiro - faixa de valores:  -2.147.483.648 até 2.147.483.647)

    FILE *arquivo;

    int linha, coluna, vida;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        puts("Erro de abertura!");
        system("pause");
        return;
    }

    fscanf(arquivo, "%d %d %d", &linha, &coluna, &vida);

    inicializaCaverna(&(*apCaverna), linha, coluna, vida);

    for (int i = 0; i < (*apCaverna)->qtLinhas; i++)
    {
        for (int j = 0; j < (*apCaverna)->qtColunas; j++)
        {
            fscanf(arquivo, "%s", valorLeitura);
            if (valorLeitura[0] == 70) // valor da tabela ASCII para a letra F
            {
                (*apCaverna)->caverna[i][j] = 70; // atribui o valor
                (*apCaverna)->xSaida = i;
                (*apCaverna)->ySaida = j;
            }
            else if (valorLeitura[0] == 73) // valor da tabela ASCII para a letra I
            {
                (*apCaverna)->caverna[i][j] = 73; // atribui o valor
                (*apCaverna)->xEstudante = i;
                (*apCaverna)->yEstudante = j;
            }
            else
                (*apCaverna)->caverna[i][j] = atoi(valorLeitura);
        }
    }

    fclose(arquivo);

    return;
}

void EscritaArquivo(TipoApontador *apCaverna, TipoApontadorTabela *apTabela)
{
    FILE *arquivoSaida;
    int vida = (*apCaverna)->qtVida;
    int movimentoI = (*apCaverna)->xSaida;
    int movimentoj = (*apCaverna)->ySaida;

    if ((*apCaverna)->xEstudante < (*apCaverna)->xSaida || (*apCaverna)->yEstudante < (*apCaverna)->ySaida)
    { // coluna estudante é menor que coluna da saida e linha estudante é menor que linha da saida

        remove("./arquivos/PASSOS.txt");
        arquivoSaida = fopen("./arquivos/resultado.txt", "w");
        fprintf(arquivoSaida, "Impossível");
        fclose(arquivoSaida);
        return;
    }

    //Abertura do arquivo para escrita
    arquivoSaida = fopen("./arquivos/resultado.txt", "w");

    //Percorrendo a tabela passos para inserir no arquivo a solução
    for (int i = (*apCaverna)->xSaida; i <= (*apCaverna)->xEstudante; i++)
    {
        for (int j = (*apCaverna)->ySaida; j <= (*apCaverna)->yEstudante; j++)
        {

            if ((*apTabela)->tabela[i][j] == 'd' && movimentoI == i && movimentoj == j)
            {
                movimentoj = j + 1;
                movimentoI = i;
                if (vida > 0)
                {
                    vida += (*apCaverna)->caverna[i][j];
                }

                fprintf(arquivoSaida, "%d %d\n", i, j);
            }
            else if ((*apTabela)->tabela[i][j] == 'b' && movimentoI == i && movimentoj == j)
            {
                movimentoI = i + 1;
                movimentoj = j;
                if (vida > 0)
                {
                    vida += (*apCaverna)->caverna[i][j];
                }

                fprintf(arquivoSaida, "%d %d\n", i, j);
            }
            else if ((*apTabela)->tabela[i][j] == '*' && movimentoI == i && movimentoj == j)
            {

                fprintf(arquivoSaida, "%d %d\n", i, j);
            }
        }
    }

    fclose(arquivoSaida);

    if (vida <= 0)
    {                                       // vida ao final do trajeto fica <= 0
        remove("./arquivos/resultado.txt"); // exclui o arquivo anterior para adicionar um novo contendo a solucao sem saida
        arquivoSaida = fopen("./arquivos/resultado.txt", "w");
        fprintf(arquivoSaida, "Impossível");
        fclose(arquivoSaida);
    }
    else
    {
        converteArquivo();
        remove("./arquivos/resultado.txt");
    }
}

void converteArquivo()
{
    FILE *arq = fopen("./arquivos/resultado.txt", "r");

    FILE *arqAux = fopen("./arquivos/PASSOS.txt", "w");

    int numLinhas = -1, posI, posJ;

    while (!feof(arq))
    { // percorre o arquivo para contar quantas linhas tem
        fscanf(arq, "%d %d", &posI, &posJ);
        numLinhas++;
    }

    rewind(arq); // volta ao inicio do arquivo, pois o while anterior nos deixa no final do arquivo

    int matriz[numLinhas][2]; // armazena os valores das linhas do arquivo

    for (int i = (numLinhas - 1); i >= 0; i--)
    { // for para criar a matriz com os valores do arquivo com as informacoes invertidas
        fscanf(arq, "%d %d", &posI, &posJ);

        for (int j = 1; j >= 0; j--)
        {
            if (j == 0)
                matriz[i][j] = posI;
            else
                matriz[i][j] = posJ;
        }
    }

    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                fprintf(arqAux, "%d ", matriz[i][j]);
            else
                fprintf(arqAux, "%d\n", matriz[i][j]);
        }
    }

    fclose(arq);
    fclose(arqAux);

    return;
}