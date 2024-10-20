#ifndef MINHAFUNCAO_H
#define MINHAFUNCAO_H

#define TAM_ALUNO 3
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZADO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
#define SEXO_INVALIDO -7
#define MATRICULA_INDISPONIVEL -8
#define CPF_CADASTRADO -9


typedef struct alu
{
    int matricula;
    char cpf[15];
    char dataNascimento[12];
    char nome[20];
    char sexo;
    int ativo;
}Aluno;


//prototipos das funções
int menuGeral();
int menuAluno();   
int cadastrarAluno(int qtdAluno, Aluno listarAluno[]);
void listarAlunos(int qtdAluno, Aluno listarAluno[]);
int atualizarAluno(int qtdAluno, Aluno listarAluno[]);
int excluirAluno(int qtdAluno, Aluno listarAluno[]);
void listarAlunos(int qtdAluno, Aluno listarAluno[]);

#endif // MINHAFUNCAO_H