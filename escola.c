#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "utils.h"




//mudando denovo para o segundo commit biruleib





//prototipos das funções
int menuGeral();
int menuAluno();   
int cadastrarAluno(int qtdAluno, Aluno listarAluno[]);
void listarAlunos(int qtdAluno, Aluno listarAluno[]);
int atualizarAluno(int qtdAluno, Aluno listarAluno[]);
int excluirAluno(int qtdAluno, Aluno listarAluno[]);
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
    

