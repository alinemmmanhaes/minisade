#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include <stdio.h>
#include "tLesao.h"
#include "tMedico.h"
#include "tPaciente.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tDocumento.h"
#include "tFila.h"

typedef struct tConsulta tConsulta;

/**
 * Cria Consulta alocando dinamicamente com as variaveis passadas por parametro
*/
tConsulta* CriaConsulta(tMedico* medico, char* cpfPaciente, char* nomePaciente);

/**
 * Verifica se a consulta é NULL e a desaloca caso não
*/
void desalocaConsulta(tConsulta* consulta);

/**
 * Le as variaveis que estavam faltando e acrescenta na consulta passada por parametro
*/
void LeConsulta(tConsulta* cons);

/**
 * Cadastra uma lesao na consulta reallocando o tamanho do ponteiro de lesoes e lendo as informacoes da lesao
*/
void ConsultaCadastraLesao(tConsulta* cons);
/**
 * Cria um documento receita, le as informacoes que faltam e adiciona o documento na fila
*/
void ConsultaGerarReceita(tConsulta* cons, tFila* fila);
/**
 * Cria um documento encaminhamento, le as informacoes que faltam e adiciona o documento na fila
*/
void ConsultaEncaminhamento(tConsulta* cons, tFila* fila);
/**
 * Cria um documento biopsia e adiciona o documento na fila
*/
void ConsultaBiopsia(tConsulta* cons, tFila* fila);

/**
 * Retorna a qtd de lesoes na consulta
*/
int ObtemQtdLesoesConsulta(tConsulta* cons);
/**
 * Retorna o tamanho da lesao de indice "ind" na consulta
*/
int ConsultaObtemTamLesaoI(tConsulta* cons, int ind);
/**
 * Retorna se a lesao de indice "ind" na consulta foi encaminhada pra cirurgia
*/
int ConsultaObtemCirurgiaLesaoI(tConsulta* cons, int ind);
/**
 * Retorna se a lesao de indice "ind" na consulta foi encaminhada pra crioterapia
*/
int ConsultaObtemCrioterapiaLesaoI(tConsulta* cons, int ind);

/**
 * Imprime menu da consulta e executa as operacoes com base na operacao escolhida e lida na entrada padrao
*/
void MenuDaConsulta(tConsulta* cons, tFila* fila);

/**
 * Salva as consultas, e consequentemente as lesoes, no binario
*/
void ConsultaSalvaBinario(tConsulta** cons, int qtd, char* path);
/**
 * Recupera as consultas, e consequentemente as lesoes, do binario
*/
void ConsultaRecuperaBinario(tConsulta*** cons, char* path, int* qtd);

/**
 * Le cpf do paciente que sera consultado, 
 * analise se ele esta cadastrado no sistema, 
 * cria uma nova consulta, 
 * le suas informacoes,
 * incrementa o numero de consultas de um paciente,
 * chama a funcao "MenuDaConsulta" para realizar possiveis operacoes
*/
void RealizaConsultas(int nPacientes, tPaciente** pacientes, int* nConsultas, tConsulta*** consultas, tFila* filaImpressao, int tipo, int idLogin, tMedico** medicos);

#endif