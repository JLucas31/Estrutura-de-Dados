#include <stdio.h>
#include <stdlib.h>


int main(){




    return 0;
}

float** cria_matriz(int linhas, int colunas){

    float** matriz[linhas];
    int i;

    for(i=0; i<linhas; i++){
        matriz[i] = (float**)malloc(linhas * sizeof(int*));

        if(matriz == NULL){
            printf("Memoria insuficiente!");
            exit(1);
        }
    }

    for(i=0; i<linhas; i++){
        matriz[i] = (float*)malloc(colunas * sizeof(float));

        if(matriz == NULL){
            printf("Memoria insuficiente!");
            exit(1);
        }
    }

    return matriz;
}

float** soma_matriz(float** A, int n, int m, float** B, int o, int p){

        float** matriz_soma = (float**)malloc(sizeof(float*));


        for(int i=0; i<){
    }
}    
