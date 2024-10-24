#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "alunoteste.c"
#include "professorteste.c"
#include "disciplinateste.c"

// utilizar um gerador automatico de matriculas
// modularizar
// novos atributos na struct
// mais validações

int main(void){

    //zerando todas as qtd de alunos de cada discplina
    zerandoqtdalunosdiscplina(listarDisciplina);

    /*listarAluno[1].matricula = 123;
    strcpy(listarAluno[1].cpf, "863");
    listarAluno[1].diaNascimento=17, listarAluno[1].mesNascimento=5, listarAluno[1].anoNascimento=2005;
    listarAluno[1].diaAtual=23, listarAluno[1].mesAtual=10, listarAluno[1].anoAtual=2024;
    strcpy(listarAluno[1].nome, "cauas");
    listarAluno[1].idade = 18;
    listarAluno[1].sexo = 'M';
    listarAluno[1].ativo = 1;

    listarProfessor[1].matricula = 321;
    strcpy(listarProfessor[1].cpf, "863");
    listarProfessor[1].diaNascimento=17, listarAluno[1].mesNascimento=5, listarAluno[1].anoNascimento=2005;
    listarProfessor[1].diaAtual=23, listarAluno[1].mesAtual=10, listarAluno[1].anoAtual=2024;
    strcpy(listarProfessor[1].nome, "matheus");
    listarProfessor[1].idade = 18;
    listarProfessor[1].sexo = 'M';
    listarProfessor[1].ativo = 1;

    listarDisciplina[1].coddisciplina=444;
    listarDisciplina[1].diaAtual=23, listarDisciplina[1].mesAtual=10, listarDisciplina[1].anoAtual=2024;
    strcpy(listarDisciplina[1].nome, "bio");
    listarDisciplina[1].matriculaprof=321;
    listarDisciplina[1].ativo=1;*/





    while(!sair){
        opcao = menuGeral();

        switch(opcao){
            case 0:{ //! -----SAIDA-----
            sair=1;
            break;
            }case 1: //! -----MODULO ALUNO-----
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
            case 2: //! -----MODULO PROFESSOR-----
            {
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
            case 3: //! -----MODULO DISCIPLINAS-----
            {
                printf("MODULO DISCIPLINA\n");
                int sairDisciplina = 0;
                int opcaoDisciplina;
                while (!sairDisciplina)
                {
                    opcaoDisciplina = menuDisciplina();
                    switch(opcaoDisciplina){
                        case 0:{
                            sairDisciplina=1;
                            break;
                        }
                        case 1:
                        {
                        int retorno = cadastrarDisciplina(qtdDisciplina, listarDisciplina);
                        if(retorno==LISTA_DISCIPLINA_CHEIA){
                            printf("LISTA DE DISCIPLINAS CHEIA\n");
                        }else if(retorno==COD_DISCIPLINA_INVALIDA){
                            printf("CODIGO DE DISCIPLINA INVALIDO\n");
                        }else{
                            printf("CADASTRADO COM SUCESSO!\n");
                            qtdDisciplina++;
                        }
                        
                        break;
                        }
                        case 2:
                        {
                            listarrDisciplina(qtdDisciplina, listarDisciplina);
                            break;
                        }
                        case 3:{
                            int retorno = atualizarDisciplina(qtdDisciplina,listarDisciplina);
                            switch (retorno)
                            {
                            case COD_DISCIPLINA_INVALIDA:{
                            printf("CODIGO DE DISCIPLINA INVALIDO!\n"); break;
                            }
                            case COD_DISCIPLINA_INEXISTENTE:{
                            printf("CODIGO DE DISCIPLINA INEXISTENTE\n"); break;
                            }
                            case ATUALIZADO_DISCIPLINA_SUCESSO:{
                            printf("DISCIPLINA ATUALIZADA COM SUCESSO!\n"); break;
                            }
                            }
                            break;
                        }
                        case 4:
                        {
                            int retorno = excluirDisciplina(qtdDisciplina,listarDisciplina);
                            switch (retorno)
                            {
                                case COD_DISCIPLINA_INVALIDA:{
                                    printf("CODIGO DE DISCIPLINA INVALIDO\n");
                                    break;
                                }
                                case COD_DISCIPLINA_INEXISTENTE:{
                                    printf("CODIGO DE DISCIPLINA INEXISTENTE!\n");
                                    break;
                                }
                                case EXCLUSAO_DISCIPLINA_SUCESSO:{
                                    printf("DISCIPLINA EXCLUIDA COM SUCESSO!\n");
                                    qtdDisciplina--;
                                    break;
                                }
                            }
                        break;
                        }
                        case 5:
                        {
                            int retorno = cadastraralunodisciplina(qtdDisciplina, listarDisciplina);
                            if(retorno==DISCIPLINA_CHEIA)
                            {
                                printf("DISCIPLINA CHEIA\n");
                            }
                            else
                            {
                                printf("CADASTRADO COM SUCESSO!\n");
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
            }
        }
    return 0;
}


