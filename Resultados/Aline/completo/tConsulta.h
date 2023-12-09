#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#include <stdio.h>
#include "tLesao.h"
#include "tMedico.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tDocumento.h"
#include "tFila.h"

typedef struct tConsulta tConsulta;

tConsulta* CriaConsulta(tMedico* medico, char* cpfPaciente, char* nomePaciente);

void desalocaConsulta(tConsulta* consulta);

void LeConsulta(tConsulta* cons);

void ConsultaCadastraLesao(tConsulta* cons);
void ConsultaGerarReceita(tConsulta* cons, tFila* fila);
void ConsultaEncaminhamento(tConsulta* cons, tFila* fila);
void ConsultaBiopsia(tConsulta* cons, tFila* fila);

int ObtemQtdLesoesConsulta(tConsulta* cons);
int ConsultaObtemTamLesaoI(tConsulta* cons, int ind);
int ConsultaObtemCirurgiaLesaoI(tConsulta* cons, int ind);
int ConsultaObtemCrioterapiaLesaoI(tConsulta* cons, int ind);

void MenuDaConsulta(tConsulta* cons, tFila* fila);

void ConsultaSalvaBinario(tConsulta** cons, int qtd, char* path);
tConsulta** ConsultaRecuperaBinario(tConsulta** cons, char* path, int* qtd);

#endif