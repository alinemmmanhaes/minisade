#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

typedef struct tPaciente tPaciente;

/**
 * Cria paciente a partir das informacoes passadas por parametro
 */
tPaciente* CriaPaciente(char* nome, char* cpf, int dia, int mes, int ano, char* tel, char* genero);

void DesalocaPaciente(tPaciente* pac);

char* ObtemNomePaciente(tPaciente* pac);
char* ObtemCPFPaciente(tPaciente* pac);
char* ObtemSexoPaciente(tPaciente* pac);
char* ObtemDataNascPaciente(tPaciente* pac);
int ObtemNumeroAtendimentosPaciente(tPaciente* pac);
int ObtemIdadePaciente(tPaciente* pac);

int PacComparaCPF(tPaciente* pac, char* cpf);
int PacComparaNome(tPaciente* pac, char* nome);

int PacIncrementaConsultas(tPaciente* pac);

#endif