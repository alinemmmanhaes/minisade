#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdio.h>

typedef struct tMedico tMedico;

/**
 * Cria medico a partir das informacoes passadas por parametro
 */
tMedico* CriaMedico(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* crm, char* user, char* senha);

/**
 * Verifica se o medico é NULL e o desaloca caso não
*/
void DesalocaMedico(tMedico* med);

/**
 * Retorna o nome do medico passado por parametro
*/
char* ObtemNomeMedico(tMedico* med);
/**
 * Retorna o CRM do medico passado por parametro
*/
char* ObtemCRMMedico(tMedico* med);
/**
 * Retorna o CPF do medico passado por parametro
*/
char* ObtemCPFMedico(tMedico* med);

/**
 * Compara o CPF do medico passado por parametro com o CPF passado por parametro
*/
int MedComparaCPF(tMedico* med, char* cpf);
/**
 * Compara o user do medico passado por parametro com o user passado por parametro
*/
int MedComparaUser(tMedico* med, char* user);
/**
 * Compara a senha do medico passado por parametro com a senha passada por parametro
*/
int MedComparaSenha(tMedico* med, char* senha);

/**
 * Salva os medicos no binario
*/
void MedicoSalvaBinario(tMedico** med, int qtd, char* path);
/**
 * Recupera os medicos do binario
*/
void MedicoRecuperaBinario(tMedico*** med, FILE* arq, int* qtd);

/**
 * Cadastra um novo medico modificando o **,
 * Verifica se o CPF lido nunca foi utilizado,
 * Retorna para o menu principal
*/
void CadastraMedico(int* nMedicos, tMedico*** medicos);

#endif