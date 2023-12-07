#include "tRelatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tRelatorio
{
    int total; //pacientes
    int pacAtendidos;
    int mediaIdade;
    int fem;
    int masc;
    int outros;
    int tamLesoes;
    int nLesoes;
    int cirurgia;
    int crioterapia;
};


tRelatorio* CriaRelatorio(){
    tRelatorio* rel = malloc(sizeof(tRelatorio));
    rel->total = 0;
    rel->pacAtendidos = 0;
    rel->mediaIdade = 0;
    rel->fem = 0;
    rel->masc = 0;
    rel->outros = 0;
    rel->tamLesoes = 0;
    rel->nLesoes = 0;
    rel->cirurgia = 0;
    rel->crioterapia = 0;
    return rel;
}

void desalocaRelatorio(void *dado){
    tRelatorio* rel = (tRelatorio*)dado;
    if(rel != NULL){
        free(rel);
    }
}

void imprimeNaTelaRelatorio(void *dado){
    tRelatorio* rel = (tRelatorio*)dado;
    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", rel->pacAtendidos);
    printf("IDADE MEDIA: %d\n", (rel->mediaIdade)/(rel->total));
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %d\n", rel->fem);
    printf("- MASCULINO: %d\n", rel->masc);
    printf("- OUTROS: %d\n", rel->outros);
    printf("TAMANHO MEDIO DAS LESOES: %d\n", (rel->tamLesoes)/(rel->nLesoes));
    printf("NUMERO TOTAL DE LESOES: %d\n", rel->nLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %d\n", rel->cirurgia);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", rel->crioterapia);
}
void imprimeEmArquivoRelatorio(void *dado, char *path){
    tRelatorio* rel = (tRelatorio*)dado;
    char direlatorio[1000];
    FILE* pRelatorio;

    sprintf(direlatorio, "%s/relatorio_geral.txt", path);
    pRelatorio = fopen(direlatorio, "a");

    fprintf(pRelatorio, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", rel->pacAtendidos);
    fprintf(pRelatorio, "IDADE MEDIA: %d\n", (rel->mediaIdade)/(rel->total));
    fprintf(pRelatorio, "DISTRIBUICAO POR GENERO:\n");
    fprintf(pRelatorio, "- FEMININO: %d\n", rel->fem);
    fprintf(pRelatorio, "- MASCULINO: %d\n", rel->masc);
    fprintf(pRelatorio, "- OUTROS: %d\n", rel->outros);
    fprintf(pRelatorio, "TAMANHO MEDIO DAS LESOES: %d\n", (rel->tamLesoes)/(rel->nLesoes));
    fprintf(pRelatorio, "NUMERO TOTAL DE LESOES: %d\n", rel->nLesoes);
    fprintf(pRelatorio, "NUMERO TOTAL DE CIRURGIAS: %d\n", rel->cirurgia);
    fprintf(pRelatorio, "NUMERO TOTAL DE CRIOTERAPIA: %d\n\n", rel->crioterapia);

    fclose(pRelatorio);
}

void CalculaRelatorio(tRelatorio* rel, tPaciente** pacs, int nPacs, tConsulta** cons, int nCons){
    rel->total = nPacs;
    for(int i=0; i<nPacs; i++){
        char* sexo = ObtemSexoPaciente(pacs[i]);
        if(strcmp(sexo, "FEMININO") == 0){
            (rel->fem)++;
        }
        else if(strcmp(sexo, "MASCULINO") == 0){
            (rel->masc)++;
        }
        else if(strcmp(sexo, "OUTROS") == 0){
            (rel->outros)++;
        }

        if(ObtemNumeroAtendimentosPaciente(pacs[i])){
            (rel->pacAtendidos)++;
        }

        (rel->mediaIdade) += ObtemIdadePaciente(pacs[i]);
    }

    for(int i=0; i<nCons; i++){
        rel->nLesoes += ObtemQtdLesoesConsulta(cons[i]);
        for(int j=0; j<ObtemQtdLesoesConsulta(cons[i]); j++){
            (rel->tamLesoes) += ConsultaObtemTamLesaoI(cons[i], j);
            (rel->cirurgia) += ConsultaObtemCirurgiaLesaoI(cons[i], j);
            (rel->crioterapia) += ConsultaObtemCrioterapiaLesaoI(cons[i], j);
        }
    }
}