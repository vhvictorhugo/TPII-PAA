#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

#include "caverna.h"

void leituraArquivo(TipoApontador *apCaverna);
void EscritaArquivo(TipoApontador *apCaverna, TipoApontadorTabela *apTabela);
#endif