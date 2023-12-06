#include "tLesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLesao
{
    char rotulo[6];
    char diagnostico[30];
    char regiao[20];
    int tam;
    int cirurgia;
    int crioterapia;
};

tLesao* CriaLesao(char* rotulo, char* diagnostico, char* regiao, int tam, int cirurgia, int crioterapia){
    tLesao* lesao = malloc(sizeof(tLesao));
    strcpy(lesao->rotulo, rotulo);
    strcpy(lesao->diagnostico, diagnostico);
    strcpy(lesao->regiao, regiao);
    lesao->tam = tam;
    lesao->cirurgia = cirurgia;
    lesao->crioterapia = crioterapia;
    return lesao;
}

void desalocaLesao(tLesao* dado){
    if(dado != NULL){
        free(dado);
    }
}

char* ObtemRotuloLesao(tLesao* lesao){
    return lesao->rotulo;
}

char* ObtemDiagnosticoLesao(tLesao* lesao){
    return lesao->diagnostico;
}

char* ObtemRegiaoLesao(tLesao* lesao){
    return lesao->regiao;
}

int ObtemTamanhoLesao(tLesao* lesao){
    return lesao->tam;
}

int ObtemCirurgiaLesao(tLesao* lesao){
    return lesao->cirurgia;
}

int ObtemCrioterapiaLesao(tLesao* lesao){
    return lesao->crioterapia;
}