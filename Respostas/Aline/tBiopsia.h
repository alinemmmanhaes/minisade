#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

typedef struct tBiopsia tBiopsia;

tBiopsia* CriaBiopsia(char* nomePaciente, char* cpfPaciente, tLesao** lesoes, int qtdLesoes, char* nomeMedico, char* CRM, char* data);

void desalocaBiopsia(void *dado);

void imprimeNaTelaBiopsia(void *dado);

void imprimeEmArquivoBiopsia(void *dado, char *path);

#endif