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

/**
 * Verifica se o secretario é NULL e o desaloca caso não
*/
void DesalocaSecretario(tSecretario* sec);

/**
 * Retorna o nome do secretario passado por parametro
*/
char* ObtemNomeSecretario(tSecretario* sec);
/**
 * Retorna o tipo do secretario passado por parametro
*/
int ObtemTipoSecretario(tSecretario* sec);

/**
 * Compara o CPF do secretario passado por parametro com o CPF passado por parametro
*/
int SecComparaCPF(tSecretario* sec, char* cpf);
/**
 * Compara o user do secretario passado por parametro com o user passado por parametro
*/
int SecComparaUser(tSecretario* sec, char* user);
/**
 * Compara a senha do secretario passado por parametro com a senha passado por parametro
*/
int SecComparaSenha(tSecretario* sec, char* senha);

/**
 * Salva os secretarios no binario
*/
void SecretarioSalvaBinario(tSecretario** sec, int qtd, char* path);
/**
 * Recupera os secretarios do binario
*/
void SecretarioRecuperaBinario(tSecretario*** sec, FILE* arq, int* qtd);

/**
 * Cadastra um novo secretario modificando o **,
 * Verifica se o CPF lido nunca foi utilizado,
 * Retorna para o menu principal
*/
void CadastraSecretario(int* nSecretarios, tSecretario*** secretarios);

#endif