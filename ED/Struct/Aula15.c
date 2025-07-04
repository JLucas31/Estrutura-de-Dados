#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct aluno {
    int mat;
    char nome[80];
    char end[121];
    char tel[21];
} Aluno;

// Protótipos
void inicializa(int n, Aluno** tab);
void preenche(int n, Aluno** tab, int i);
void retira(int n, Aluno** tab, int i);
void imprime(int n, Aluno** tab, int i);
void imprime_tudo(int n, Aluno** tab);

int main(void){
    Aluno* tab[10];
    
    inicializa(10, tab);

    preenche(10, tab, 0);
    preenche(10, tab, 1);
    preenche(10, tab, 2);

    imprime_tudo(10, tab);

    retira(10, tab, 0);
    retira(10, tab, 1);
    retira(10, tab, 2);

    return 0;
}

//Inicializa o vetor de struct tab atribuindo NULL em suas posições i
void inicializa (int n, Aluno** tab){
    for(int i=0; i<n; i++)
        tab[i] = NULL;
}

void preenche (int n, Aluno** tab, int i){
    if(i<0 || i>=n){ //Se estiver fora do range do vetor, o programa encerra
        printf("Indice fora do limite do vetor\n");
        exit(1);
    }

    if(tab[i]==NULL) //Se a posição i na tab estiver como NULL, aloca-se as colunas de i 
        tab[i] = (Aluno*)malloc(sizeof(Aluno));

    printf("Entre com a matricula: ");
    scanf("%d", &tab[i]->mat);
    printf("Entre com o nome: ");
    scanf(" %[^\n]", tab[i]->nome);
    printf("Entre com o endereço: ");
    scanf(" %[^\n]", tab[i]->end);
    printf("Entre com o telefone: ");
    scanf(" %[^\n]", tab[i]->tel);
    printf("\n\n");
}

void retira(int n, Aluno** tab, int i){
    if(i<0 || i>=n){ //Se estiver fora do range do vetor, o programa encerra
        printf("Indice fora do limite do vetor\n");
        exit(1);
    }

    if(tab[i] != NULL){ //Se a posição i estiver ocupada, desaloca a memória e atribui tab[i] = NULL
        free(tab[i]);
        tab[i] = NULL;
    }
}

void imprime(int n, Aluno** tab, int i){
    if(i<0 || i>=n){ //Se estiver fora do range do vetor, o programa encerra
        printf("Indice fora do limite do vetor\n");
        exit(1);
    }

    if(tab[i] != NULL){
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereco: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

void imprime_tudo(int n, Aluno** tab){
    for(int i=0; i<n; i++){
        imprime(n, tab, i);
    }    
}