#ifndef _TLESAO_H_
#define _TLESAO_H_

#include <stdio.h>

typedef struct tLesao tLesao;

tLesao* CriaLesao(char* rotulo, char* diagnostico, char* regiao, int tam, int cirurgia, int crioterapia);

void desalocaLesao(tLesao* dado);

char* ObtemRotuloLesao(tLesao* lesao);
char* ObtemDiagnosticoLesao(tLesao* lesao);
char* ObtemRegiaoLesao(tLesao* lesao);
int ObtemTamanhoLesao(tLesao* lesao);
int ObtemCirurgiaLesao(tLesao* lesao);
int ObtemCrioterapiaLesao(tLesao* lesao);

void LesaoSalvaBinario(tLesao** lesao, int qtd, FILE* arq);
void LesaoRecuperaBinario(tLesao*** lesao, FILE* arq, int qtd);

#endif