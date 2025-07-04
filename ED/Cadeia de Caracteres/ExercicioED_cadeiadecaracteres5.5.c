#include <stdio.h>

    void string_oposta(char* str); 

int main(){

    char str[] = "ABCDE";
    string_oposta(str);

    return 0;
}
    
void string_oposta(char* str){

    char posicao, oposto;

    for(int i=0; str[i] != '\0'; i++){

        if(str[i] >= 'A' && str[i] <= 'Z'){
            posicao = str[i] - 'A'; //Acha a posicao de str[i] relativa ao alfabeto (tira 65 do valor correspondente da str[i])
            oposto = 25 - posicao; //Acha a posicao relativa do caractere oposto ao alfabeto (subtrai 25 da posicao relativa da posicao relativa do caractere oposto)
            str[i] = 'A' + oposto; //Adicionando 'A'(65) a posicao relativa do oposto se encontra o caractere oposto (Adiciona +65 a posicao relativa do caractere oposto)    
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
            posicao = str[i] - 'a'; //Acha a posicao de str[i] relativa ao alfabeto (tira 97 do valor correspondente da str[i])
            oposto = 25 - posicao; //Acha a posicao relativa do caractere oposto ao alfabeto (subtrai 25 da posicao relativa da posicao relativa do caractere oposto)
            str[i] = 'a' + oposto; //Adicionando 'a'(97) a posicao relativa do oposto se encontra o caractere oposto (Adiciona +97 a posicao relativa do caractere oposto)   

        if(str[i] < 'A' && str[i] > 'z'){
            str[i] = str[i];
        } 

        printf("%c", str[i]);
             
    }

}