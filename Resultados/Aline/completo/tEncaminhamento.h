#ifndef _TENCAMINHAMENTO_H_
#define _TENCAMINHAMENTO_H_

#define MAX_TAM_ESPECIALIDADE 50
#define MAX_TAM_MOTIVO 300

typedef struct tEncaminhamento tEncaminhamento;

/**
 * Cria Encaminhamento alocando dinamicamente com as variaveis passadas por parametro
*/
tEncaminhamento* CriaEncaminhamento(char* nomePaciente, char* cpfPaciente, char* especialidade, char* motivo, char* nomeMedico, char* CRM, char* data);

/**
 * Verifica se o encaminhamento é NULL e o desaloca caso não
*/
void desalocaEncaminhamento(void *dado);

/**
 * Imprime o encaminhamento na tela nos moldes especificados 
*/
void imprimeNaTelaEncaminhamento(void *dado);

/**
 * Imprime o encaminhamento no encaminhamento.txt nos moldes especificados 
*/
void imprimeEmArquivoEncaminhamento(void *dado, char *path);

#endif