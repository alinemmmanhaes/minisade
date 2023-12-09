#include "tConsulta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tConsulta
{
    char nomeMedico[100];
    char CRM[12];
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
    tConsulta* cons = calloc(1, sizeof(tConsulta));
    cons->lesoes = NULL;
    cons->qtdLesoes = 0;
    strcpy(cons->cpfPaciente, cpfPaciente);
    strcpy(cons->nomePaciente, nomePaciente);
    strcpy(cons->nomeMedico, ObtemNomeMedico(medico));
    strcpy(cons->CRM, ObtemCRMMedico(medico));
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
    int dia, mes, ano;
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

    sscanf(cons->data, "%d/%d/%d", &dia, &mes, &ano);
    sprintf(cons->data, "%d/%d/%d", dia, mes, ano);
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

    tReceita* receita = criaReceita(cons->nomePaciente, tpuso, medicamento, tipomed, intrucoes, qtd, cons->nomeMedico, cons->CRM, cons->data);
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
    tEncaminhamento* enc = CriaEncaminhamento(cons->nomePaciente, cons->cpfPaciente, esp, mot, cons->nomeMedico, cons->CRM, cons->data);
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
        tBiopsia* bio = CriaBiopsia(cons->nomePaciente, cons->cpfPaciente, cons->lesoes, cons->qtdLesoes, cons->nomeMedico, cons->CRM, cons->data);
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
    return ObtemCrioterapiaLesao(cons->lesoes[ind]);
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

void ConsultaSalvaBinario(tConsulta** cons, int qtd, char* path){
    char diretorio[1000];
    char dirlesao[1000];
    sprintf(diretorio, "%s/consultas.bin", path);
    sprintf(dirlesao, "%s/lesoes.bin", path);
    FILE* arq = fopen(diretorio, "wb");
    FILE* arqLesao = fopen(dirlesao, "wb");

    fwrite(&qtd, sizeof(int), 1, arq);

    for(int i=0; i<qtd; i++){
        fwrite(cons[i], sizeof(tConsulta), 1, arq);
        LesaoSalvaBinario(cons[i]->lesoes, cons[i]->qtdLesoes, arqLesao);
    }

    fclose(arq);
    fclose(arqLesao);
}

tConsulta** ConsultaRecuperaBinario(tConsulta** cons, char* path, int* qtd){
    char diretorio[1000], dirlesao[1000];
    sprintf(diretorio, "%s/consultas.bin", path);
    FILE* arq = fopen(diretorio, "rb");
    if(arq == NULL){
        return NULL;
    }
    sprintf(dirlesao, "%s/lesoes.bin", path);
    FILE* arqLesao = fopen(dirlesao, "rb");

    fread(qtd, sizeof(int), 1, arq);
    cons = realloc(cons, (*qtd)*sizeof(tConsulta*));
    
    for(int i=0; i<(*qtd); i++){
        tConsulta* consulta = malloc(sizeof(tConsulta));
        fread(consulta, sizeof(tConsulta), 1, arq);
        consulta->lesoes = NULL;
        consulta->lesoes = LesaoRecuperaBinario(consulta->lesoes, arqLesao, consulta->qtdLesoes);
        cons[i] = consulta;
    }

    fclose(arq);
    fclose(arqLesao);
    return cons;
}