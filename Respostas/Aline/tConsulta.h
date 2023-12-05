#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

typedef struct tConsulta tConsulta;

tConsulta* CriaConsulta(tMedico* medico, char* cpfPaciente, char* nomePaciente);

void desalocaConsulta(tConsulta* consulta);

void LeConsulta(tConsulta* cons);

#endif