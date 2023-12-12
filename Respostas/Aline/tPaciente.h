#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include <stdio.h>

typedef struct tPaciente tPaciente;

/**
 * Cria paciente a partir das informacoes passadas por parametro
 */
tPaciente* CriaPaciente(char* nome, char* cpf, int dia, int mes, int ano, char* tel, char* genero);

/**
 * Verifica se o paciente é NULL e o desaloca caso não
*/
void DesalocaPaciente(tPaciente* pac);

/**
 * Retorna o nome do paciente passado por parametro
*/
char* ObtemNomePaciente(tPaciente* pac);
/**
 * Retorna o CPF do paciente passado por parametro
*/
char* ObtemCPFPaciente(tPaciente* pac);
/**
 * Retorna o sexo do paciente passado por parametro
*/
char* ObtemSexoPaciente(tPaciente* pac);
/**
 * Retorna a data de nascimento do paciente passado por parametro
*/
char* ObtemDataNascPaciente(tPaciente* pac);
/**
 * Retorna o numero de consultas do paciente passado por parametro
*/
int ObtemNumeroAtendimentosPaciente(tPaciente* pac);
/**
 * Retorna a idade do paciente passado por parametro
*/
int ObtemIdadePaciente(tPaciente* pac);

/**
 * Compara o CPF do paciente passado por parametro com o CPF passado por parametro
*/
int PacComparaCPF(tPaciente* pac, char* cpf);
/**
 * Compara o nome do paciente passado por parametro com o nome passado por parametro
*/
int PacComparaNome(tPaciente* pac, char* nome);

/**
 * Incrementa o numero de atendimentos que o paciente passado por parametro realizou
*/
int PacIncrementaConsultas(tPaciente* pac);

/**
 * Salva os pacientes no binario
*/
void PacienteSalvaBinario(tPaciente** pac, int qtd, char* path);
/**
 * Recupera os pacientes do binario
*/
void PacienteRecuperaBinario(tPaciente*** pac, FILE* arq, int* qtd);

/**
 * Cadastra um novo paciente modificando o **,
 * Verifica se o CPF lido nunca foi utilizado,
 * Retorna para o menu principal
*/
void CadastraPaciente(int* nPacientes, tPaciente*** pacientes);

#endif