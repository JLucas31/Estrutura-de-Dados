#include <stdio.h>

int Fibonacci(int n){

    int n1=1, n2 = 1, prox;

            for(int i=3; i <= n; i++){
                
                prox = n1 + n2;
                n1 = n2;
                n2 = prox;
            }

        return prox;
    }    

int main(){

    int nesimo, resultado;

    printf("Digite o n-esimo numero da sequencia de Fibonacci = ");
    scanf("%d", &nesimo);

    resultado = Fibonacci(nesimo);

    printf("%d", resultado);  
   
    return 0;
}

