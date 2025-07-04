#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicio(char **nomes, int n){
    int i;
    for(i=0; i<n; i++){
        __fpurge(stdin);
        printf("Nome %d", i);
        fgets(nomes[i]);
    }
}

void escreve(char **nomes, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%s\n", nomes[i]);
    }
}


int main(){

    char** nomes;
    int n, i, size;

    printf("Quantidade de strings: ");
    scanf("%d", &n);

    nomes = malloc(n*sizeof(char*));

    printf("Tamanho de cade string: ");
    scanf("%d", &size);

    for(i=0; i<n ; i++){
        nomes[i] = malloc(n*sizeof(char));
    }

    inicio(nomes, n);

    escreve(nomes, n);

    //desalocando a memoria

    for(i=0; i<n ; i++){
        free(nomes[i]);
        free(nomes);
    }

    return 0;
}


