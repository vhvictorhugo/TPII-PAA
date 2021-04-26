/*
*   Programa: PROBLEMA DE PROGRAMAÇÃO DINÂMICA FUGA DA CAVERNA
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include "caverna.h"

void leituraArquivo(TipoApontador *apCaverna, char *nomeArquivo);
void EscritaArquivo(TipoApontador *apCaverna, TipoApontadorTabela *apTabela);
void converteArquivo();
#endif