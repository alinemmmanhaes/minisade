#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"

typedef struct tBiopsia tBiopsia;

/**
 * Cria Biopsia alocando dinamicamente com as variaveis passadas por parametro
*/
tBiopsia* CriaBiopsia(char* nomePaciente, char* cpfPaciente, tLesao** lesoes, int qtdLesoes, char* nomeMedico, char* CRM, char* data);

/**
 * Verifica se a biopsia é NULL e a desaloca caso não
*/
void desalocaBiopsia(void *dado);

/**
 * Imprime a biopsia na tela nos moldes especificados 
*/
void imprimeNaTelaBiopsia(void *dado);

/**
 * Imprime a biopsia no biopsia.txt nos moldes especificados 
*/
void imprimeEmArquivoBiopsia(void *dado, char *path);

#endif