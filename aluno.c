#include "utils.h"
#include <stdio.h>

 int menuAluno(){
        int opcao;
        printf("0-VOLTAR\n");   
        printf("1-CADASTRAR ALUNO\n");   
        printf("2-LISTAR ALUNO\n");   
        printf("3-ATUALIZAR ALUNO\n"); 
        printf("4-DELETAR ALUNO\n");
        scanf("%d", &opcao);
                        
        return opcao;
    }

    int menuGeral(){
    int opcao;
        printf("PROJETO ESCOLA\n");   
        printf("0-SAIR\n");   
        printf("1-ALUNO\n");   
        printf("2-PROFESSOR\n");   
        printf("3-DISCIPLINA\n");  
        scanf("%d", &opcao);

        return opcao;
}

        int cadastrarAluno(int qtdAluno, Aluno listarAluno[]){
                printf("CADASTRAR ALUNO\n");
                    if(qtdAluno==TAM_ALUNO){
                        return LISTA_CHEIA;
                    }else{
                            int matricula;
                            char nome[20];
                            char sexo;

                            printf("DIGITE SEU NOME:\n");
                            getchar();
                            fgets(nome,sizeof(nome),stdin);

                            printf("DIGITE A MATRICULA:\n");
                            scanf("%d", &matricula);

                            printf("DIGITE O SEXO (M/F):\n");
                            scanf(" %c", &sexo);

                           
                           
                           sexo = toupper(sexo);
                            if(matricula<0){
                                return MATRICULA_INVALIDA;
                            }else{
                                    if(sexo=='F' || sexo=='M'){
                                    strcpy(listarAluno[qtdAluno].nome, nome);
                                    listarAluno[qtdAluno].sexo = sexo;
                                    listarAluno[qtdAluno].matricula = matricula;
                                    listarAluno[qtdAluno].ativo = 1;
                                    return CAD_ALUNO_SUCESSO;
                                    }else{
                                        return SEXO_INVALIDO;
                                    }
                                
                            }
                        }
                    }

void listarAlunos(int qtdAluno, Aluno listarAluno[]){
        if(qtdAluno==0){
                        printf("LISTA DE ALUNO VAZIA\n");
                        }else{
                            for(int i=0; i<qtdAluno; i++){
                                if(listarAluno[i].ativo==1)
                                    printf(" aluno %d  nome:%s matricula: %d  sexo: %c\n", i,listarAluno[i].nome, listarAluno[i].matricula,listarAluno[i].sexo); 
                            
                            }
                        }
        
    }

    int atualizarAluno(int qtdAluno, Aluno listarAluno[]){
    printf("ATUALIZAR ALUNO\n");
                        printf("DIGITE A MATRICULA:\n");
                        int matricula;  
                        scanf("%d", &matricula);
                        int achou = 0;
                        if(matricula<0){
                            return MATRICULA_INVALIDA;
                        }else{
                        for(int i=0; i<qtdAluno; i++){
                            if (matricula==listarAluno[i].matricula&&listarAluno[i].ativo){
                                //atualização
                                printf("DIGITE A NOVA MATRICULA:\n");
                                int novaMatricula;
                                scanf("%d", &novaMatricula);
                                 if(novaMatricula<0){
                            return MATRICULA_INVALIDA;
                        }
                                    listarAluno[i].matricula=novaMatricula;
                                    
                                achou=1;
                                break;
                            }
                            
                        }if(achou){
                            return ATUALIZADO_ALUNO_SUCESSO;
                            
                        }else{
                            return MATRICULA_INEXISTENTE;
                           
                        }
    
        }
    }
    
    int excluirAluno(int qtdAluno, Aluno listarAluno[]){
        printf("DELETAR ALUNO\n");
        printf("DIGITE A MATRICULA:\n");
        int matricula;  
        scanf("%d", &matricula);
        int achou = 0;
            if(matricula<0){
                return MATRICULA_INVALIDA;
            }else{
                for(int i=0; i<qtdAluno; i++){ 
                    if (matricula==listarAluno[i].matricula){
                                
                        //exclusão logica
                            listarAluno[i].ativo = -1;
                               
                            for (int j=i; j<qtdAluno-1; j++)
                            {//movendo todos os alunos pra casa anterior
                                listarAluno[j].matricula=listarAluno[j+1].matricula;
                                listarAluno[j].sexo=listarAluno[j+1].sexo;
                                listarAluno[j].ativo=listarAluno[j+1].ativo;
                                            
                            }

                                achou=1;
                                break;
                    }
                }

                        if(achou){
                            return EXCLUSAO_ALUNO_SUCESSO;
                            
                        }else{
                                return MATRICULA_INEXISTENTE;
                           
                        }
                            
                }
            }
    

