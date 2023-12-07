#include "tEncaminhamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tEncaminhamento
{
    char nomePaciente[100];
    char cpfPaciente[15];
    char especialidade[MAX_TAM_ESPECIALIDADE];
    char motivo[MAX_TAM_MOTIVO];
    char nomeMedico[100];
    char CRM[12];
    char dataStr[11];
};

tEncaminhamento* CriaEncaminhamento(char* nomePaciente, char* cpfPaciente, char* especialidade, char* motivo, char* nomeMedico, char* CRM, char* data){
    tEncaminhamento* enc = malloc(sizeof(tEncaminhamento));
    strcpy(enc->nomePaciente, nomePaciente);
    strcpy(enc->cpfPaciente, cpfPaciente);
    strcpy(enc->especialidade, especialidade);
    strcpy(enc->motivo, motivo);
    strcpy(enc->nomeMedico, nomeMedico);
    strcpy(enc->CRM, CRM);
    strcpy(enc->dataStr, data);
    return enc;
}

void desalocaEncaminhamento(void *dado){
    tEncaminhamento* enc = (tEncaminhamento*) dado;
    if(enc != NULL){
        free(enc);
    }
}

void imprimeNaTelaEncaminhamento(void *dado){
    tEncaminhamento* enc = (tEncaminhamento*) dado;
    printf("PACIENTE: %s\n", enc->nomePaciente);
    printf("CPF: %s\n\n", enc->cpfPaciente);
    printf("ESPECIALIDADE ENCAMINHADA: %s\n\n", enc->especialidade);
    printf("MOTIVO: %s\n\n", enc->motivo);
    printf("%s (%s)\n", enc->nomeMedico, enc->CRM);
    printf("%s\n\n", enc->dataStr);
}

void imprimeEmArquivoEncaminhamento(void *dado, char *path){
    tEncaminhamento* enc = (tEncaminhamento*) dado;
    FILE * pEncaminhamento;
    char direncaminhamento[1000];

    sprintf(direncaminhamento, "%s/encaminhamento.txt", path);
    pEncaminhamento = fopen(direncaminhamento, "a");

    fprintf(pEncaminhamento, "PACIENTE: %s\n", enc->nomePaciente);
    fprintf(pEncaminhamento, "CPF: %s\n\n", enc->cpfPaciente);
    fprintf(pEncaminhamento, "ESPECIALIDADE ENCAMINHADA: %s\n\n", enc->especialidade);
    fprintf(pEncaminhamento, "MOTIVO: %s\n\n", enc->motivo);
    fprintf(pEncaminhamento, "%s (%s)\n", enc->nomeMedico, enc->CRM);
    fprintf(pEncaminhamento, "%s\n\n", enc->dataStr);

    fclose(pEncaminhamento);
}