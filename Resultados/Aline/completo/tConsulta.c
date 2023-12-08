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
    if(consulta != NULL){
        if(consulta->lesoes != NULL){
            for(int i=0; i<consulta->qtdLesoes; i++){
                desalocaLesao(consulta->lesoes[i]);
            }
            free(consulta->lesoes);
        }
        free(consulta);
    }
}

void LeConsulta(tConsulta* cons){
    printf("DATA DA CONSULTA: ");
    scanf("%[^\n]%*c", cons->data);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &cons->diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", &cons->fumante);
    printf("ALERGIA A MEDICAMENTO: ");
    scanf("%d%*c", &cons->alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &cons->cancer);
    printf("TIPO DE PELE: \n");
    scanf("%[^\n]%*c", cons->pele);
}

void ConsultaCadastraLesao(tConsulta* cons){
    char diagnostico[30], regiao[20], rotulo[6];
    int tamanho, cirurgia, crioterapia;
    (cons->qtdLesoes)++;

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]%*c", diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]%*c", regiao);
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
    int qtd = 0;
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
    if(strcmp(uso, "ORAL") == 0){
        tpuso = 0;
    }
    else{
        tpuso = 1;
    }

    tReceita* receita = criaReceita(cons->nomePaciente, tpuso, medicamento, tipomed, intrucoes, qtd, ObtemNomeMedico(cons->medico), ObtemCRMMedico(cons->medico), cons->data);
    insereDocumentoFila(fila, receita, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);

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
    insereDocumentoFila(fila, enc, imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);

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
        insereDocumentoFila(fila, bio, imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);
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

void MenuDaConsulta(tConsulta* cons, tFila* fila){
    int op = 0;

    while(1){
        printf("#################### CONSULTA MEDICA #######################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) CADASTRAR LESAO\n");
        printf("\t(2) GERAR RECEITA MEDICA\n");
        printf("\t(3) SOLICITACAO DE BIOPSIA\n");
        printf("\t(4) ENCAMINHAMENTO\n");
        printf("\t(5) ENCERRAR CONSULTA\n");
        printf("############################################################\n");

        scanf("%d%*c", &op);
        if(op == 1){
            ConsultaCadastraLesao(cons);
        }
        else if(op == 2){
            ConsultaGerarReceita(cons, fila);
        }
        else if(op == 3){
            ConsultaBiopsia(cons, fila);
        }
        else if(op == 4){
            ConsultaEncaminhamento(cons, fila);
        }
        else if(op == 5){
            break;
        }
    }
}