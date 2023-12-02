#ifndef _TENCAMINHAMENTO_H_
#define _TENCAMINHAMENTO_H_

#define MAX_TAM_ESPECIALIDADE 50
#define MAX_TAM_MOTIVO 300

typedef struct tEncaminhamento tEncaminhamento;

tEncaminhamento* CriaEncaminhamento(char* nomePaciente, char* cpfPaciente, char* especialidade, char* motivo, char* nomeMedico, char* CRM, char* data);

void desalocaEncaminhamento(void *dado);

void imprimeNaTelaEncaminhamento(void *dado);

void imprimeEmArquivoEncaminhamento(void *dado, char *path);

#endif