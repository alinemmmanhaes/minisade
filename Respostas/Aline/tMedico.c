#include "tMedico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tMedico
{
    char nome[100];
    char cpf[15];
    char nasc[11];
    char tel[15];
    char genero[10];
    char user[20];
    char senha[20];
    char crm[12];
};

tMedico* CriaMedico(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* crm, char* user, char* senha){
    tMedico* medico = calloc(1, sizeof(tMedico));
    strcpy(medico->nome, nome);
    strcpy(medico->cpf, cpf);
    strcpy(medico->nasc, nasc);
    strcpy(medico->tel, tel);
    strcpy(medico->genero, genero);
    strcpy(medico->crm, crm);
    strcpy(medico->user, user);
    strcpy(medico->senha, senha);
    return medico;
}

void DesalocaMedico(tMedico* med){
    if(med != NULL){
        free(med);
    }
}

char* ObtemNomeMedico(tMedico* med){
    if(med == NULL){
        return "\0";
    }
    char* nome = med->nome;
    return nome;
}

char* ObtemCRMMedico(tMedico* med){
    if(med == NULL){
        return "\0";
    }
    char* crm = med->crm;
    return crm;
}

char* ObtemCPFMedico(tMedico* med){
    char* cpf = med->cpf;
    return cpf;
}

int MedComparaCPF(tMedico* med, char* cpf){
    int resp = strcmp(med->cpf, cpf);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int MedComparaUser(tMedico* med, char* user){
    int resp = strcmp(med->user, user);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int MedComparaSenha(tMedico* med, char* senha){
    int resp = strcmp(med->senha, senha);
    if(resp == 0){
        return 1;
    }
    return 0;
}

void MedicoSalvaBinario(tMedico** med, int qtd, char* path){
    char diretorio[1000];
    sprintf(diretorio, "%s/medicos.bin", path);
    FILE* arq = fopen(diretorio, "wb");

    fwrite(&qtd, sizeof(int), 1, arq);

    for(int i=0; i<qtd; i++){
        fwrite(med[i], sizeof(tMedico), 1, arq);
    }

    fclose(arq);
}

int MedicoRecuperaBinario(tMedico** med, FILE* arq){
    int qtd;

    fread(&qtd, sizeof(int), 1, arq);
    med = realloc(med, qtd*sizeof(tMedico*));
    
    for(int i=0; i<qtd; i++){
        tMedico* medico = malloc(sizeof(tMedico));
        fread(medico, sizeof(tMedico), 1, arq);
        med[i] = medico;
    }

    fclose(arq);
    return qtd;
}