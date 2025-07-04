#include <stdio.h>

int soma_impares(int n){

    int sum=0;

    for(int i=1; i <= n; i++){
        
        if(i % 2 != 0){
            sum += i;
        }
    }
    
    return sum;

}    

int main(){

    int num, resultado;

    printf("Digite um numero: ");
    scanf("%d", &num);

    resultado = soma_impares(num);

    printf("%d", resultado);
   
    return 0;
}

