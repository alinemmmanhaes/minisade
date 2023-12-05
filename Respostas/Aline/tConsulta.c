#include "tConsulta.h"
#include "tLesao.h"
#include "tMedico.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tDocumento.h"
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

void ConsultaCadastraLesao(tConsulta* cons){
    char diagnostico[30], regiao[20], rotulo[6];
    int tamanho, cirurgia, crioterapia;
    (cons->qtdLesoes)++;

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]\n", diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]\n", regiao);
    printf("TAMANHO: ");
    scanf("%d%*c", &tamanho);
    printf("ENVIAR PARA CIRURGIA: ");
    scanf("%d%*c", &cirurgia);
    printf("ENVIAR PARA CRIOTERAPIA: ");
    scanf("%d%*c", &crioterapia);

    sprintf(rotulo, "L%d", cons->qtdLesoes);
    tLesao* les = CriaLesao(rotulo, diagnostico, regiao, tamanho, cirurgia, crioterapia);
    cons->lesoes = realloc(cons->lesoes, (cons->qtdLesoes)*sizeof(tLesao*));
    cons->lesoes[cons->qtdLesoes - 1] = les;
    printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");

    char c;
    scanf("%c%*c", &c);
    printf("############################################################\n");
}

void ConsultaGerarReceita(tConsulta* cons, tDocumento** docs, int qtddocs){
    char uso[7], medicamento[50], tipomed[50], intrucoes[300];
    int qtd;

    printf("TIPO DE USO: ");
    printf("%[^\n]%*c", uso);
    printf("NOME DO MEDICAMENTO: ");
    printf("%[^\n]%*c", medicamento);
    printf("TIPO DE MEDICAMENTO: ");
    printf("%[^\n]%*c", tipomed);
    printf("QUANTIDADE: ");
    printf("%d%*c", &qtd);
    printf("INSTRUCOES DE USO: ");
    printf("%[^\n]%*c", intrucoes);

    tReceita* receita = criaReceita(cons->nomePaciente, uso, medicamento, tipomed, intrucoes, qtd, ObtemNomeMedico(cons->medico), ObtemCRMMedico(cons->medico), cons->data);
    
}

void ConsultaEncaminhamento(tConsulta* cons);

void ConsultaBiopsia(tConsulta* cons);