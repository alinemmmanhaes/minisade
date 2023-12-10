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

void SecretarioRecuperaBinario(tSecretario*** sec, FILE* arq, int* qtd){
    fread(qtd, sizeof(int), 1, arq);
    *sec = realloc(*sec, (*qtd)*sizeof(tSecretario*));
    
    for(int i=0; i<(*qtd); i++){
        tSecretario* secretario = malloc(sizeof(tSecretario));
        fread(secretario, sizeof(tSecretario), 1, arq);
        (*sec)[i] = secretario;
    }

    fclose(arq);
}

void CadastraSecretario(int* nSecretarios, tSecretario*** secretarios){
    char nome[100], cpf[15], nasc[11], tel[15], genero[10], user[20], senha[20], tipo[6];
    int ehigual = 0;

    printf("#################### CADASTRO SECRETARIO #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%[^\n]%*c", nasc);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", tel);
    printf("GENERO: ");
    scanf("%[^\n]%*c", genero);
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", senha);
    printf("NIVEL DE ACESSO: ");
    scanf("%[^\n]%*c", tipo);

    for(int i=0; i<*nSecretarios; i++){
        if(SecComparaCPF((*secretarios)[i], cpf)){
            ehigual = 1;
            printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA\n");
            break;
        }
    }

    if(ehigual == 0){
        (*nSecretarios)++;
        *secretarios = realloc(*secretarios, (*nSecretarios)*sizeof(tSecretario*));
        (*secretarios)[(*nSecretarios)-1] = CriaSecretario(nome, cpf, nasc, tel, genero, user, senha, tipo);
        printf("\nCADASTRO REALIZADO COM SUCESSO. ");
        printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
        char c;
        scanf("%c%*c", &c);
        printf("###############################################################\n");
    }
}