#include "tConsulta.h"
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
    printf("TIPO DE PELE: \n");
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
    printf("ENVIAR PARA CRIOTERAPIA: \n");
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

void ConsultaGerarReceita(tConsulta* cons, tFila* fila){
    char uso[7], medicamento[50], tipomed[50], intrucoes[300];
    int qtd;
    eTipoUso tpuso;

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("RECEITA MEDICA:\n");
    printf("TIPO DE USO: ");
    scanf("%[^\n]%*c", uso);
    printf("NOME DO MEDICAMENTO: ");
    scanf("%[^\n]%*c", medicamento);
    printf("TIPO DE MEDICAMENTO: ");
    scanf("%[^\n]%*c", tipomed);
    printf("QUANTIDADE: ");
    scanf("%d%*c", &qtd);
    printf("INSTRUCOES DE USO: \n");
    scanf("%[^\n]%*c", intrucoes);
    if(uso == "ORAL"){
        tpuso = 0;
    }
    else if(uso == "TOPICO"){
        tpuso = 1;
    }

    tReceita* receita = criaReceita(cons->nomePaciente, tpuso, medicamento, tipomed, intrucoes, qtd, ObtemNomeMedico(cons->medico), ObtemCRMMedico(cons->medico), cons->data);
    tDocumento* doc = criaDocumento(receita, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
    insereDocumentoFila(fila, doc, imprimeNaTelaDocumento, imprimeEmArquivoDocumento, desalocaDocumento);

    printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    char c;
    scanf("%c%*c", &c);
    printf("############################################################\n");
}

void ConsultaEncaminhamento(tConsulta* cons, tFila* fila){
    printf("#################### CONSULTA MEDICA #######################\n");

    char esp[50], mot[300];
    printf("ENCAMINHAMENTO:\n");
    printf("ESPECIALIDADE ENCAMINHADA: ");
    scanf("%[^\n]%*c", esp);
    printf("MOTIVO: \n");
    scanf("%[^\n]%*c", mot);
    tEncaminhamento* enc = CriaEncaminhamento(cons->nomePaciente, cons->cpfPaciente, esp, mot, ObtemNomeMedico(cons->medico), ObtemCRMMedico(cons->medico), cons->data);
    tDocumento* doc = criaDocumento(enc, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
    insereDocumentoFila(fila, doc, imprimeNaTelaDocumento, imprimeEmArquivoDocumento, desalocaDocumento);

    printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    char c;
    scanf("%c%*c", &c);
    printf("############################################################\n");
}

void ConsultaBiopsia(tConsulta* cons, tFila* fila){
    int flag = 0;
    printf("#################### CONSULTA MEDICA #######################\n");

    for(int i=0; i<cons->qtdLesoes; i++){
        if(ObtemCirurgiaLesao(cons->lesoes[i])){
            flag = 1;
        }
    }

    if(flag){
        tBiopsia* bio = CriaBiopsia(cons->nomePaciente, cons->cpfPaciente, cons->lesoes, cons->qtdLesoes, ObtemNomeMedico(cons->medico), ObtemCRMMedico(cons->medico), cons->data);
        tDocumento* doc = criaDocumento(bio, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
        insereDocumentoFila(fila, doc, imprimeNaTelaDocumento, imprimeEmArquivoDocumento, desalocaDocumento);
        printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. ");
    }
    else{
        printf("NAO FOI POSSIVEL GERAR A BIOPSIA. ");
    }
    
    printf("PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    char c;
    scanf("%c%*c", &c);
    printf("############################################################\n");
}

int ObtemQtdLesoesConsulta(tConsulta* cons){
    return cons->qtdLesoes;
}

int ConsultaObtemTamLesaoI(tConsulta* cons, int ind){
    return ObtemTamanhoLesao(cons->lesoes[ind]);
}

int ConsultaObtemCirurgiaLesaoI(tConsulta* cons, int ind){
    return ObtemCirurgiaLesao(cons->lesoes[ind]);
}

int ConsultaObtemCrioterapiaLesaoI(tConsulta* cons, int ind){
    ObtemCrioterapiaLesao(cons->lesoes[ind]);
}