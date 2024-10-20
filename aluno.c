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
                            char cpf[15];
                            char dataNascimento[12];
                            char nome[20];
                            char sexo;
                            int i;

                            printf("DIGITE SEU NOME:\n");
                            getchar();
                            fgets(nome,sizeof(nome),stdin);

                             // Remover a nova linha ao final da string nome, se presente
                             size_t len = strlen(nome);
                             if (len > 0 && nome[len - 1] == '\n') {
                                    nome[len - 1] = '\0';
                                 }

                            printf("DIGITE A MATRICULA:\n");
                            scanf("%d", &matricula);

                            printf("DIGITE O SEXO (M/F):\n");
                            scanf(" %c", &sexo);
                            sexo = toupper(sexo);

                            printf("DIGITE SEU CPF (formato: 000.000.000-00):\n");
                            getchar();
                            fgets(cpf, sizeof(cpf), stdin);
                            len = strlen(cpf);
                            if (len > 0 && cpf[len - 1] == '\n') {
                                cpf[len - 1] = '\0';
                            }

                             // Verificar se o CPF já está cadastrado
                            for (i = 0; i < qtdAluno; i++) {
                                if (strcmp(listarAluno[i].cpf, cpf) == 0) {
                                    printf("Erro: CPF já cadastrado!\n");
                                    return CPF_CADASTRADO;
                                }
                            }

                            printf("DIGITE SUA DATA DE NASCIMENTO (formato: DD/MM/AAAA):\n");
                            fgets(dataNascimento,sizeof(dataNascimento),stdin);

                            len = strlen(dataNascimento);
                            if (len > 0 && dataNascimento[len - 1] == '\n') {
                                dataNascimento[len - 1] = '\0';
                            }

                            if(matricula<0){
                                return MATRICULA_INVALIDA;
                            }else{
                                    if(sexo=='F' || sexo=='M'){
                                    strcpy(listarAluno[qtdAluno].nome, nome);
                                    listarAluno[qtdAluno].sexo = sexo;
                                    listarAluno[qtdAluno].matricula = matricula;
                                    strcpy(listarAluno[qtdAluno].cpf, cpf);
                                    strcpy(listarAluno[qtdAluno].dataNascimento, dataNascimento);
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
                                if(listarAluno[i].ativo==1){
                                    printf("ALUNO %d:\n", i);
                                    printf("SEXO: %c", listarAluno[i].sexo);
                                    printf("MATRICULA: %d\n",listarAluno[i].matricula);
                                    printf("NOME:%s\n",listarAluno[i].nome);
                                    printf("CPF: %s\n", listarAluno[i].cpf);
                                    printf("DATA DE NASCIMENTO: %s\n", listarAluno[i].dataNascimento);
                                    printf("\n");
                                }
                            }
                        }
        
    }

    int atualizarAluno(int qtdAluno, Aluno listarAluno[]){
    printf("ATUALIZAR ALUNO\n");
                        int matricula;
                        char cpf[15];
                        char dataNascimento[11];
                        char nome[20];
                        char sexo;

                        printf("DIGITE A MATRICULA:\n");
                        scanf("%d", &matricula);
                        int achou = 0;
                        if(matricula<0){
                            return MATRICULA_INVALIDA;
                        }else{
                        for(int i=0; i<qtdAluno; i++){
                            if (matricula==listarAluno[i].matricula&&listarAluno[i].ativo){
                                //atualização
                                int novaMatricula;
                                char novoNome[20];
                                char newDataNascimento[11];
                                char newSexo;
                                printf("DIGITE A NOVA MATRICULA:\n");
                                scanf("%d", &novaMatricula);
                                printf("NOME:\n");
                                getchar();
                                fgets(novoNome,sizeof(novoNome),stdin);

                                size_t len=strlen(novoNome);
                                if (len > 0 && novoNome[len - 1] == '\n') {
                                    novoNome[len - 1] = '\0';
                                 }
                                
                                printf("DATA DE NASCIMENTO:\n");
                                getchar();
                                fgets(newDataNascimento,sizeof(newDataNascimento),stdin);

                                len=strlen(newDataNascimento);
                                if (len > 0 && newDataNascimento[len - 1] == '\n') {
                                    newDataNascimento[len - 1] = '\0';
                                 }
                                
                                printf("SEXO:\n");
                                scanf(" %c", &newSexo);

                                 if(novaMatricula<0){
                            return MATRICULA_INVALIDA;
                        }
                                listarAluno[i].matricula=novaMatricula;
                                strcpy(listarAluno[i].nome,novoNome);
                                strcpy(listarAluno[i].dataNascimento,newDataNascimento);
                                listarAluno[i].sexo=newSexo;
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
    

