#include "tFuncoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DesalocaPessoas(tPaciente** pacientes, tSecretario** secretarios, tMedico** medicos, int nMedicos, int nPacientes, int nSecretarios){
    for(int i=0; i<nMedicos; i++){
        DesalocaMedico(medicos[i]);
    }
    free(medicos);
    for(int i=0; i<nPacientes; i++){
        DesalocaPaciente(pacientes[i]);
    }
    free(pacientes);
    for(int i=0; i<nSecretarios; i++){
        DesalocaSecretario(secretarios[i]);
    }
    free(secretarios);
}

void DesalocaArquivos(tConsulta** consultas, int nConsultas, tFila* filaImpressao, tListaBusca** listasbusca, tRelatorio** relatorios){
    for(int i=0; i<nConsultas; i++){
        desalocaConsulta(consultas[i]);
    }
    free(consultas);
    desalocaFila(filaImpressao);
    free(listasbusca);
    free(relatorios);
}

void ImprimeMenuPrincipal(int tipo){
    printf("####################### MENU PRINCIPAL #########################\n");
    printf("ESCOLHA UMA OPCAO:\n");
    if(tipo){
        if(tipo == 1){
            printf("\t(1) CADASTRAR SECRETARIO\n");
        }
        printf("\t(2) CADASTRAR MEDICO\n");
        printf("\t(3) CADASTRAR PACIENTE\n");
    }
    if(tipo != 2){
        printf("\t(4) REALIZAR CONSULTA\n");
    }
    printf("\t(5) BUSCAR PACIENTES\n");
    printf("\t(6) RELATORIO GERAL\n");
    printf("\t(7) FILA DE IMPRESSAO\n");
    printf("\t(8) FINALIZAR O PROGRAMA\n");
    printf("###############################################################\n");
}

int ObtemTipoUsuario(tMedico** med, int nmed, tSecretario** sec, int nsec, char* user, char* senha, int* id){
    int tipo = -1;
    for(int i=0; i<nmed; i++){
        if(MedComparaUser(med[i], user) && MedComparaSenha(med[i], senha)){
            tipo = 0;
            *id = i;
            return tipo;
        }
    }
    for(int i=0; i<nsec; i++){
        if(SecComparaUser(sec[i], user) && SecComparaSenha(sec[i], senha)){
            *id = i;
            tipo = ObtemTipoSecretario(sec[i]);
            return tipo;
        }
    }
    return tipo;
}

void OperaFila(tFila* filaImpressao, char* path){
    while(1){
        printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) EXECUTAR FILA DE IMPRESSAO\n");
        printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
        printf("###############################################################\n");
        int num = 0;
        scanf("%d%*c", &num);
        if(num == 1){
            printf("################ FILA DE IMPRESSAO MEDICA ##################\n");
            printf("EXECUTANDO FILA DE IMPRESSAO:\n");
            imprimeFila(filaImpressao, path);
        }
        else if(num == 2){
            break;
        }
        printf("\nPRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
        char c;
        scanf("%c%*c", &c);
        printf("###############################################################\n");
    }
}

void SalvaBinario(tPaciente** pacientes, tMedico** medicos, tSecretario** secretarios, tConsulta** consultas, int nConsultas, int nMedicos, int nPacientes, int nSecretarios, char* bancodedados){
    MedicoSalvaBinario(medicos, nMedicos, bancodedados);
    PacienteSalvaBinario(pacientes, nPacientes, bancodedados);
    SecretarioSalvaBinario(secretarios, nSecretarios, bancodedados);
    ConsultaSalvaBinario(consultas, nConsultas, bancodedados);
}

void RecuperaBinario(tPaciente*** pacientes, tMedico*** medicos, tSecretario*** secretarios, tConsulta*** consultas, int* nConsultas, int* nMedicos, int* nPacientes, int* nSecretarios, char* bancodedados){
    char pathM[300], pathS[300], pathP[300];
    sprintf(pathM, "%s/medicos.bin", bancodedados);
    sprintf(pathS, "%s/secretarios.bin", bancodedados);
    sprintf(pathP, "%s/pacientes.bin", bancodedados);

    FILE* fSec = fopen(pathS, "rb");
    FILE* fMed = fopen(pathM, "rb");
    FILE* fPac = fopen(pathP, "rb");
    if(fSec != NULL){
        MedicoRecuperaBinario(medicos, fMed, nMedicos);
        PacienteRecuperaBinario(pacientes, fPac, nPacientes);
        SecretarioRecuperaBinario(secretarios, fSec, nSecretarios);
    }
    ConsultaRecuperaBinario(consultas, bancodedados, nConsultas);
}

void FazLogin(int nMedicos, int* nSecretarios, tMedico** medicos, tSecretario*** secretarios, int* idLogin, int* tipo){
    while(1){
        if(nMedicos != 0 || *nSecretarios != 0){
            while(1){
                char user[20], senha[20];
                printf("######################## ACESSO MINI-SADE ######################\n");
                printf("DIGITE SEU LOGIN: ");
                scanf("%[^\n]%*c", user);
                printf("DIGITE SUA SENHA: ");
                scanf("%[^\n]%*c", senha);

                *tipo = ObtemTipoUsuario(medicos, nMedicos, *secretarios, *nSecretarios, user, senha, idLogin);
                if(*tipo == -1){
                    printf("SENHA INCORRETA OU USUARIO INEXISTENTE\n");
                    printf("###############################################################\n");
                }
                else{
                    printf("###############################################################\n");
                    break;
                }
            }
            break;
        }
        else{
            char nome[100], cpf[15], nasc[11], tel[15], genero[10], user[20], senha[20], tipo[6];

            (*nSecretarios)++;
            *secretarios = realloc(*secretarios, (*nSecretarios)*sizeof(tSecretario*));
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
            *secretarios[(*nSecretarios)-1] = CriaSecretario(nome, cpf, nasc, tel, genero, user, senha, tipo);
        }
    }
}