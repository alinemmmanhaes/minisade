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
    tPaciente* pac = calloc(1, sizeof(tPaciente));
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
    char* nome = pac->nome;
    return nome;
}

char* ObtemCPFPaciente(tPaciente* pac){
    char* cpf = pac->cpf;
    return cpf;
}

char* ObtemSexoPaciente(tPaciente* pac){
    char* gen = pac->genero;
    return gen;
}

char* ObtemDataNascPaciente(tPaciente* pac){
    char* nasc = pac->nasc;
    return nasc;
}

int ObtemNumeroAtendimentosPaciente(tPaciente* pac){
    return pac->nConsultas;
}

int ObtemIdadePaciente(tPaciente* pac){
    return pac->idade;
}

int PacComparaCPF(tPaciente* pac, char* cpf){
    if(strcmp(pac->cpf, cpf) == 0){
        return 1;
    }
    return 0;
}

int PacComparaNome(tPaciente* pac, char* nome){
    if(pac == NULL){
        return 0;
    }
    if(strcmp(pac->nome, nome) == 0){
        return 1;
    }
    return 0;
}

int PacIncrementaConsultas(tPaciente* pac){
    (pac->nConsultas)++;
}

void PacienteSalvaBinario(tPaciente** pac, int qtd, char* path){
    char diretorio[1000];
    sprintf(diretorio, "%s/pacientes.bin", path);
    FILE* arq = fopen(diretorio, "wb");

    fwrite(&qtd, sizeof(int), 1, arq);

    for(int i=0; i<qtd; i++){
        fwrite(pac[i], sizeof(tPaciente), 1, arq);
    }

    fclose(arq);
}

tPaciente** PacienteRecuperaBinario(tPaciente** pac, FILE* arq, int* qtd){
    fread(qtd, sizeof(int), 1, arq);
    pac = realloc(pac, (*qtd)*sizeof(tPaciente*));
    
    for(int i=0; i<(*qtd); i++){
        tPaciente* paciente = malloc(sizeof(tPaciente));
        fread(paciente, sizeof(tPaciente), 1, arq);
        pac[i] = paciente;
    }

    fclose(arq);
    return pac;
}