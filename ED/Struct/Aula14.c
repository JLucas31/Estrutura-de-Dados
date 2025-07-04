#include <stdio.h>
#include <math.h>

typedef struct ponto{ //Cria uma estrutura do tipo ponto;
    float x,y;
}Ponto;

void pontos_figura(int n, Ponto* p);

float area_figura(int n, Ponto* p);

int main(){

    int qtd;

    printf("Digite a quantidade de pontos que a figura: "); 
    scanf("%d", &qtd);

    Ponto fig[qtd];

    pontos_figura(qtd, fig);

    float area = area_figura(qtd, fig);


    printf("Area da figura: %.2f", area);

    return 0;
}


void pontos_figura(int n, Ponto* p){ //Preenche um vetor de estrutura ponto

    int i;

    for(i=0; i<n; i++){

        printf("Digite as coordenadas do ponto %d (x,y): "); 
        scanf("%f %f", &p[i].x, &p[i].y); //Preenche as coordenadas dos pontos, como mexemos com valores ao invés de endereços, utilizamos '&' ao invés de '->'
        printf("\n");
    }
}        

float area_figura(int n, Ponto* p){

    int i, j;
    float a =0;

    for(i=0; i<n; i++){

        j = (i+1) % n;
        a+= (p[j].x - p[i].x) * (p[i].y + p[j].y)/2; //Quebra a figura em trapézios e calcula suas áreas e acumula as áreas em a    
    }
    
    return fabs(a); //Retorna o valor absoluto da Área (o módulo)

}

