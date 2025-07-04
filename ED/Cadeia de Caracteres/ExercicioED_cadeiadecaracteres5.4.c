#include <stdio.h>

    void shift_string(char* str);

int main(){

    char str[] = "";
    shift_string(str);

    return 0;
}
    
void shift_string(char* str){

    for(int i=0; str[i] != '\0'; i++){

        if(str[i] >= 'A' && str[i] <= 'z'){
            if (str[i] == 'Z')
                str[i] = 'A'-1; 
            else if (str[i] == 'z')
                str[i] = 'a'-1;
        
            if (str[i] < 'A' && str[i] > 'z')
                str[i] = str[i];   
            
            str[i] = str[i] + 1;    
        } 

        printf("%c", str[i]);
             
    }

}