#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdio.h>

typedef struct tLesao tLesao;

/**
 * Cria Lesao alocando dinamicamente com as variaveis passadas por parametro
*/
tLesao* CriaLesao(char* rotulo, char* diagnostico, char* regiao, int tam, int cirurgia, int crioterapia);

/**
 * Verifica se a lesao é NULL e a desaloca caso não
*/
void desalocaLesao(tLesao* dado);

/**
 * Retorna o rotulo da lesao passada por parametro
*/
char* ObtemRotuloLesao(tLesao* lesao);
/**
 * Retorna o diagnostico da lesao passada por parametro
*/
char* ObtemDiagnosticoLesao(tLesao* lesao);
/**
 * Retorna a regiao da lesao passada por parametro
*/
char* ObtemRegiaoLesao(tLesao* lesao);
/**
 * Retorna o tamanho da lesao passada por parametro
*/
int ObtemTamanhoLesao(tLesao* lesao);
/**
 * Retorna se a lesao passada por parametro precisa de cirurgia
*/
int ObtemCirurgiaLesao(tLesao* lesao);
/**
 * Retorna se a lesao passada por parametro precisa de crioterapia
*/
int ObtemCrioterapiaLesao(tLesao* lesao);

/**
 * Salva as lesoes no binario
*/
void LesaoSalvaBinario(tLesao** lesao, int qtd, FILE* arq);
/**
 * Recupera as lesoes do binario
*/
void LesaoRecuperaBinario(tLesao*** lesao, FILE* arq, int qtd);

#endif