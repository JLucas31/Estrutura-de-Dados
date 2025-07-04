#include <stdio.h>
#include <math.h>

    int raizes(float a, float b, float c, float* x1, float* x2){ 

        float delta;

        delta = pow(b, 2) - (4*a*c);

        if (delta == 0){ 
            *x1 = -b /(2*a);
            return 1;
        }
        else if(delta > 0){
            *x1 = (- b + sqrt(delta))/(2*a);            
            *x2 = (- b - sqrt(delta))/(2*a);
            return 2;
        }
        else { 
            return 0;
        }
    }        

    int main() {

        float a, b, c, x1, x2;

        printf("Digite o valor de a: ");
        scanf("%f", &a);
        printf("\nDigite o valor de b: ");
        scanf("%f", &b);
        printf("\nDigite o valor de c: ");
        scanf("%f", &c);

        int qtd_raizes = raizes(a, b, c, &x1, &x2);

        if(qtd_raizes == 1){
            printf("X1 = %.1f", x1);
        }
        else if(qtd_raizes == 2){
            printf("X1 = %.1f", x1);
            printf("\nX2 = %.1f", x2);
        }
        else {
            printf("Nenhuma raiz real.");
        }    


        return 0;
    }