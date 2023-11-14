#include "tFila.h"
#include <stdio.h>
#include <stdlib.h>

struct tFila
{
    tDocumento** docs;
    int numdocs;
};


tFila *criaFila(){
    tFila* fila = malloc(sizeof(tFila));
    return fila;
}

void desalocaFila(tFila *f){
    for(int i=0; i<f->numdocs; i++){
        if(f->docs[i] != NULL){
            desalocaDocumento(f->docs[i]);
        }
    }
    free(f);
}

void insereDocumentoFila(tFila *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                         func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca){
                            (f->numdocs)++;
                            f->docs = realloc(f->docs, (f->numdocs)*sizeof(tDocumento*));
                            f->docs[(f->numdocs)-1] = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);
                         }

int quantidadeDocumentosNaFila(tFila *f){
    return f->numdocs;
}

void imprimeFila(tFila *f, char *path){
    for(int i=0; i<f->numdocs; i++){
        imprimeNaTelaDocumento(f->docs[i]);
        imprimeEmArquivoDocumento(f->docs[i], path);
    }
}