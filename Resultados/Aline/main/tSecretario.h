#ifndef _TSECRETARIO_H_
#define _TSECRETARIO_H_

#include <stdio.h>

typedef enum {
    ADMIN = 1,
    USER = 2
} TypeSec;

typedef struct tSecretario tSecretario;

/**
 * Cria secretario a partir das informacoes passadas por parametro
 */
tSecretario* CriaSecretario(char* nome, char* cpf, char* nasc, char* tel, char* genero, char* user, char* senha, char* nivel);

void DesalocaSecretario(tSecretario* sec);

char* ObtemNomeSecretario(tSecretario* sec);
int ObtemTipoSecretario(tSecretario* sec);

int SecComparaCPF(tSecretario* sec, char* cpf);
int SecComparaUser(tSecretario* sec, char* user);
int SecComparaSenha(tSecretario* sec, char* senha);

void SecretarioSalvaBinario(tSecretario** sec, int qtd, char* path);
void SecretarioRecuperaBinario(tSecretario*** sec, FILE* arq, int* qtd);

void CadastraSecretario(int* nSecretarios, tSecretario*** secretarios);

#endif