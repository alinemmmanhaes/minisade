#include "tPaciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tPaciente
{
    char nome[100];
    char cpf[15];
    char nasc[11];
    char tel[15];
    char genero[10];
};

tPaciente* CriaPaciente(char* nome, char* cpf, char* nasc, char* tel, char* genero){
    tPaciente* pac = malloc(sizeof(tPaciente));
    strcpy(pac->nome, nome);
    strcpy(pac->cpf, cpf);
    strcpy(pac->nasc, nasc);
    strcpy(pac->tel, tel);
    strcpy(pac->genero, genero);
    return pac;
}

void DesalocaPaciente(tPaciente* pac){
    if(pac != NULL){
        free(pac);
    }
}

char* ObtemNomePaciente(tPaciente* pac){
    return pac->nome;
}

char* ObtemCPFPaciente(tPaciente* pac){
    return pac->cpf;
}

int PacComparaCPF(tPaciente* pac, char* cpf){
    int resp = strcmp(pac->cpf, cpf);
    if(resp == 0){
        return 1;
    }
    return 0;
}