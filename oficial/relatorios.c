#include "disciplina.h"
#include <string.h>
#include <ctype.h>
#include "relatorios.h"
#include <stdio.h>

int menuRelatorio() {
  int opcao;
  printf("0-VOLTAR\n");
  printf("1- LISTAR ALUNOS\n");
  printf("2-LISTAR PROFESSORES\n");
  printf("3-LISTAR DISCIPLINAS SEM ALUNOS\n");
  printf("4-LISTAR DISCIPLINAS COM ALUNOS\n");
  printf("5-LISTAR ALUNOS POR SEXO:\n");
  printf("6-LISTAR ALUNOS POR ORDEM ALFABETICA:\n");
  printf("7-LISTAR ALUNOS POR DATA DE NASCIMENTO:\n");
  printf("8-LISTAR PROFESSOR POR SEXO:\n");
  printf("9-LISTAR PROFESSOR POR ORDEM ALFABETICA:\n");
  scanf("%d", &opcao);

  return opcao;
}

// Listar todos os alunos
void listarAlunosSimples(int qtdAluno, Aluno listarAluno[]) {
    printf("LISTA DE ALUNOS\n");
    if(qtdAluno==0){
        printf("LISTA VAZIA\n");
    }else{
    for (int i = 0; i < qtdAluno; i++) {
        if (listarAluno[i].ativo == 1) {
            printf("ALUNO %d:\n", i + 1);
            printf("NOME: %s\n", listarAluno[i].nome);
            printf("MATRICULA: %d\n", listarAluno[i].matricula);
            printf("SEXO: %c\n", listarAluno[i].sexo);
            printf("DATA DE NASCIMENTO: %d/%d/%d\n", listarAluno[i].diaNascimento, listarAluno[i].mesNascimento, listarAluno[i].anoNascimento);
            printf("CPF: %s\n\n", listarAluno[i].cpf);
        }
    }
    }
}
// Listar todos os professores
void listarProfessoresSimples(int qtdProfessor, Professor listarProfessor[]) {
    printf("LISTA DE PROFESSORES\n");
    if(qtdProfessor==0){
        printf("LISTA DE PROFESSORES VAZIA\n");
    }else{
    for (int i = 0; i < qtdProfessor; i++) {
        if (listarProfessor[i].ativo == 1) {
            printf("PROFESSOR %d:\n", i + 1);
            printf("NOME: %s\n", listarProfessor[i].nome);
            printf("MATRICULA: %d\n", listarProfessor[i].matricula);
            printf("SEXO: %c\n", listarProfessor[i].sexo);
            printf("DATA DE NASCIMENTO: %d/%d/%d\n", listarProfessor[i].diaNascimento, listarProfessor[i].mesNascimento, listarProfessor[i].anoNascimento);
            printf("CPF: %s\n\n", listarProfessor[i].cpf);
        }
    }
    }
}

void listarDisciplinasSimples(int qtdDisciplina, Disciplina listarDisciplina[], int qtdProfessor, Professor listarProfessor[]) {
    printf("LISTA DE DISCIPLINAS\n");
    if(qtdDisciplina==0){
        printf("LISTA DE DISCIPLINAS VAZIA\n");
    }else{
    for (int i = 0; i < qtdDisciplina; i++) {
        if (listarDisciplina[i].ativo == 1) {
            printf("DISCIPLINA %d:\n", i + 1);
            printf("NOME: %s\n", listarDisciplina[i].nome);
            printf("CODIGO: %d\n", listarDisciplina[i].coddisciplina);
            printf("PROFESSOR MATRICULADO (Matrícula: %d): ", listarDisciplina[i].matriculaprof);

            // Encontrar e imprimir o nome do professor correspondente
            int professorEncontrado = 0;
            for (int j = 0; j < qtdProfessor; j++) {
                if (listarProfessor[j].matricula == listarDisciplina[i].matriculaprof && listarProfessor[j].ativo == 1) {
                    printf("%s\n\n", listarProfessor[j].nome);
                    professorEncontrado = 1;
                    break;
                }
            }
            // Caso o professor não seja encontrado (por exemplo, se foi excluído)
            if (!professorEncontrado) {
                printf("PROFESSOR NAO ENCONTRADO\n\n");
            }
        }
    }
}
}

void listarDisciplinaComAlunos(int qtdDisciplina, Disciplina listarDisciplina[]) {
    int codDisciplina;

    // Solicitar o código da disciplina ao usuário
    printf("DIGITE O CODIGO DA DISCIPLINA QUE DESEJA LISTAR: ");
    scanf("%d", &codDisciplina);

    // Procurar pela disciplina com o código fornecido
    for (int i = 0; i < qtdDisciplina; i++) {
        // Verificar se a disciplina é ativa e corresponde ao código fornecido
        if (listarDisciplina[i].ativo == 1 && listarDisciplina[i].coddisciplina == codDisciplina) {
            printf("DISCIPLINA: %s\n", listarDisciplina[i].nome);
            printf("CODIGO: %d\n", listarDisciplina[i].coddisciplina);

            // Listar alunos matriculados na disciplina
            if (listarDisciplina[i].qtdalunosdisciplina > 0) {
                printf("ALUNOS MATRICULADOS:\n");
                for (int j = 0; j < listarDisciplina[i].qtdalunosdisciplina; j++) {
                    printf(" NOME: %s\n", listarDisciplina[i].listaALNdisciplina[j].nome);
                    printf("  MATRICULA: %d\n", listarDisciplina[i].listaALNdisciplina[j].matricula);
                    printf("  IDADE: %d\n", listarDisciplina[i].listaALNdisciplina[j].idade);
                    printf("  SEXO: %c\n", listarDisciplina[i].listaALNdisciplina[j].sexo);
                    printf("\n");
                }
            } else {
                printf("NENHUM ALUNO MATRICULADO NESTA DISCIPLINA.\n");
            }
            return;
        }
    }
    printf("DISCIPLINA NAO ENCONTRADA OU INATIVA.\n");
}

