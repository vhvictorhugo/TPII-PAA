// void leituraArquivo(TipoApontador *apLabirinto)
// {
//     int i, j, linha, coluna, chave;

//     char nomeArquivo[20], caminhoArquivo[20];

//     FILE *arquivo;

//     printf("Entre com o nome do arquivo: ");

//     scanf("%s", nomeArquivo);

//     sprintf(caminhoArquivo, "./arquivos/%s", nomeArquivo); // funcao que compoe uma string, armazena no 1º parametro o 2º concatenado com o 3º

//     arquivo = fopen(caminhoArquivo, "r");

//     if (arquivo == NULL)
//     {
//         puts("Erro de abertura!");
//         pausaPrograma();
//         return;
//     }

//     fscanf(arquivo, "%d %d %d", &linha, &coluna, &chave);

//     inicializaLabirinto(&(*apLabirinto), linha, coluna, chave);

//     char stringLinha[(*apLabirinto)->qtColunas]; // variavel que armazenara cada linha a partir da 2ª linha do arquivo

//     for (i = 0; i < ((*apLabirinto)->qtLinhas); i++)
//     {
//         fscanf(arquivo, "%s", &stringLinha);
//         for (j = 0; j < ((*apLabirinto)->qtColunas); j++)
//         {
//             (*apLabirinto)->labirinto[i][j] = stringLinha[j] - '0';
//         }
//     }

//     fclose(arquivo);

//     return;
// }