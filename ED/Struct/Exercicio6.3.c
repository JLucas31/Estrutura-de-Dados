#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[81];
    char matricula[8];
    char turma[6];
    float p1, p2, p3;
}Aluno;

//Protótipos das funções
Aluno* cria_aluno();
void preenche_aluno(Aluno* tab);
float media_aluno(Aluno* tab);
void exibe_info_aluno(Aluno* tab, float m);

int main(void){

    Aluno* aluno = cria_aluno();
    float media;

    preenche_aluno(aluno);

    media = media_aluno(aluno);

    exibe_info_aluno(aluno, media);

    free(aluno);
    
    return 0;
}

//Cria o aluno alocando memória dinamicamente (não precisa de parâmetros)
Aluno* cria_aluno(){
    Aluno* t = (Aluno*)malloc(sizeof(Aluno));
     if (t == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    return t; //Retorna o ponteiro tipo aluno
}

void preenche_aluno(Aluno* tab) {
    
    printf("Digite o nome do aluno: ");
    fgets(tab->nome, sizeof(tab->nome), stdin);
    tab->nome[strcspn(tab->nome, "\n")] = '\0'; // Remove o '\n' que o fgets pode deixar

    printf("Digite a matricula do aluno: ");
    fgets(tab->matricula, sizeof(tab->matricula), stdin);
    tab->matricula[strcspn(tab->matricula, "\n")] = '\0'; // Remove o '\n'

    printf("Digite a turma do aluno: ");
    fgets(tab->turma, sizeof(tab->turma), stdin);
    tab->turma[strcspn(tab->turma, "\n")] = '\0'; // Remove o '\n'
}

float media_aluno(Aluno* tab){

    float media;
    
    printf("Digite nota p1: ");
    scanf("%f", &tab->p1);
    printf("Digite nota p2: ");
    scanf("%f", &tab->p2);
    printf("Digite nota p3: ");
    scanf("%f", &tab->p3);

    media = (tab->p1 + tab->p2 + tab->p3)/3; 

    return media;

}

void exibe_info_aluno(Aluno* tab, float m){

    printf("Nome: %s\n", tab->nome);
    printf("Matricula: %s\n", tab->matricula);
    printf("Turma: %s\n", tab->turma);
    printf("Nome: %s\n", tab->nome);
    printf("Media final: %f", m);
}

