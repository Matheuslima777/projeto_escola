#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "aluno.c"

// utilizar um gerador automatico de matriculas
// modularizar
// novos atributos na struct
// mais validações

int main(void){

    Aluno listarAluno[TAM_ALUNO];
    int opcao;
    int sair = 0; //falso
    int qtdAluno = 0;

    while(!sair){
      opcao = menuGeral();

        switch(opcao){
            case 0:{
            sair=1;
            break;
            }case 1:{
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
                        if(retorno==LISTA_CHEIA){
                        printf("LISTA DE ALUNOS CHEIA\n");
                        }else if(retorno==MATRICULA_INVALIDA){
                            printf("MATRICULA INVALIDA\n");
                        }else if(retorno==SEXO_INVALIDO){
                            printf("SEXO INVALIDO\n");
                        }else if(retorno==CPF_CADASTRADO){
                            printf("CPF JA CADASTRADO\n");
                        }else{
                            printf("CADASTRADO COM SUCESSO!\n");
                            qtdAluno++;
                        }
                        
                        break;
                        }
                        case 2:{
                       listarAlunos(qtdAluno,listarAluno);
                        break;
                        }
                        case 3:{
                            int retorno = atualizarAluno(qtdAluno,listarAluno);
                            switch (retorno)
                            {
                            case MATRICULA_INVALIDA:{
                            printf("MATRICULA INVALIDA!\n"); break;
                            }
                            case MATRICULA_INEXISTENTE:{
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
                                case MATRICULA_INVALIDA:{
                                    printf("MATRICULA INVALIDA!\n");
                                    break;
                                }
                                case MATRICULA_INEXISTENTE:{
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


//funções

