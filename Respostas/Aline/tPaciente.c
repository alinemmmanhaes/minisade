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
    int idade;
    int nConsultas;
};

int CalculaIdade(int dia, int mes, int ano){
    if(mes< 11){
        return 2023-ano;
    }
    else if(mes == 11){
        if(dia <= 9){
            return 2023-ano;
        }
    }
    return 2022-ano;
}

tPaciente* CriaPaciente(char* nome, char* cpf, int dia, int mes, int ano, char* tel, char* genero){
    tPaciente* pac = malloc(sizeof(tPaciente));
    strcpy(pac->nome, nome);
    strcpy(pac->cpf, cpf);
    strcpy(pac->tel, tel);
    strcpy(pac->genero, genero);
    sprintf(pac->nasc, "%d/%d/%d", dia, mes, ano); //%02d?
    pac->idade = CalculaIdade(dia, mes, ano);
    pac->nConsultas = 0;
    return pac;
}

void DesalocaPaciente(tPaciente* pac){
    if(pac != NULL){
        free(pac);
    }
}

char* ObtemNomePaciente(tPaciente* pac){
    return (pac->nome);
}

char* ObtemCPFPaciente(tPaciente* pac){
    return (pac->cpf);
}

char* ObtemSexoPaciente(tPaciente* pac){
    return (pac->genero);
}

char* ObtemDataNascPaciente(tPaciente* pac){
    return (pac->nasc);
}

int ObtemNumeroAtendimentosPaciente(tPaciente* pac){
    return pac->nConsultas;
}

int ObtemIdadePaciente(tPaciente* pac){
    return pac->idade;
}

int PacComparaCPF(tPaciente* pac, char* cpf){
    int resp = strcmp(pac->cpf, cpf);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int PacComparaNome(tPaciente* pac, char* nome){
    int resp = strcmp(pac->nome, nome);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int PacIncrementaConsultas(tPaciente* pac){
    (pac->nConsultas)++;
}