#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    float x,y;
}Ponto;

//Prototipos das Funções
Ponto* cria_ponto();
void ler_ponto(Ponto* p);
int dentroret (Ponto* v1, Ponto* v2, Ponto* p);

int main(){

    Ponto* p = cria_ponto();
    Ponto* v1 = cria_ponto();
    Ponto* v2 = cria_ponto();

    printf("----COORDENADAS DO VERTICE 1----\n");
    ler_ponto(v1);
    printf("----COORDENADAS DO VERTICE 2----\n");
    ler_ponto(v2);
    printf("----COORDENADAS DO PONTO----\n");
    ler_ponto(p);
    
    int result = dentroret(v1, v2, p);

    switch(result){
        case 0:
            printf("O Ponto esta fora do retangulo");
            break;
        case 1:
            printf("O ponto esta dentro do retangulo");
            break;
        default:
            printf("Error");
            break;        
    }
//Libera a memória alocada dos pontos
    free(p);
    free(v1);
    free(v2);
    
    return 0;
}

//Função cria ponto alocando memória dinamicamente (não precisa de parâmetros)
Ponto* cria_ponto(){
    
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    if(!p){
        printf("Memória insuficiente...");
        exit(1);
    }
}

//Função lê as coordenadas do ponto
void ler_ponto(Ponto* p){
    
    printf("Digite a coordenada x do ponto: ");
    scanf("%f", &p->x);

    printf("Digite a coordenada y do ponto: ");
    scanf("%f", &p->y);
    printf("\n");
}

//Função verifica se o ponto está dentro do retângulo (se sim, retorna 1, se não, retorna 0)
int dentroret (Ponto* v1, Ponto* v2, Ponto* p){

    if(p->x > v1->x && p->y > v1->y && p->x < v2->x && p->y < v2->y)
        return 1;
    else
        return 0;        
}