void listarAlunosPorSexo(int qtdAluno, Aluno listarAluno[]) {
    char sexo;

    // Solicita ao usuário o sexo desejado para listar os alunos
    printf("DIGITE O SEXO DOS ALUNOS QUE DESEJA LISTAR (M PARA MASCULINO, F PARA FEMININO): ");
    scanf(" %c", &sexo);

    // Converte para maiúscula manualmente, caso o usuário insira uma letra minúscula
    if (sexo >= 'a' && sexo <= 'z') {
        sexo = sexo - ('a' - 'A');
    }

    // Verifica se o usuário inseriu um valor válido para sexo
    if (sexo != 'M' && sexo != 'F') {
        printf("SEXO INVALIDO. USE 'M' PARA MASCULINO ou 'F' PARA FEMININO.\n");
        return;
    }

    // Exibe a lista de alunos do sexo especificado
    printf("LISTA DE ALUNOS POR SEXO (%c)\n", sexo);
    int encontrou = 0;

    for (int i = 0; i < qtdAluno; i++) {
        if (listarAluno[i].ativo == 1 &&
            (listarAluno[i].sexo == sexo || listarAluno[i].sexo == sexo + ('a' - 'A'))) {
            printf("NOME: %s\n", listarAluno[i].nome);
            encontrou = 1;
        }
    }

    // Caso nenhum aluno seja encontrado com o sexo especificado
    if (!encontrou) {
        printf("NENHUM ALUNO ENCONTRADO COM O SEXO ESPECIFICADO.\n");
    }
}


// Função para listar alunos em ordem alfabética
void listarAlunosOrdemAlfabetica(int qtdAluno, Aluno listarAluno[]) {
    Aluno temp;

    // Algoritmo de ordenação por seleção
    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = i + 1; j < qtdAluno; j++) {
            if (listarAluno[i].ativo == 1 && listarAluno[j].ativo == 1 && 
                strcmp(listarAluno[i].nome, listarAluno[j].nome) > 0) {
                // Troca os alunos de posição caso estejam fora de ordem
                temp = listarAluno[i];
                listarAluno[i] = listarAluno[j];
                listarAluno[j] = temp;
            }
        }
    }

    // Exibe a lista de alunos em ordem alfabética
    printf("LISTA DE ALUNOS EM ORDEM ALFABÉTICA:\n");
    for (int i = 0; i < qtdAluno; i++) {
        if (listarAluno[i].ativo == 1) {
            printf("Nome: %s\n", listarAluno[i].nome);
        }
    }
}

void ordenarAlunosPorDataNascimento(int qtdAluno, Aluno listarAluno[]) {
    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = i + 1; j < qtdAluno; j++) {
            if (listarAluno[i].anoNascimento > listarAluno[j].anoNascimento || 
               (listarAluno[i].anoNascimento == listarAluno[j].anoNascimento && listarAluno[i].mesNascimento > listarAluno[j].mesNascimento) ||
               (listarAluno[i].anoNascimento == listarAluno[j].anoNascimento && listarAluno[i].mesNascimento == listarAluno[j].mesNascimento && listarAluno[i].diaNascimento > listarAluno[j].diaNascimento)) {
                Aluno temp = listarAluno[i];
                listarAluno[i] = listarAluno[j];
                listarAluno[j] = temp;
            }
        }
    }
    listarrAlunos(qtdAluno, listarAluno);
}

// Função para listar professores por sexo
void listarProfessoresPorSexo(int qtdProfessor, Professor listarProfessor[]) {
    char sexo;

    // Solicita o sexo ao usuário
    printf("DIGITE O SEXO DOS PROFESSORES QUE DESEJA LISTAR (M/F): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);  

    printf("LISTA DE PROFESSORES POR SEXO (%c):\n", sexo);
    int encontrou = 0;  

    for (int i = 0; i < qtdProfessor; i++) {
        if (listarProfessor[i].ativo == 1 && listarProfessor[i].sexo == sexo) {
            printf("%s\n", listarProfessor[i].nome);
            encontrou = 1;
        }
    }
}
// Função para listar professores em ordem alfabética
void listarProfessoresOrdemAlfabetica(int qtdProfessor, Professor listarProfessor[]){
    Professor temp;

    // Algoritmo de ordenação por seleção
    for (int i = 0; i < qtdProfessor - 1; i++) {
        for (int j = i + 1; j < qtdProfessor; j++) {
            if (listarProfessor[i].ativo == 1 && listarProfessor[j].ativo == 1 && 
                strcmp(listarProfessor[i].nome, listarProfessor[j].nome) > 0) {
                // Troca os professores de posição caso estejam fora de ordem
                temp = listarProfessor[i];
                listarProfessor[i] = listarProfessor[j];
                listarProfessor[j] = temp;
            }
        }
    }

    // Exibe a lista de professores em ordem alfabética
    printf("LISTA DE PROFESSORES EM ORDEM ALFABÉTICA:\n");
    for (int i = 0; i < qtdProfessor; i++) {
        if (listarProfessor[i].ativo == 1) {
            printf("Nome: %s\n", listarProfessor[i].nome);
        }
    }
}
