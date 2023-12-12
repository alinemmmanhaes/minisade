#ifndef _TFUNCOES_H_
#define _TFUNCOES_H_

#include "tMedico.h"
#include "tPaciente.h"
#include "tSecretario.h"
#include "tConsulta.h"
#include "tFila.h"
#include "tListaBusca.h"
#include "tRelatorio.h"

/**
 * DESALOCA OS DADOS DE PESSOAS CRIADOS AO LONGO DO SISTEMA NO BANCO DE DADOS
*/
void DesalocaPessoas(tPaciente** pacientes, tSecretario** secretarios, tMedico** medicos, int nMedicos, int nPacientes, int nSecretarios);
/**
 * DESALOCA OS DADOS DE ARQUIVOS CRIADOS AO LONGO DO SISTEMA NO BANCO DE DADOS
*/
void DesalocaArquivos(tConsulta** consultas, int nConsultas, tFila* filaImpressao, tListaBusca** listasbusca, tRelatorio** relatorios);

/**
 * Imprime o menu que será usado ao longo de todo o sistema
*/
void ImprimeMenuPrincipal(int tipo);
/**
 * Confere/Verifica se o login foi feito de forma correta e retorna o tipo do usuário, além disso salva o id do login do usuario logado.
 * Tipo = -1 significa que não ocorreu o login.
 * Tipo = 0 significa que um médico logou.
 * Tipo = 1 significa que um secretário ADMIN logou.
 * Tipo = 2 significa que um secretário USER logou.
*/
int ObtemTipoUsuario(tMedico** med, int nmed, tSecretario** sec, int nsec, char* user, char* senha, int* id);
/**
 * Opera e exibe o menu da fila de impressao
*/
void OperaFila(tFila* filaImpressao, char* path);

/**
 * SALVA OS DADOS CRIADOS AO LONGO DO SISTEMA NO BANCO DE DADOS
*/
void SalvaBinario(tPaciente** pacientes, tMedico** medicos, tSecretario** secretarios, tConsulta** consultas, int nConsultas, int nMedicos, int nPacientes, int nSecretarios, char* bancodedados);
/**
 * VERIFICA SE BANCO DE DADOS FOI CRIADO E LE DADOS ANTERIORES
*/
void RecuperaBinario(tPaciente*** pacientes, tMedico*** medicos, tSecretario*** secretarios, tConsulta*** consultas, int* nConsultas, int* nMedicos, int* nPacientes, int* nSecretarios, char* bancodedados);

/**
 * Printa os menus de cadastro do primeiro secretario ou de login, além de verificar se o login foi feito corretamente
*/
void FazLogin(int nMedicos, int* nSecretarios, tMedico** medicos, tSecretario*** secretarios, int* idLogin, int* tipo);

/**
 * Gera todos os arquivos de texto de forma vazia, para caso não haja nada escrito ao longo do programa, os arquivos ainda assim existirem
*/
void CriaArquivosTexto(char* path);

#endif