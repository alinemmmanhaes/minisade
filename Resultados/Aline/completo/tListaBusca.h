#ifndef _TLISTABUSCA_H_
#define _TLISTABUSCA_H_

typedef struct tListaBusca tListaBusca;

tListaBusca* CriaListaBusca();

void AdicionaPacienteListaBusca(tListaBusca* lista, tPaciente* paciente);

void DesalocaListaBusca(void* dado);

void imprimeNaTelaListaBusca(void *dado);

void imprimeEmArquivoListaBusca(void *dado, char *path);

#endif