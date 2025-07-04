#include <stdio.h>

void roda_string(char* str); 

int main(){

    char str[] = "Pedra";
    roda_string(str);

    return 0;
}
    
void roda_string(char* str){

    int i, l=0;

    for(i=0; str[i] != '\0'; i++){ //For para achar o tamanho da string 

        l++;
    }

    char ultimo = str[l-1]; //Variavel temporaria que armazena o ultimo caractere da string

    for(i=l-2; str[i] >= 0; i--){ //Movendo os caracteres para direita (Percorrendo a string da direita pra esquerda, ou seja, do ultimo para o primeiro)

        str[i+1] = str[i]; //O caractere a direita recebe o caractere a esquerda
    }
    str[0] = ultimo; //A primeira posicao recebe o ultimo caractere
    
    for(i=0; str[i] != '\0'; i++){ //Mostra a nova string
        
        printf("%c", str[i]);
    }

}

