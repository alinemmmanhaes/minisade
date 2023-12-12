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
#include "tFuncoes.h"

int main(int argc, char * argv[]){
    char path[200], caminho[200], bancodedados[400];
    sprintf(path, "%s/saida", argv[1]);

    tMedico** medicos = NULL;
    tPaciente** pacientes = NULL;
    tSecretario** secretarios = NULL;
    tConsulta** consultas = NULL;
    tListaBusca** listasbusca = NULL;
    tRelatorio** relatorios = NULL;
    tFila* filaImpressao = criaFila();
    int nMedicos = 0, nPacientes = 0, nSecretarios = 0, nConsultas = 0, nListaBusca = 0, nRelatorios = 0, op=0, tipo = -1, idLogin = -1;
    
    CriaArquivosTexto(path);

    if(argc <= 1){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }

    printf("################################################\n");
    printf("DIGITE O CAMINHO DO BANCO DE DADOS: ");
    scanf("%[^\n]%*c", caminho);
    printf("################################################\n");
    sprintf(bancodedados, "%s/%s", argv[1], caminho);
    printf("Caminho do banco de dados: %s\n", bancodedados);
    printf("Caminho da pasta de saida: %s\n", path);

    RecuperaBinario(&pacientes, &medicos, &secretarios, &consultas, &nConsultas, &nMedicos, &nPacientes, &nSecretarios, bancodedados);

    FazLogin(nMedicos, &nSecretarios, medicos, &secretarios, &idLogin, &tipo);

    while(1){
        ImprimeMenuPrincipal(tipo);
        scanf("%d%*c", &op);
        if(op == 1 && tipo == 1){
            CadastraSecretario(&nSecretarios, &secretarios);
        }
        else if(op == 2 && tipo){
            CadastraMedico(&nMedicos, &medicos);
        }
        else if(op == 3 && tipo){
            CadastraPaciente(&nPacientes, &pacientes);
        }
        else if(op == 4 && tipo != 2){
            RealizaConsultas(nPacientes, pacientes, &nConsultas, &consultas, filaImpressao, tipo, idLogin, medicos);
        }
        else if(op == 5){
            RealizaBusca(nPacientes, pacientes, &nListaBusca, &listasbusca, filaImpressao);
        }
        else if(op == 6){
            GeraRelatorio(nPacientes, nConsultas, pacientes, consultas, &relatorios, &nRelatorios, filaImpressao);
        }
        else if(op == 7){
            OperaFila(filaImpressao, path);
        }
        else if(op == 8){
            break;
        }
        else{
            printf("OPERACAO INVALIDA\n");
        }
    }
    
    SalvaBinario(pacientes, medicos, secretarios, consultas, nConsultas, nMedicos, nPacientes, nSecretarios, bancodedados);

    DesalocaPessoas(pacientes, secretarios, medicos, nMedicos, nPacientes, nSecretarios);
    DesalocaArquivos(consultas, nConsultas, filaImpressao, listasbusca, relatorios);

    return 0;
}