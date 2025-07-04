#include <stdio.h>

    int conta_vogais (char* str);


int main(){

    char* str = "Joao";
    int Vogais = conta_vogais(str);    
    printf("Quantidade de vogais em %s = %d", str, Vogais);

    return 0;
}
    
int conta_vogais(char* str){
    
    int i, v=0;

    for(i=0; str[i] != '\0'; i++){

        if(str[i] == 'a' || str[i] == 'A')
            v++;
        else if(str[i] == 'e' || str[i] == 'E')
            v++;
        else if(str[i] == 'i' || str[i] == 'I')
            v++;    
        else if(str[i] == 'o' || str[i] == 'O')
            v++;
        else if(str[i] == 'u' || str[i] == 'U')
            v++;            
       
    }

    return v;
}