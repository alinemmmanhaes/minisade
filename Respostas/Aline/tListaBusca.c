#include "tListaBusca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tListaBusca
{
    tPaciente** pacientes;
    int qtd;
};


tListaBusca* CriaListaBusca(){
    tListaBusca* lista = malloc(sizeof(tListaBusca));
    lista->qtd = 0;
    lista->pacientes = NULL;
    return lista;
}

void AdicionaPacienteListaBusca(tListaBusca* lista, tPaciente* paciente){
    (lista->qtd)++;
    lista->pacientes = realloc(lista->pacientes, (lista->qtd)*sizeof(tPaciente*));
    lista->pacientes[lista->qtd - 1] = paciente;
}

void DesalocaListaBusca(void* dado){
    tListaBusca* lista = (tListaBusca*) dado;
    if(lista != NULL){
        if(lista->pacientes != NULL){
            free(lista->pacientes);
        }
        free(lista);
    }
}

void imprimeNaTelaListaBusca(void *dado){
    tListaBusca* lista = (tListaBusca*) dado;
    for(int i=0; i<lista->qtd; i++){
        printf("%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->pacientes[i]), ObtemCPFPaciente(lista->pacientes[i]));
    }
    printf("\n");
}

void imprimeEmArquivoListaBusca(void *dado, char *path){
    tListaBusca* lista = (tListaBusca*) dado;
    FILE * pLista;
    char dirlista[1000];

    sprintf(dirlista, "%s/lista_busca.txt", path);
    pLista = fopen(dirlista, "a");

    for(int i=0; i<lista->qtd; i++){
        fprintf(pLista, "%d - %s (%s)\n", i+1, ObtemNomePaciente(lista->pacientes[i]), ObtemCPFPaciente(lista->pacientes[i]));
    }
    fprintf(pLista, "\n");

    fclose(pLista);
}

void RealizaBusca(int nPacientes, tPaciente** pacientes, int* nListaBusca, tListaBusca*** listasbusca, tFila* filaImpressao){
    char nome[100];
    int total = 0;
    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("NOME DO PACIENTE: ");
    scanf("%[^\n]%*c", nome);
    for(int i=0; i<nPacientes; i++){
        tPaciente* p = pacientes[i];
        if(PacComparaNome(p, nome) == 1){
            total = 1;
        }
    }

    if(total == 0){
        printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
        char c;
        scanf("%c%*c", &c);

    }
    else{
        (*nListaBusca)++;
        (*listasbusca) = realloc((*listasbusca), *nListaBusca*sizeof(tListaBusca*));
        (*listasbusca)[*nListaBusca - 1] = CriaListaBusca();
        for(int i=0; i<nPacientes; i++){
            tPaciente* p = pacientes[i];
            if(PacComparaNome(p, nome)){
                AdicionaPacienteListaBusca((*listasbusca)[*nListaBusca - 1], p);
            }
        }

        printf("PACIENTES ENCONTRADOS:\n");
        imprimeNaTelaListaBusca((*listasbusca)[*nListaBusca - 1]);

        printf("#################### BUSCAR PACIENTES #######################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
        printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
        printf("###############################################################\n\n");
        int num = 0;
        scanf("%d%*c", &num);
        if(num == 1){
            insereDocumentoFila(filaImpressao, (*listasbusca)[*nListaBusca - 1], imprimeNaTelaListaBusca, imprimeEmArquivoListaBusca, DesalocaListaBusca);
            printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
            char c;
            scanf("%c%*c", &c);
        }
    }
    printf("###############################################################\n");
}