#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#include "tPaciente.h"
#include "tConsulta.h"
#include "tFila.h"

typedef struct tRelatorio tRelatorio;

/**
 * Cria Relatorio alocando dinamicamente
*/
tRelatorio* CriaRelatorio();

/**
 * Verifica se o Relatorio é NULL e a desaloca caso não, sem desalocar seus pacientes
*/
void desalocaRelatorio(void *dado);

/**
 * Imprime o relatorio na tela nos moldes especificados 
*/
void imprimeNaTelaRelatorio(void *dado);
/**
 * Imprime o relatorio no relatorio_geral.txt nos moldes especificados 
*/
void imprimeEmArquivoRelatorio(void *dado, char *path);

/**
 * Calcula as informacoes do relatorio:
 * qtd de pacientes atendidos,
 * qtd de pacientes por sexo,
 * media de idade dos paciente,
 * qtd de lesoes,
 * tamanho medio de lesoes,
 * qtd de lesoes enviadas p cirurgia,
 * qtd de lesoes enviadas p crioterapia
*/
void CalculaRelatorio(tRelatorio* rel, tPaciente** pacs, int nPacs, tConsulta** cons, int nCons);
/**
 * Gera um novo relatorio, alocando dinamicamente, calcula relatorio e acrescenta documento na fila de impressao
*/
void GeraRelatorio(int nPacientes, int nConsultas, tPaciente** pacientes, tConsulta** consultas, tRelatorio*** relatorios, int* nRelatorios, tFila* filaImpressao);

#endif