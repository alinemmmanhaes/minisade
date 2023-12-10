#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include "tPaciente.h"
#include "tConsulta.h"
#include "tFila.h"

typedef struct tRelatorio tRelatorio;

tRelatorio* CriaRelatorio();

void desalocaRelatorio(void *dado);

void imprimeNaTelaRelatorio(void *dado);
void imprimeEmArquivoRelatorio(void *dado, char *path);

void CalculaRelatorio(tRelatorio* rel, tPaciente** pacs, int nPacs, tConsulta** cons, int nCons);
void GeraRelatorio(int nPacientes, int nConsultas, tPaciente** pacientes, tConsulta** consultas, tRelatorio*** relatorios, int* nRelatorios, tFila* filaImpressao);

#endif