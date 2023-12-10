#ifndef _TFUNCOES_H_
#define _TFUNCOES_H_

#include "tMedico.h"
#include "tPaciente.h"
#include "tSecretario.h"
#include "tConsulta.h"
#include "tFila.h"
#include "tListaBusca.h"
#include "tRelatorio.h"

void DesalocaPessoas(tPaciente** pacientes, tSecretario** secretarios, tMedico** medicos, int nMedicos, int nPacientes, int nSecretarios);
void DesalocaArquivos(tConsulta** consultas, int nConsultas, tFila* filaImpressao, tListaBusca** listasbusca, tRelatorio** relatorios);

void ImprimeMenuPrincipal(int tipo);
int ObtemTipoUsuario(tMedico** med, int nmed, tSecretario** sec, int nsec, char* user, char* senha, int* id);
void OperaFila(tFila* filaImpressao, char* path);

/**
 * SALVA OS DADOS CRIADOS AO LONGO DO SISTEMA NO BANCO DE DADOS
*/
void SalvaBinario(tPaciente** pacientes, tMedico** medicos, tSecretario** secretarios, tConsulta** consultas, int nConsultas, int nMedicos, int nPacientes, int nSecretarios, char* bancodedados);
/**
 * VERIFICA SE BANCO DE DADOS FOI CRIADO E LE DADOS ANTERIORES
*/
void RecuperaBinario(tPaciente*** pacientes, tMedico*** medicos, tSecretario*** secretarios, tConsulta*** consultas, int* nConsultas, int* nMedicos, int* nPacientes, int* nSecretarios, char* bancodedados);

void FazLogin(int nMedicos, int* nSecretarios, tMedico** medicos, tSecretario*** secretarios, int* idLogin, int* tipo);

#endif