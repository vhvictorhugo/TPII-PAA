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

void EscritaArquivo(TipoApontador *apCaverna, TipoApontadorTabela *apTabela){
    FILE *arquivoSaida;
    int vida = (*apCaverna)->qtVida;
    int movimentoI = (*apCaverna)->xSaida;
    int movimentoj = (*apCaverna)->ySaida;
    //Abertura do arquivo para escrita
    arquivoSaida = fopen("testeSAIDA.txt","w");

    //Preecorrendo a tabela passoas para inserir no arquivo a solução
    for (int i = (*apCaverna)->xSaida ; i < (*apCaverna)->qtLinhas; i++)
    {
        for (int j = (*apCaverna)->ySaida; j < (*apCaverna)->qtColunas; j++)
        {
            if(movimentoI == i && movimentoj == j)
            {       
                if(vida > 0){
                    vida +=(*apCaverna)->caverna[i][j];
                }
                
                fprintf(arquivoSaida,"%d %d\n",i,j);
            }

            if((*apTabela)->tabela[i][j] == 'd' && movimentoI == i && movimentoj == j)
            {
                movimentoj = j + 1;
                movimentoI = i;
            }
            if((*apTabela)->tabela[i][j] == 'b' && movimentoI == i && movimentoj == j)
            {
                movimentoI = i + 1;
                movimentoj = j;
            }
        }
    }
    fclose(arquivoSaida);

    if(vida <= 0){
        arquivoSaida = fopen("testeSAIDA.txt","w");
        fprintf(arquivoSaida,"Impossível");
    }

    fclose(arquivoSaida);
}
