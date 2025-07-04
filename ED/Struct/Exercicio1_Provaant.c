#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    float x;
    float y;
}Ponto;

Ponto** cria_pontos(int n, Ponto** lista_pontos);
void preenche_pontos(int n, Ponto** lista_pontos);
Ponto* centro_geo(Ponto** lista_pontos, int n);
void libera_lista_pontos(int n, Ponto** lista_pontos);

int main(){

    int num;

    printf("Digite o numero de pontos: ");
    scanf("%d", &num);

        Ponto* pontos[num];

    cria_pontos(num, pontos);
    preenche_pontos(num, pontos);

    Ponto* centro_geometrico = centro_geo(pontos, num);

    printf("(CENTRO GEOMETRICO = (%.1f, %.1f)", centro_geometrico->x, centro_geometrico->y);

    libera_lista_pontos(num, pontos);

    free(centro_geometrico);
    centro_geometrico = NULL;

    return 0;
}

Ponto** cria_pontos(int n, Ponto** lista_pontos){ //Inicializa as linhas do vetor de struct poontos
    for(int i=0; i<n; i++){
        lista_pontos[i] = NULL;
    }
    
    return lista_pontos;
}

void preenche_pontos(int n, Ponto** lista_pontos){
    for(int i=0; i<n; i++){
        if(i<0 || i>=n){
            printf("Indice fora do alcance do vetor!");
            exit(1);
        }

        if(lista_pontos[i] == NULL){
            lista_pontos[i] = (Ponto*)malloc(sizeof(Ponto));
        }

        printf("Digite a coordenada de x do ponto #%d: ", i+1);
            scanf("%f", &lista_pontos[i]->x);
        printf("Digite a coordenada de y do ponto #%d: ",  i+1);
            scanf("%f", &lista_pontos[i]->y);
        printf("\n\n"); 
    }       
}

Ponto* centro_geo(Ponto** lista_pontos, int n){

    Ponto* centro_geo = (Ponto*)malloc(sizeof(Ponto));
    float media_x = 0.0;
    float media_y = 0.0;

    for(int i=0; i<n; i++){
        media_x += lista_pontos[i]->x;
        media_y += lista_pontos[i]->y;
    }

    centro_geo->x = media_x/(float)n;
    centro_geo->y = media_y/(float)n;

    return centro_geo;
}

void libera_lista_pontos(int n, Ponto** lista_pontos){

    for(int i=0; i<n; i++){
        if(i<0 || i>=n){
        printf("Indice fora do limite do vetor\n");
        exit(1);
    }
        if(lista_pontos[i] != NULL){
            free(lista_pontos[i]);
            lista_pontos[i] = NULL;
        }

    }
}
