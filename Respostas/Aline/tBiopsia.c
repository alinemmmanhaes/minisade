#include "tBiopsia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tBiopsia
{
    char nomePaciente[100];
    char cpfPaciente[15];
    char rotulo[5];
    char diagnostico[100];
    char regiao[15];
    int tamanho;
    char nomeMedico[100];
    char CRM[12];
    char dataStr[11];
};

tBiopsia* CriaBiopsia(char* nomePaciente, char* cpfPaciente, char* rotulo, char* diagnostico, char* regiao, int tamanho, char* nomeMedico, char* CRM, char* data){
    tBiopsia* biop = malloc(sizeof(tBiopsia));
    strcpy(biop->nomePaciente, nomePaciente);
    strcpy(biop->cpfPaciente, cpfPaciente);
    strcpy(biop->rotulo, rotulo);
    strcpy(biop->diagnostico, diagnostico);
    strcpy(biop->regiao, regiao);
    strcpy(biop->nomeMedico, nomeMedico);
    strcpy(biop->CRM, CRM);
    strcpy(biop->dataStr, data);
    biop->tamanho = tamanho;

    //CHECAR SE AO MENOS UMA DAS LESOES FOI ENVIADA PARA CIRURGIA ANTES DE CRIAR O DOCUMENTO

    return biop;
}

void desalocaBiopsia(void *dado){
    tBiopsia* biop = (tBiopsia*) dado;
    if(biop != NULL){
        free(biop);
    }
}

void imprimeNaTelaBiopsia(void *dado){
    tBiopsia* biop = (tBiopsia*) dado;
    printf("PACIENTE: %s\n", biop->nomePaciente);
    printf("CPF: %s\n\n", biop->cpfPaciente);
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    printf("%s - %s - %s - %d\n", biop->rotulo, biop->diagnostico, biop->regiao, biop->tamanho);
    printf("\n");
    printf("%s (%s)\n", biop->nomeMedico, biop->CRM);
    printf("%s\n", biop->dataStr);
}

void imprimeEmArquivoBiopsia(void *dado, char *path){
    tBiopsia* biop = (tBiopsia*) dado;
    FILE * pBiopsia;
    char dirbiopsia[1000];

    sprintf(dirbiopsia, "%s/biopsia.txt", path);
    pBiopsia = fopen(dirbiopsia, "a");

    fprintf(pBiopsia, "PACIENTE: %s\n", biop->nomePaciente);
    fprintf(pBiopsia, "CPF: %s\n\n", biop->cpfPaciente);
    fprintf(pBiopsia, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    fprintf(pBiopsia, "%s - %s - %s - %d\n", biop->rotulo, biop->diagnostico, biop->regiao, biop->tamanho);
    fprintf(pBiopsia, "\n");
    fprintf(pBiopsia, "%s (%s)\n", biop->nomeMedico, biop->CRM);
    fprintf(pBiopsia ,"%s\n", biop->dataStr);

    fclose(pBiopsia);
}