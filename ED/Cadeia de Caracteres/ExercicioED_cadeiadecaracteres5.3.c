#include <stdio.h>

    void minusculo(char* str);

int main(){

    char str[] = "SaMsUnG";
    minusculo(str);

    return 0;
}
    
void minusculo(char* str){

    for(int i=0; str[i] != '\0'; i++){

        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;

        printf("%c", str[i]);
             
    }

}