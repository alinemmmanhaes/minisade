#ifndef _TLISTABUSCA_H_
#define _TLISTABUSCA_H_

#include "tPaciente.h"
#include "tFila.h"

typedef struct tListaBusca tListaBusca;

tListaBusca* CriaListaBusca();

/**
 * Adiciona um novo paciente na lista de busca, reallocando o ponteiro de ponteiro de pacientes
*/
void AdicionaPacienteListaBusca(tListaBusca* lista, tPaciente* paciente);

/**
 * Verifica se a lista é NULL e a desaloca caso não, sem desalocar seus pacientes
*/
void DesalocaListaBusca(void* dado);

/**
 * Imprime a lista na tela nos moldes especificados 
*/
void imprimeNaTelaListaBusca(void *dado);

/**
 * Imprime a lista no lista_busca.txt nos moldes especificados 
*/
void imprimeEmArquivoListaBusca(void *dado, char *path);

/**
 * Le nome do paciente que sera buscado, 
 * compara nome com o dos outros pacientes cadastrados no sistema, 
 * cria uma nova lista, 
 * adiciona pacientes na lista,
 * envia lista para a fila de impressao
*/
void RealizaBusca(int nPacientes, tPaciente** pacientes, int* nListaBusca, tListaBusca*** listasbusca, tFila* filaImpressao);

#endif