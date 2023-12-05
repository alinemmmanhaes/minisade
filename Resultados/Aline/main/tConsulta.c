#include "tConsulta.h"
#include "tLesao.h"
#include "tMedico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tConsulta
{
    tMedico* medico;
    tLesao** lesoes;
    int qtdLesoes;
    char data[11];
    char nomePaciente[100];
    char cpfPaciente[15];
    int diabetes;
    int fumante;
    int alergia;
    int cancer;
    char pele[4];
};

tConsulta* CriaConsulta(tMedico* medico, char* cpfPaciente, char* nomePaciente){
    tConsulta* cons = malloc(sizeof(tConsulta));
    cons->medico = medico;
    cons->lesoes = NULL;
    cons->qtdLesoes = 0;
    strcpy(cons->cpfPaciente, cpfPaciente);
    strcpy(cons->nomePaciente, nomePaciente);
    return cons;
}

void desalocaConsulta(tConsulta* consulta){
    for(int i=0; i<consulta->qtdLesoes; i++){
        desalocaLesao(consulta->lesoes[i]);
    }
    free(consulta->lesoes);
    free(consulta);
}

void LeConsulta(tConsulta* cons){
    printf("DATA DA CONSULTA: ");
    scanf("%s", cons->data);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &cons->diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", &cons->fumante);
    printf("ALERGIA A MEDICAMENTO: ");
    scanf("%d%*c", &cons->alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &cons->cancer);
    printf("TIPO DE PELE: ");
    scanf("%s", cons->pele);
}