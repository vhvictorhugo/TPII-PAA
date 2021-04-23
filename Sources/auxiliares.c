#include "../Headers/auxiliares.h"

void leituraArquivo(TipoApontador *apCaverna)
{
    char nomeArquivo[20], caminhoArquivo[40] = "./arquivos/caverna1.txt";
    char valorLeitura[10]; // valor pode ser de até 10 digitos (deve ser inteiro - faixa de valores:  -2.147.483.648 até 2.147.483.647)

    FILE *arquivo;

    int linha, coluna, vida;

    arquivo = fopen(caminhoArquivo, "r");

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
            if (valorLeitura[0] == 70)
                (*apCaverna)->caverna[i][j] = 70;
            else if (valorLeitura[0] == 73)
                (*apCaverna)->caverna[i][j] = 73;
            else
                (*apCaverna)->caverna[i][j] = atoi(valorLeitura);
        }
    }

    fclose(arquivo);

    return;
}