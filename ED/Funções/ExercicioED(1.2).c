#include <stdio.h>

int primo(int n){

    int qtd=0;

    for(int i=1; i <= n; i++){

        if(n%i==0){
            qtd++;
        }
    }
    
    if(qtd == 2){
        return 1;
    }
    else
        return 0;
}

int main(){

    int num, resultado;

    printf("Digite um numero: ");
    scanf("%d", &num);

    resultado = primo(num);

    printf("%d", resultado);
  
   
    return 0;
}