


#define TAM_ALUNO 3
#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZADO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6
#define SEXO_INVALIDO -7

typedef struct alu
{
    int matricula;
    char nome[20];
    char sexo;
    int ativo;
}Aluno;