#ifndef MINHAFUNCAO_H
#define MINHAFUNCAO_H




/* ========================================================================================
                                    INICIO ALUNO
======================================================================================== */

#define TAM_ALUNO 3
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_ALUNO_INVALIDA -2
#define LISTA_ALUNO_CHEIA -3
#define ATUALIZADO_ALUNO_SUCESSO -4
#define MATRICULA_ALUNO_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
#define SEXO_ALUNO_INVALIDO -7
#define MATRICULA_ALUNO_INDISPONIVEL -8
#define CPF_ALUNO_JA_CADASTRADO -9

typedef struct alu
{
    int matricula;
    char cpf[15];
    int idade;
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    char nome[20];
    char sexo;
    int ativo;
}Aluno;


//prototipos das funções aluno
int menuGeral();
int menuAluno();   
int cadastrarAluno(int qtdAluno, Aluno listarAluno[]);
void listarAlunos(int qtdAluno, Aluno listarAluno[]);
int atualizarAluno(int qtdAluno, Aluno listarAluno[]);
int excluirAluno(int qtdAluno, Aluno listarAluno[]);
void listarAlunos(int qtdAluno, Aluno listarAluno[]);

/* ========================================================================================
                                    FINAL ALUNO
======================================================================================== */





/* ========================================================================================
                                    INICIO PROFESSOR
======================================================================================== */

#define TAM_PROFESSOR 3
#define CAD_PROFESSOR_SUCESSO -1
#define MATRICULA_PROFESSOR_INVALIDA -2
#define LISTA_PROFESSOR_CHEIA -3
#define ATUALIZADO_PROFESSOR_SUCESSO -4
#define MATRICULA_PROFESSOR_INEXISTENTE -5
#define EXCLUSAO_PROFESSOR_SUCESSO -6
#define SEXO_PROFESSOR_INVALIDO -7
#define MATRICULA_PROFESSOR_INDISPONIVEL -8
#define CPF_PROFESSOR_JA_CADASTRADO -9

typedef struct prof
{
    int matricula;
    char cpf[15];
    int idade;
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    char nome[20];
    char sexo;
    int ativo;
}Professor;

//prototipos das funções professor
int menuGeral();
int menuAluno();
int cadastrarProfessor(int qtdProfessor, Professor listarProfessor[]);
void listarProfessor(int qtdProfessor, Professor listarProfessor[]);
int atualizarProfessor(int qtdProfessor, Professor listarProfessor[]);
int excluirProfessor(int qtdProfessor, Professor listarProfessor[]);
void listarProfessor(int qtdProfessor, Professor listarProfessor[]);



/* ========================================================================================
                                    FINAL PROFESSOR
======================================================================================== */



/* ========================================================================================
                                    INICIO DISCPLINA
======================================================================================== */

#define TAM_DISCIPLINA 3
#define CAD_DISCIPLINA_SUCESSO -1
#define COD_DISCIPLINA_INVALIDA -2
#define LISTA_DISCIPLINA_CHEIA -3
#define ATUALIZADO_DISCIPLINA_SUCESSO -4
#define COD_DISCIPLINA_INEXISTENTE -5
#define EXCLUSAO_DISCIPLINA_SUCESSO -6
#define COD_DISCIPLINA_INDISPONIVEL -8

typedef struct discip
{
    int coddisciplina;
    int diaAtual, mesAtual, anoAtual;
    char nome[20];
    int ativo;
}Disciplina;

//prototipos das funções professor
int menuDisciplina();
int cadastrarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
void listarrDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
int atualizarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
int excluirDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);

/* ========================================================================================
                                    FINAL DISCIPLINA
======================================================================================== */



#endif // MINHAFUNCAO