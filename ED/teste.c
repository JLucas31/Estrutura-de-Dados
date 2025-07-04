#include <stdio.h>

int main(){

    int x = 4; //Declaracao da variavel inteira x que armazena o valor 4;
    int *ptr = &x; //Declaracao do ponteiro ptr do tipo inteiro que aponta pro conteudo contido no endereco de x;
    ptr = &x; //Atribuicao de ptr ao endereco da variavel x;

    printf("Conteudo de x = %d\n", x); //Exibe o conteudo da variavel;
    printf("Endereco de x = %p\n", &x); //Exibe o endereco da variavel;
    printf("Conteudo apontado por ptr = %p\n", *ptr); //Exibe o conteudo do endereco apontado por ptr;
    printf("Endereco apontado por ptr = %p\n", ptr); //Autoexplicativo;
    printf("Endereco de ptr = %p\n", &ptr); //Exibe o endereco de ptr.

    return 0;
}

