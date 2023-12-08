#ifndef _TMEDICO_H_
#define _TMEDICO_H_

#include <stdio.h>

typedef struct tMedico tMedico;

/**
 * Cria medico a partir das informacoes passadas por parametro
 */
tMedico* CriaMedico(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* crm, char* user, char* senha);

void DesalocaMedico(tMedico* med);

char* ObtemNomeMedico(tMedico* med);
char* ObtemCRMMedico(tMedico* med);
char* ObtemCPFMedico(tMedico* med);

int MedComparaCPF(tMedico* med, char* cpf);
int MedComparaUser(tMedico* med, char* user);
int MedComparaSenha(tMedico* med, char* senha);

void MedicoSalvaBinario(tMedico** med, int qtd, char* path);
int MedicoRecuperaBinario(tMedico** med, FILE* arq);

#endif