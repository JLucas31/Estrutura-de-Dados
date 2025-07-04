#include <stdio.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){

    if(x > x0 && x < x1){
        if(y > y0 && y < y1){
            return 1;
        }
    }
    else
        return 0;
}

int main(){

    int x0, y0, x1, y1, x, y, resultado;

    printf("Digite os valores da vertice x0,y0 = ");
    scanf("%d %d", &x0, &y0);
    printf("\nDigite os valores da vertice x1,y1 = ");
    scanf("%d %d", &x1, &y1);

    printf("\nDigite as cordenadas do ponto x,y = ");
    scanf("%d %d", &x, &y);

    resultado = dentro_ret(x0, y0, x1, y1, x, y);

    printf("%d", resultado);
   
    return 0;
}