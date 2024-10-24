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
#define ALUNO_EXISTE -10

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
void listarrAlunos(int qtdAluno, Aluno listarAluno[]);
int atualizarAluno(int qtdAluno, Aluno listarAluno[]);
int excluirAluno(int qtdAluno, Aluno listarAluno[]);
void listarrAlunos(int qtdAluno, Aluno listarAluno[]);
int verificarAluno(int qtdAluno, Aluno listarAluno[], int * matriculaaluno);

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
#define PROFESSOR_EXISTE -10

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
void listarrProfessor(int qtdProfessor, Professor listarProfessor[]);
int atualizarProfessor(int qtdProfessor, Professor listarProfessor[]);
int excluirProfessor(int qtdProfessor, Professor listarProfessor[]);
void listarrProfessor(int qtdProfessor, Professor listarProfessor[]);
int verificarProfessor(int qtdprofessor,Professor listarProfessor[], int * matriculaprof);



/* ========================================================================================
                                    FINAL PROFESSOR
======================================================================================== */



/* ========================================================================================
                                    INICIO DISCPLINA
======================================================================================== */

#define TAM_DISCIPLINA 3
#define TAM_DA_DISCIPLINA 1
#define CAD_DISCIPLINA_SUCESSO -1
#define COD_DISCIPLINA_INVALIDA -2
#define LISTA_DISCIPLINA_CHEIA -3
#define ATUALIZADO_DISCIPLINA_SUCESSO -4
#define COD_DISCIPLINA_INEXISTENTE -5
#define EXCLUSAO_DISCIPLINA_SUCESSO -6
#define COD_DISCIPLINA_INDISPONIVEL -8
#define DISCIPLINA_EXISTE -10
#define CAD_ALUNO_DISCIPLINA_SUCESSO -11
#define DISCIPLINA_CHEIA -12

typedef struct discip
{
    int coddisciplina;
    int diaAtual, mesAtual, anoAtual;
    char nome[20];
    int matriculaprof;
    int ativo;
    Aluno listaALNdisciplina[TAM_DA_DISCIPLINA]; //!Lista de alunos DENTRO da disciplina
    int qtdalunosdisciplina;
}Disciplina;

//prototipos das funções professor
int menuDisciplina();
int cadastrarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
void listarrDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
int atualizarDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
int excluirDisciplina(int qtdDisciplina, Disciplina listarDisciplina[]);
int verificadorDisciplina(int qtdDisciplina, Disciplina listarDisciplina[], int * coddisciplina);
void zerandoqtdalunosdiscplina(Disciplina listarDisciplina[]);

/* ========================================================================================
                                    FINAL DISCIPLINA
======================================================================================== */


    Aluno listarAluno[TAM_ALUNO]; //! Lista de alunos BRUTA
    Professor listarProfessor[TAM_PROFESSOR];
    Disciplina listarDisciplina[TAM_DISCIPLINA];

    int opcao;
    int sair = 0; //falso
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int qtdDisciplina = 0;
    
    
// MINHAFUNCAO
#endif