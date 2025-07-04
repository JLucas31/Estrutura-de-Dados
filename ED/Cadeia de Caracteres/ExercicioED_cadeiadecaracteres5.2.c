#include <stdio.h>

    int consta_char(char* str, char* caractere);


int main(){

    char* str = "Ceara";
    char caractere = 'a';
    int Consta = consta_char(str, caractere);    
    printf("Quantidade de ocorencias de %c em %s eh = %d", caractere, str, Consta);

    return 0;
}
    
int consta_char(char* str, char* caractere){
    
    int i, c=0;

    for(i=0; str[i] != '\0'; i++){

        if(str[i] == caractere)
            c++;      
    }

    return c;
}