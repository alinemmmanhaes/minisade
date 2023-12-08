#include "tSecretario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tSecretario
{
    char nome[100];
    char cpf[15];
    char nasc[11];
    char tel[15];
    char genero[10];
    char user[20];
    char senha[20];
    char tipo[6];
};

tSecretario* CriaSecretario(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* user, char* senha, char* nivel){
    tSecretario* sec = calloc(1, sizeof(tSecretario));
    strcpy(sec->nome, nome);
    strcpy(sec->cpf, cpf);
    strcpy(sec->nasc, nasc);
    strcpy(sec->tel, tel);
    strcpy(sec->genero, genero);
    strcpy(sec->user, user);
    strcpy(sec->senha, senha);
    strcpy(sec->tipo, nivel);

    return sec;
}

void DesalocaSecretario(tSecretario* sec){
    if(sec != NULL){
        free(sec);
    }
}

char* ObtemNomeSecretario(tSecretario* sec){
    char* nome = sec->nome;
    return nome;
}

int ObtemTipoSecretario(tSecretario* sec){
    if(strcmp(sec->tipo, "ADMIN") == 0){
        return 1;
    }
    return 2;
}

int SecComparaCPF(tSecretario* sec, char* cpf){
    int resp = strcmp(sec->cpf, cpf);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int SecComparaUser(tSecretario* sec, char* user){
    int resp = strcmp(sec->user, user);
    if(resp == 0){
        return 1;
    }
    return 0;
}

int SecComparaSenha(tSecretario* sec, char* senha){
    int resp = strcmp(sec->senha, senha);
    if(resp == 0){
        return 1;
    }
    return 0;
}

void SecretarioSalvaBinario(tSecretario** sec, int qtd, char* path){
    char diretorio[1000];
    sprintf(diretorio, "%s/secretarios.bin", path);
    FILE* arq = fopen(diretorio, "wb");

    fwrite(&qtd, sizeof(int), 1, arq);

    for(int i=0; i<qtd; i++){
        fwrite(sec[i], sizeof(tSecretario), 1, arq);
    }

    fclose(arq);
}

int SecretarioRecuperaBinario(tSecretario** sec, FILE* arq){
    int qtd;

    fread(&qtd, sizeof(int), 1, arq);
    sec = realloc(sec, qtd*sizeof(tSecretario*));
    
    for(int i=0; i<qtd; i++){
        tSecretario* secretario = malloc(sizeof(tSecretario));
        fread(secretario, sizeof(tSecretario), 1, arq);
        sec[i] = secretario;
    }

    fclose(arq);
    return qtd;
}