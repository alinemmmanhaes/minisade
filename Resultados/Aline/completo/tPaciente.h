#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

typedef struct tPaciente tPaciente;

/**
 * Cria paciente a partir das informacoes passadas por parametro
 */
tPaciente* CriaPaciente(char* nome, char* cpf, char* nasc, char* tel, char* genero);

void DesalocaPaciente(tPaciente* pac);

char* ObtemNomePaciente(tPaciente* pac);
char* ObtemCPFPaciente(tPaciente* pac);

int PacComparaCPF(tPaciente* pac, char* cpf);
#endif