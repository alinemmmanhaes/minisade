#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

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
void ConsultaEncaminhamento(tConsulta* cons);
void ConsultaBiopsia(tConsulta* cons);

#endif