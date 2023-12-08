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

void CadastraSec(int* total, tSecretario** sec){
    char nome[100], cpf[15], nasc[11], tel[15], genero[10], user[20], senha[20], tipo[6];

    (*total)++;
    sec = realloc(sec, (*total)*sizeof(tSecretario*));
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

    sec[(*total)-1] = CriaSecretario(nome, cpf, nasc, tel, genero, user, senha, tipo);

    printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    char c;
    scanf("%c%*c", &c);
    printf("###############################################################\n");
}

void CadastraMed(int* total, tMedico** med){
    char nome[100], cpf[15], nasc[11], tel[15], genero[10], user[20], senha[20], crm[12];

    (*total)++;
    med = realloc(med, (*total)*sizeof(tMedico*));
    printf("#################### CADASTRO MEDICO #######################\n");
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
    printf("CRM: ");
    scanf("%[^\n]%*c", crm);
    printf("NOME DE USUARIO: ");
    scanf("%[^\n]%*c", user);
    printf("SENHA: ");
    scanf("%[^\n]%*c", senha);

    med[(*total)-1] = CriaMedico(nome, cpf, nasc, tel, genero, crm, user, senha);

    printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    char c;
    scanf("%c%*c", &c);
    printf("###############################################################\n");
}

void CadastraPac(int* total, tPaciente** pac){
    char nome[100], cpf[15], tel[15], genero[10];
    int dia, mes, ano;

    (*total)++;
    pac = realloc(pac, (*total)*sizeof(tPaciente*));
    printf("#################### CADASTRO PACIENTE #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", nome);
    printf("CPF: ");
    scanf("%[^\n]%*c", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    printf("TELEFONE: ");
    scanf("%[^\n]%*c", tel);
    printf("GENERO: ");
    scanf("%[^\n]%*c", genero);

    pac[(*total)-1] = CriaPaciente(nome, cpf, dia, mes, ano, tel, genero);

    printf("\nCADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    char c;
    scanf("%c%*c", &c);
    printf("###############################################################\n");
}

int main(int argc, char * argv[]){
    char path[100], caminho[100], bancodedados[200];
    sprintf(path, "%s/saida", argv[1]);

    tMedico** medicos = NULL;
    tPaciente** pacientes = NULL;
    tSecretario** secretarios = NULL;
    tConsulta** consultas = NULL;
    tListaBusca** listasbusca = NULL;
    tRelatorio** relatorios = NULL;
    tFila* filaImpressao = criaFila();
    int nMedicos = 0, nPacientes = 0, nSecretarios = 0, nConsultas = 0, nListaBusca = 0, nRelatorios = 0, op=0, tipo = -1, idLogin = -1;
    
    if(argc <= 1){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }

    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS: ");
    scanf("%[^\n]%*c", caminho);
    printf("\n################################################\n");
    sprintf(bancodedados, "%s/%s", argv[1], caminho);

    //VERIFICA SE BANCO DE DADOS FOI CRIADO E LE DADOS ANTERIORES
    char pathM[300], pathS[300], pathP[300];
    sprintf(pathM, "%s/medicos.bin", bancodedados);
    sprintf(pathS, "%s/secretarios.bin", bancodedados);
    sprintf(pathP, "%s/pacientes.bin", bancodedados);

    FILE* fSec = fopen(pathS, "rb");
    FILE* fMed = fopen(pathM, "rb");
    FILE* fPac = fopen(pathP, "rb");
    if(fSec != NULL){
        medicos = MedicoRecuperaBinario(medicos, fMed, &nMedicos);
        pacientes = PacienteRecuperaBinario(pacientes, fPac, &nPacientes);
        secretarios = SecretarioRecuperaBinario(secretarios, fSec, &nSecretarios);
    }

    while(1){
        if(nMedicos != 0 || nSecretarios != 0){
            while(1){
                char user[20], senha[20];
                printf("######################## ACESSO MINI-SADE ######################\n");
                printf("DIGITE SEU LOGIN: ");
                scanf("%[^\n]%*c", user);
                printf("DIGITE SUA SENHA: ");
                scanf("%[^\n]%*c", senha);

                tipo = ObtemTipoUsuario(medicos, nMedicos, secretarios, nSecretarios, user, senha, &idLogin);
                if(tipo == -1){
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

            (nSecretarios)++;
            secretarios = realloc(secretarios, (nSecretarios)*sizeof(tSecretario*));
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
            secretarios[(nSecretarios)-1] = CriaSecretario(nome, cpf, nasc, tel, genero, user, senha, tipo);
        }
    }

    while(1){
        ImprimeMenuPrincipal(tipo);
        scanf("%d%*c", &op);
        if(op == 1 && tipo == 1){
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

            for(int i=0; i<nSecretarios; i++){
                if(SecComparaCPF(secretarios[i], cpf)){
                    ehigual = 1;
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA\n");
                    break;
                }
            }

            if(ehigual == 0){
                (nSecretarios)++;
                secretarios = realloc(secretarios, (nSecretarios)*sizeof(tSecretario*));
                secretarios[(nSecretarios)-1] = CriaSecretario(nome, cpf, nasc, tel, genero, user, senha, tipo);
                printf("\nCADASTRO REALIZADO COM SUCESSO. ");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);
                printf("###############################################################\n");
            }
        }
        else if(op == 2 && tipo){
            char nome[100], cpf[15], nasc[11], tel[15], genero[10], user[20], senha[20], crm[12];
            int ehigual = 0;

            printf("#################### CADASTRO MEDICO #######################\n");
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
            printf("CRM: ");
            scanf("%[^\n]%*c", crm);
            printf("NOME DE USUARIO: ");
            scanf("%[^\n]%*c", user);
            printf("SENHA: ");
            scanf("%[^\n]%*c", senha);

            for(int i=0; i<nMedicos; i++){
                if(MedComparaCPF(medicos[i], cpf)){
                    ehigual = 1;
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA\n");
                    break;
                }
            }

            if(ehigual == 0){
                (nMedicos)++;
                medicos = realloc(medicos, (nMedicos)*sizeof(tMedico*));
                medicos[(nMedicos)-1] = CriaMedico(nome, cpf, nasc, tel, genero, crm, user, senha);
                printf("\nCADASTRO REALIZADO COM SUCESSO. ");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);
                printf("###############################################################\n");
            }

            /*printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            char c;
            scanf("%c%*c", &c);
            printf("###############################################################\n");*/
        }
        else if(op == 3 && tipo){
            char nome[100], cpf[15], tel[15], genero[10];
            int dia, mes, ano, ehigual = 0;;

            printf("#################### CADASTRO PACIENTE #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nome);
            printf("CPF: ");
            scanf("%[^\n]%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%d/%d/%d%*c", &dia, &mes, &ano);
            printf("TELEFONE: ");
            scanf("%[^\n]%*c", tel);
            printf("GENERO: ");
            scanf("%[^\n]%*c", genero);

            for(int i=0; i<nPacientes; i++){
                if(PacComparaCPF(pacientes[i], cpf)){
                    ehigual = 1;
                    printf("CPF JA EXISTENTE. OPERACAO NAO PERMITIDA\n");
                    break;
                }
            }

            if(ehigual == 0){
                (nPacientes)++;
                pacientes = realloc(pacientes, (nPacientes)*sizeof(tPaciente*));
                pacientes[(nPacientes)-1] = CriaPaciente(nome, cpf, dia, mes, ano, tel, genero);
                printf("\nCADASTRO REALIZADO COM SUCESSO. ");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);
                printf("###############################################################\n");
            }

            /*printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
            char c;
            scanf("%c%*c", &c);
            printf("###############################################################\n");*/
        }
        else if(op == 4 && tipo != 2){
            char cpf[15];
            int resp = -1;
            printf("#################### CONSULTA MEDICA #######################\n");
            printf("CPF DO PACIENTE: ");
            scanf("%[^\n]%*c", cpf);
            for(int i=0; i<nPacientes; i++){
                if(PacComparaCPF(pacientes[i], cpf)){
                    resp = i;
                    break;
                }
            }
            if(resp == -1){
                printf("PACIENTE SEM CADASTRO\n\n");
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);
                printf("###############################################################\n");
            }
            else{
                printf("---\n");
                printf("-NOME: %s\n", ObtemNomePaciente(pacientes[resp]));
                printf("-DATA DE NASCIMENTO: %s\n", ObtemDataNascPaciente(pacientes[resp]));
                printf("---\n");

                nConsultas++;
                consultas = realloc(consultas, nConsultas*sizeof(tConsulta*));
                if(tipo){
                    consultas[nConsultas - 1] = CriaConsulta(NULL, ObtemCPFPaciente(pacientes[resp]), ObtemNomePaciente(pacientes[resp]));
                }
                else{
                    consultas[nConsultas - 1] = CriaConsulta(medicos[idLogin], ObtemCPFPaciente(pacientes[resp]), ObtemNomePaciente(pacientes[resp]));
                }

                LeConsulta(consultas[nConsultas - 1]);
                printf("###############################################################\n");
                PacIncrementaConsultas(pacientes[resp]);
                MenuDaConsulta(consultas[nConsultas - 1], filaImpressao);
            }
        }
        else if(op == 5){
            char nome[100];
            int total = 0;
            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("NOME DO PACIENTE: ");
            scanf("%[^\n]%*c", nome);
            for(int i=0; i<nPacientes; i++){
                tPaciente* p = pacientes[i];
                if(PacComparaNome(p, nome) == 1){
                    total = 1;
                }
            }

            if(total == 0){
                printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
                char c;
                scanf("%c%*c", &c);

            }
            else{
                (nListaBusca)++;
                listasbusca = realloc(listasbusca, nListaBusca*sizeof(tListaBusca*));
                listasbusca[nListaBusca - 1] = CriaListaBusca();
                for(int i=0; i<nPacientes; i++){
                    tPaciente* p = pacientes[i];
                    if(PacComparaNome(p, nome)){
                        AdicionaPacienteListaBusca(listasbusca[nListaBusca - 1], p);
                    }
                }

                printf("PACIENTES ENCONTRADOS:\n");
                imprimeNaTelaListaBusca(listasbusca[nListaBusca - 1]);

                printf("#################### BUSCAR PACIENTES #######################\n");
                printf("ESCOLHA UMA OPCAO:\n");
                printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
                printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
                printf("###############################################################\n\n");
                int num = 0;
                scanf("%d%*c", &num);
                if(num == 1){
                    insereDocumentoFila(filaImpressao, listasbusca[nListaBusca - 1], imprimeNaTelaListaBusca, imprimeEmArquivoListaBusca, DesalocaListaBusca);
                    printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
                    char c;
                    scanf("%c%*c", &c);
                }
            }
            printf("###############################################################\n");
        }
        else if(op == 6){
            printf("#################### RELATORIO GERAL #######################\n");
            nRelatorios++;
            relatorios = realloc(relatorios, nRelatorios*sizeof(tRelatorio*));
            relatorios[nRelatorios - 1] = CriaRelatorio();
            CalculaRelatorio(relatorios[nRelatorios - 1], pacientes, nPacientes, consultas, nConsultas);
            imprimeNaTelaRelatorio(relatorios[nRelatorios - 1]);

            printf("ESCOLHA UMA OPCAO:\n");
            printf("\t(1) ENVIAR PARA IMPRESSAO\n");
            printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
            printf("###############################################################\n\n");
            int num = 0;
            scanf("%d%*c", &num);
            if(num == 1){
                insereDocumentoFila(filaImpressao, relatorios[nRelatorios - 1], imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorio);
                printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                char c;
                scanf("%c%*c", &c);
                printf("###############################################################\n");
            }
        }
        else if(op == 7){
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
        else if(op == 8){
            break;
        }
        else{
            printf("OPERACAO INVALIDA\n");
        }
    }
    
    MedicoSalvaBinario(medicos, nMedicos, bancodedados);
    PacienteSalvaBinario(pacientes, nPacientes, bancodedados);
    SecretarioSalvaBinario(secretarios, nSecretarios, bancodedados);
    ConsultaSalvaBinario(consultas, nConsultas, bancodedados);

    DesalocaPessoas(pacientes, secretarios, medicos, nMedicos, nPacientes, nSecretarios);
    DesalocaArquivos(consultas, nConsultas, filaImpressao, listasbusca, relatorios);

    return 0;
}