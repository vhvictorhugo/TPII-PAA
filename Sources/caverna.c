/*
*   Programa: PROBLEMA DE PROGRAMAÇÃO DINÂMICA FUGA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/caverna.h"

void inicializaCaverna(TipoApontador *apCaverna, int linha, int coluna, int vida)
{
    (*apCaverna) = (TipoCaverna *)malloc(sizeof(TipoCaverna)); // aloca a estrutura

    (*apCaverna)->qtColunas = coluna;
    (*apCaverna)->qtLinhas = linha;
    (*apCaverna)->qtVida = vida;

    (*apCaverna)->caverna = (int **)calloc(((*apCaverna)->qtLinhas + 1), sizeof(int *));

    for (int i = 0; i < linha; i++)
    {
        (*apCaverna)->caverna[i] = (int *)calloc(((*apCaverna)->qtColunas + 1), sizeof(int));
    }
}

void inicializaTabela(TipoApontador *apCaverna, TipoApontadorTabela *apTabela){
   
    (*apTabela) = (TipoTabela *)malloc(sizeof(TipoTabela)); //Faz a alocação da estrutura

    (*apTabela)->qtLinhas = (*apCaverna)->qtLinhas;
    (*apTabela)->qtColunas = (*apCaverna)->qtColunas;

    (*apTabela)->tabela = (char **)calloc(((*apTabela)->qtLinhas+1),sizeof(char *));
    
    for (int i = 0; i < (*apTabela)->qtLinhas; i++)
    {
        (*apTabela)->tabela[i] = (char *)calloc(((*apTabela)->qtColunas + 1), sizeof(char));
    }
}



void mostrarCaverna(TipoApontador *apCaverna)
{
    printf("linha: %d\n", (*apCaverna)->qtLinhas);
    printf("Coluna: %d\n", (*apCaverna)->qtColunas);
    printf("Vida: %d\n", (*apCaverna)->qtVida);

    for (int i = 0; i < (*apCaverna)->qtLinhas; i++)
    {
        printf("\n");
        for (int j = 0; j < (*apCaverna)->qtColunas; j++)
        {
            printf("%d ", (*apCaverna)->caverna[i][j]);
        }
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return 1; // a é maior
    }
    else
    {
        return 0; // b é maior ou igual
    }
}

void movimentaEstudante(TipoApontador *apCaverna, TipoApontadorTabela *apTabelaPassos)
{
                                                                        //apTabela tabela auxiliar para armazenas as direções dos passos
    int tabelaAux[(*apCaverna)->qtLinhas][(*apCaverna)->qtColunas];
    int verificaCasoBase = 1;                                           //  se for 1, quer dizer que estamos na posicao inicial e então não se faz verificação
    int verificaBaixo, verificaDireita;
    int maximo = 0;

    
    (*apCaverna)->caverna[(*apCaverna)->xSaida][(*apCaverna)->ySaida] = 0;
    (*apCaverna)->caverna[(*apCaverna)->xEstudante][(*apCaverna)->yEstudante] = (*apCaverna)->qtVida;

    for (int i = (*apCaverna)->xSaida; i < (*apCaverna)->qtLinhas; i++) 
    {
        for (int j = (*apCaverna)->ySaida; j < (*apCaverna)->qtColunas; j++)
        {
             tabelaAux[i][j] = (*apCaverna)->caverna[i][j];
        }
    }
    
    for (int i = (*apCaverna)->qtLinhas - 1; i >= (*apCaverna)->xSaida; i--) // for que percorre a parte limitada da solução
    {
        for (int j = (*apCaverna)->qtColunas - 1; j >= (*apCaverna)->ySaida; j--)
        {
            if (verificaCasoBase == 1)
            {
                (*apTabelaPassos)->tabela[i][j] = '*';
                verificaCasoBase++; // caso base ja ocorreu
            }
            else
            {
                verificaDireita = verificaPosicao(&(*apCaverna), i, j + 1);

                verificaBaixo = verificaPosicao(&(*apCaverna), i + 1, j);

                if (verificaBaixo == 1 && verificaDireita == 1)
                {

                    if (max(tabelaAux[i + 1][j] + tabelaAux[i][j], tabelaAux[i][j + 1] + tabelaAux[i][j]))
                    {
                        
                        (*apTabelaPassos)->tabela[i][j] = 'b';
                        tabelaAux[i][j] = tabelaAux[i + 1][j] + tabelaAux[i][j];
                        

                    }
                    else
                    {
                        (*apTabelaPassos)->tabela[i][j] = 'd';                      
                        tabelaAux[i][j] = tabelaAux[i][j + 1] + tabelaAux[i][j];
                        
                    }
                }
                else if (verificaBaixo == 1 && verificaDireita == 0)
                {
                    (*apTabelaPassos)->tabela[i][j] = 'b';
                    tabelaAux[i][j] = tabelaAux[i + 1][j] + tabelaAux[i][j];
                    
                }
                else if (verificaBaixo == 0 && verificaDireita == 1)
                {
                    (*apTabelaPassos)->tabela[i][j] = 'd';
                    tabelaAux[i][j] = tabelaAux[i][j + 1] + tabelaAux[i][j];
                    
                }
            }
        }
    }

    //REMOVER DPS 
    for (int i = (*apCaverna)->xSaida; i < (*apCaverna)->qtLinhas; i++) // for que percorre a parte limitada da solução
    {
        for (int j = (*apCaverna)->ySaida; j < (*apCaverna)->qtColunas; j++)
        {
            printf("%c ", (*apTabelaPassos)->tabela[i][j]); 
        }
        puts("");
    }
    //REMOVER DPS
        for (int i = (*apCaverna)->xSaida; i < (*apCaverna)->qtLinhas; i++) // for que percorre a parte limitada da solução
    {
        for (int j = (*apCaverna)->ySaida; j < (*apCaverna)->qtColunas; j++)
        {
            printf("%d ", tabelaAux[i][j]); 
        }
        puts("");
    }
}

int verificaPosicao(TipoApontador *apCaverna, int x, int y)
{
    if (x <= (*apCaverna)->qtLinhas - 1 && y <= (*apCaverna)->qtColunas - 1)
    {
        return 1;
    }
    return 0;
}
