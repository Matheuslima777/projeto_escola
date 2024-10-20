#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "aluno.c"
#include "professor.c"

// utilizar um gerador automatico de matriculas
// modularizar
// novos atributos na struct
// mais validações

int main(void){

    Aluno listarAluno[TAM_ALUNO];
    Professor listarProfessor[TAM_PROFESSOR];
    int opcao;
    int sair = 0; //falso
    int qtdAluno = 0;
    int qtdProfessor = 0;

    while(!sair){
      opcao = menuGeral();

        switch(opcao){
            case 0:{
            sair=1;
            break;
            }case 1:
            {
                printf("MODULO ALUNO\n");
                int sairAluno = 0;
                int opcaoAluno;
                while (!sairAluno)
                {
                    opcaoAluno = menuAluno();
 
                    switch(opcaoAluno){
                        case 0:{
                            sairAluno=1;
                            break;
                        }
                        case 1:{
                        int retorno = cadastrarAluno(qtdAluno, listarAluno);
                        if(retorno==LISTA_ALUNO_CHEIA){
                        printf("LISTA DE ALUNOS CHEIA\n");
                        }else if(retorno==MATRICULA_ALUNO_INVALIDA){
                            printf("MATRICULA INVALIDA\n");
                        }else if(retorno==SEXO_ALUNO_INVALIDO){
                            printf("SEXO INVALIDO\n");
                        }else if(retorno==CPF_ALUNO_JA_CADASTRADO){
                            printf("CPF JA CADASTRADO\n");
                        }else{
                            printf("CADASTRADO COM SUCESSO!\n");
                            qtdAluno++;
                        }
                        
                        break;
                        }
                        case 2:{
                        listarrAlunos(qtdAluno,listarAluno);
                        break;
                        }
                        case 3:{
                            int retorno = atualizarAluno(qtdAluno,listarAluno);
                            switch (retorno)
                            {
                            case MATRICULA_ALUNO_INVALIDA:{
                            printf("MATRICULA INVALIDA!\n"); break;
                            }
                            case MATRICULA_ALUNO_INEXISTENTE:{
                            printf("MATRICULA INEXISTENTE!\n"); break;
                            }
                            case ATUALIZADO_ALUNO_SUCESSO:{
                            printf("ALUNO ATUALIZADO COM SUCESSO!\n"); break;
                            }
                            }
                            break;
                        }
                        case 4:{
                            int retorno = excluirAluno(qtdAluno,listarAluno);
                            switch (retorno)
                            {
                                case MATRICULA_ALUNO_INVALIDA:{
                                    printf("MATRICULA INVALIDA!\n");
                                    break;
                                }
                                case MATRICULA_ALUNO_INEXISTENTE:{
                                    printf("MATRICULA INEXISTENTE!\n");
                                    break;
                                }
                                case EXCLUSAO_ALUNO_SUCESSO:{
                                    printf("ALUNO EXCLUIDO COM SUCESSO!\n");
                                    qtdAluno--;
                                    break;
                                }
                            }
                        break;
                        }
                        default:{
                        printf("OPERACAO INVALIDA!\n");
                        }
                    }
                }
                    break;
            }
            case 2:{
                printf("MODULO PROFESSOR\n");
                int sairProfessor = 0;
                int opcaoProfessor;
                while (!sairProfessor)
                {
                    opcaoProfessor = menuProfessor();
 
                    switch(opcaoProfessor){
                        case 0:{
                            sairProfessor=1;
                            break;
                        }
                        case 1:{
                        int retorno = cadastrarProfessor(qtdProfessor, listarProfessor);
                        if(retorno==LISTA_PROFESSOR_CHEIA){
                            printf("LISTA DE PROFESSOR CHEIA\n");
                        }else if(retorno==MATRICULA_PROFESSOR_INVALIDA){
                            printf("MATRICULA INVALIDA\n");
                        }else if(retorno==SEXO_PROFESSOR_INVALIDO){
                            printf("SEXO INVALIDO\n");
                        }else if(retorno==CPF_PROFESSOR_JA_CADASTRADO){
                            printf("CPF JA CADASTRADO\n");
                        }else{
                            printf("CADASTRADO COM SUCESSO!\n");
                            qtdProfessor++;
                        }
                        
                        break;
                        }
                        case 2:{
                        listarrProfessor(qtdProfessor, listarProfessor);
                        break;
                        }
                        case 3:{
                            int retorno = atualizarProfessor(qtdProfessor,listarProfessor);
                            switch (retorno)
                            {
                            case MATRICULA_PROFESSOR_INVALIDA:{
                            printf("MATRICULA INVALIDA!\n"); break;
                            }
                            case MATRICULA_PROFESSOR_INEXISTENTE:{
                            printf("MATRICULA INEXISTENTE!\n"); break;
                            }
                            case ATUALIZADO_PROFESSOR_SUCESSO:{
                            printf("PROFESSOR ATUALIZADO COM SUCESSO!\n"); break;
                            }
                            }
                            break;
                        }
                        case 4:{
                            int retorno = excluirProfessor(qtdProfessor,listarProfessor);
                            switch (retorno)
                            {
                                case MATRICULA_PROFESSOR_INVALIDA:{
                                    printf("MATRICULA INVALIDA!\n");
                                    break;
                                }
                                case MATRICULA_ALUNO_INEXISTENTE:{
                                    printf("MATRICULA INEXISTENTE!\n");
                                    break;
                                }
                                case EXCLUSAO_ALUNO_SUCESSO:{
                                    printf("PROFESSOR EXCLUIDO COM SUCESSO!\n");
                                    qtdProfessor--;
                                    break;
                                }
                            }
                        break;
                        }
                        default:{
                        printf("OPERACAO INVALIDA!\n");
                        }
                    }
                }
                    break;
            }
            case 3:{

                printf("MODULO DISCIPLINA\n");
                break;
            }
        }
    }

    return 0;
}


