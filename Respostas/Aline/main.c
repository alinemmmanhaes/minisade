#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tBiopsia.h"
#include "tConsulta.h"
#include "tDocumento.h"
#include "tEncaminhamento.h"
#include "tFila.h"
#include "tLesao.h"
#include "tListaBusca.h"
#include "tMedico.h"
#include "tPaciente.h"
#include "tReceita.h"
#include "tRelatorio.h"
#include "tSecretario.h"

void ImprimeMenuPrincipal(){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    printf("\t(1) CADASTRAR SECRETARIO\n");
    printf("\t(2) CADASTRAR MEDICO\n");
    printf("\t(3) CADASTRAR PACIENTE\n");
    printf("\t(4) REALIZAR CONSULTA\n");
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

int main(int argv, char argc[]){
    tMedico** medicos = NULL;
    tPaciente** pacientes = NULL;
    tSecretario** secretarios = NULL;
    int nMedicos = 0, nPacientes = 0, nSecretarios = 0, op=0;

    while(1){
        ImprimeMenuPrincipal();
        scanf("%d%*c", &op);
        if(op == 1){

        }
    }

    return 0;
}