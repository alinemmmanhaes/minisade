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