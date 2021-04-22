#include "includes.h"

typedef struct
{
    int tipo; // TIPO DO VALOR A SER ACESSADO: 0 - STRING, 1 - INTEIRO
    union teste
    {
        char posicao;
        int valor;
    };
} tipoDado;

typedef tipoDado *TipoApontador;

typedef struct
{

} tipoCaverna;
