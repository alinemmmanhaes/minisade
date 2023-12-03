#include "tReceita.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tReceita
{
    char nomePaciente[100];
    eTipoUso tipoUso;
    char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    char instrucoes[MAX_TAM_INSTRUCOES];
    int qtd;
    char nomeMedico[100];
    char CRM[12];
    char dataStr[11];
};

tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr){
                        tReceita* receita = malloc(sizeof(tReceita));

                        strcpy(receita->nomePaciente, nomePaciente);
                        strcpy(receita->nomeMedicamento, nomeMedicamento);
                        strcpy(receita->tipoMedicamento, tipoMedicamento);
                        strcpy(receita->instrucoes, instrucoes);
                        strcpy(receita->nomeMedico, nomeMedico);
                        strcpy(receita->CRM, CRM);
                        strcpy(receita->dataStr, dataStr);
                        receita->tipoUso = tipoUso;
                        receita->qtd = qntd;

                        return receita;
                      }

void desalocaReceita(void *dado){
    tReceita* rec = (tReceita*) dado;
    if(rec != NULL){
        free(rec);
    }
}

void imprimeNaTelaReceita(void *dado){
    tReceita* receita = (tReceita*)dado;

    char uso[7];
    if(receita->tipoUso == 0){
        strcpy(uso, "ORAL");
    }
    else if(receita->tipoUso == 1){
        strcpy(uso, "TOPICO");
    }

    printf("RECEITUARIO\n");
    printf("NOME: %s\n\n", (receita->nomePaciente));
    printf("USO %s\n\n", uso);
    printf("%s\n%d %s\n\n", receita->nomeMedicamento, receita->qtd, receita->tipoMedicamento);
    printf("%s\n\n", receita->instrucoes);
    printf("%s (%s)\n", receita->nomeMedico, receita->CRM);
    printf("%s\n", receita->dataStr);
}

void imprimeEmArquivoReceita(void *dado, char *path){
    tReceita* receita = (tReceita*)dado;
    FILE * pReceita;
    char direceita[1000];

    sprintf(direceita, "%s/receita.txt", path);
    pReceita = fopen(direceita, "a");

    char uso[7];
    if(receita->tipoUso == 0){
        strcpy(uso, "ORAL");
    }
    else if(receita->tipoUso == 1){
        strcpy(uso, "TOPICO");
    }

    fprintf(pReceita, "RECEITUARIO\n");
    fprintf(pReceita, "NOME: %s\n\n", (receita->nomePaciente));
    fprintf(pReceita,"USO %s\n\n", uso);
    fprintf(pReceita, "%s\n%d %s\n\n", receita->nomeMedicamento, receita->qtd, receita->tipoMedicamento);
    fprintf(pReceita, "%s\n\n", receita->instrucoes);
    fprintf(pReceita, "%s (%s)\n", receita->nomeMedico, receita->CRM);
    fprintf(pReceita, "%s\n\n", receita->dataStr);

    fclose(pReceita);
}