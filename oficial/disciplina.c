#include "utils.h"
#include <stdio.h>


    int menuDisciplina(){
            int opcao;
            printf("0-VOLTAR\n");   
            printf("1-CADASTRAR DISCIPLINA\n");   
            printf("2-LISTAR DISCIPLINA\n");   
            printf("3-ATUALIZAR DISCIPLINA\n"); 
            printf("4-DELETAR DISCIPLINA\n");
            scanf("%d", &opcao);
                            
            return opcao;
        }

    int cadastrarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[])
    {
                printf("CADASTRAR DISCIPLINA\n");
                    if(qtdDisciplina==TAM_DISCIPLINA){
                        return LISTA_DISCIPLINA_CHEIA;
                    }else{
                            int coddisciplina;
                            int diaAtual, mesAtual, anoAtual;
                            char nome[20];

                            printf("DIGITE O NOME DA DISCIPLINA:\n");
                            getchar();
                            fgets(nome,sizeof(nome),stdin);

                             // Remover a nova linha ao final da string nome, se presente
                            size_t len = strlen(nome);
                            if (len > 0 && nome[len - 1] == '\n')
                                {
                                    nome[len - 1] = '\0';
                                }

                            printf("DIGITE O CODIGO DA DISCIPLINA:\n");
                            scanf("%d", &coddisciplina);

                            // Entrada da data atual
                            printf("DIGITE A DATA ATUAL (formato: DD/MM/AAAA):\n");
                            scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);

                            if(coddisciplina<0){
                                return COD_DISCIPLINA_INVALIDA;
                            }
                            else
                            {
                                //nome do aluno
                                strcpy(listarDisciplina[qtdDisciplina].nome, nome);

                                //cod da materia
                                listarDisciplina[qtdDisciplina].coddisciplina = coddisciplina;

                                //data que a materia entrou entrou
                                listarDisciplina[qtdDisciplina].diaAtual=diaAtual;
                                listarDisciplina[qtdDisciplina].mesAtual=mesAtual;
                                listarDisciplina[qtdDisciplina].anoAtual=anoAtual;

                                //marca se o aluno está cadastrado ou não, serve para fazer exclusão logica
                                listarDisciplina[qtdDisciplina].ativo = 1;

                                return CAD_DISCIPLINA_SUCESSO;
                            }
                                
                        }
    }

    void listarrDisciplina(int qtdDisciplina, Disciplina listarDisciplina[])
    {
        if(qtdDisciplina==0)
        {
            printf("LISTA DE DISCIPLINA VAZIA\n");
        }
            else
            {
                for(int i=0; i<qtdDisciplina; i++){
                    if(listarDisciplina[i].ativo==1){
                        printf("DISCIPLINA %d:\n", i);
                        printf("CODIGO DA DISCIPLINA: %d\n",listarDisciplina[i].coddisciplina);
                        printf("NOME:%s\n",listarDisciplina[i].nome);
                        printf("DATA DE CADASTRO: %d/%d/%d\n", listarDisciplina[i].diaAtual, listarDisciplina[i].mesAtual, listarDisciplina[i].anoAtual);
                        printf("\n");
                    }
                }
            }
        
    }

    int atualizarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]){
    printf("ATUALIZAR DISCIPLINAS\n");
                        int coddisciplina;

                        printf("DIGITE O CODIGO DA DISCIPLINA:\n");
                        scanf("%d", &coddisciplina);
                        int achou = 0;
                        if(coddisciplina<0){
                            return COD_DISCIPLINA_INVALIDA;
                        }else{
                        for(int i=0; i<qtdDisciplina; i++){
                            if (coddisciplina==listarDisciplina[i].coddisciplina&&listarDisciplina[i].ativo){
                                //atualização
                                int novocodigo;
                                char novoNome[20];
                                printf("DIGITE O NOVO CODIGO:\n");
                                scanf("%d", &novocodigo);
                                printf("NOME:\n");
                                getchar();
                                fgets(novoNome,sizeof(novoNome),stdin);

                                size_t len=strlen(novoNome);
                                if (len > 0 && novoNome[len - 1] == '\n') {
                                    novoNome[len - 1] = '\0';
                                }

                                if(novocodigo<0)
                                {
                                    return COD_DISCIPLINA_INVALIDA;
                                }
                                listarDisciplina[i].coddisciplina=novocodigo;
                                strcpy(listarDisciplina[i].nome,novoNome);
                                achou=1;
                                break;
                            }
                            
                        }if(achou){
                            return ATUALIZADO_DISCIPLINA_SUCESSO;
                            
                        }else{
                            return COD_DISCIPLINA_INEXISTENTE;
                        }
    
        }
    }
    
    int excluirDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]){
        printf("DELETAR DISCIPLINA\n");
        printf("DIGITE O CODIGO DA DISCPLINA:\n");
        int coddisciplina;  
        scanf("%d", &coddisciplina);
        int achou = 0;
            if(coddisciplina<0){
                return COD_DISCIPLINA_INVALIDA;
            }else{
                for(int i=0; i<qtdDisciplina; i++){ 
                    if (coddisciplina==listarDisciplina[i].coddisciplina){
                                
                        //exclusão logica
                        listarDisciplina[i].ativo = -1;
                        for (int j=i; j<qtdDisciplina-1; j++)
                        {
                        //movendo todas as disciplinas pra casa anterior
                            listarDisciplina[j].nome[20]=listarDisciplina[j+1].nome[20];
                            listarDisciplina[j].coddisciplina=listarDisciplina[j+1].coddisciplina;
                            listarDisciplina[j].ativo=listarDisciplina[j+1].ativo;
                            
                        //movendo as datas de cadastro
                        //cadastro
                            listarDisciplina[j].diaAtual=listarDisciplina[j+1].diaAtual;
                            listarDisciplina[j].mesAtual=listarDisciplina[j+1].mesAtual;
                            listarDisciplina[j].anoAtual=listarDisciplina[j+1].anoAtual;
                        }
                        achou=1;
                        break;
                    }
                }

                        if(achou){
                            return EXCLUSAO_DISCIPLINA_SUCESSO;
                            
                        }else{
                                return COD_DISCIPLINA_INEXISTENTE;
                        }
                }
            }
    

