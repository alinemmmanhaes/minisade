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
    TypeSec tipo;
};

tSecretario* CriaSecretario(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* user, char* senha, char* nivel){
    tSecretario* sec = malloc(sizeof(tSecretario));
    strcpy(sec->nome, nome);
    strcpy(sec->cpf, cpf);
    strcpy(sec->nasc, nasc);
    strcpy(sec->tel, tel);
    strcpy(sec->genero, genero);
    strcpy(sec->user, user);
    strcpy(sec->senha, senha);
    if(nivel == "ADMIN"){
        sec->tipo = ADMIN;
    }
    else if(nivel == "USER"){
        sec->tipo = USER;
    }
    return sec;
}

void DesalocaSecretario(tSecretario* sec){
    if(sec != NULL){
        free(sec);
    }
}

TypeSec ObtemTipoSecretario(tSecretario* sec){
    return sec->tipo;
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