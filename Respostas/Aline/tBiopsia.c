#include "tBiopsia.h"
#include "tLesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tBiopsia
{
    char nomePaciente[100];
    char cpfPaciente[15];
    tLesao** lesoes;
    int qtdLesoes;
    char nomeMedico[100];
    char CRM[12];
    char dataStr[11];
};

tBiopsia* CriaBiopsia(char* nomePaciente, char* cpfPaciente, tLesao** lesoes, int qtdLesoes, char* nomeMedico, char* CRM, char* data){
    tBiopsia* biop = malloc(sizeof(tBiopsia));
    strcpy(biop->nomePaciente, nomePaciente);
    strcpy(biop->cpfPaciente, cpfPaciente);
    strcpy(biop->nomeMedico, nomeMedico);
    strcpy(biop->CRM, CRM);
    strcpy(biop->dataStr, data);
    biop->qtdLesoes = qtdLesoes;
    biop->lesoes = lesoes;

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
    for(int i=0; i<biop->qtdLesoes; i++){
        char* rotulo = ObtemRotuloLesao(biop->lesoes[i]);
        char* diagnostico = ObtemDiagnosticoLesao(biop->lesoes[i]);
        char* regiao = ObtemRegiaoLesao(biop->lesoes[i]);
        int tam = ObtemTamanhoLesao(biop->lesoes[i]);
        if(ObtemCirurgiaLesao(biop->lesoes[i])){
            printf("%s - %s - %s - %dMM\n", rotulo, diagnostico, regiao, tam);
        }
    }
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
    for(int i=0; i<biop->qtdLesoes; i++){
        char* rotulo = ObtemRotuloLesao(biop->lesoes[i]);
        char* diagnostico = ObtemDiagnosticoLesao(biop->lesoes[i]);
        char* regiao = ObtemRegiaoLesao(biop->lesoes[i]);
        int tam = ObtemTamanhoLesao(biop->lesoes[i]);
        if(ObtemCirurgiaLesao(biop->lesoes[i])){
            fprintf(pBiopsia, "%s - %s - %s - %dMM\n", rotulo, diagnostico, regiao, tam);
        }
    }
    fprintf(pBiopsia, "\n");

    fprintf(pBiopsia, "%s (%s)\n", biop->nomeMedico, biop->CRM);
    fprintf(pBiopsia ,"%s\n", biop->dataStr);

    fclose(pBiopsia);
}