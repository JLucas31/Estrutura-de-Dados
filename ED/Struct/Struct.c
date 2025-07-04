#include <stdio.h>

//Struct Data criada com typedef, sem ter que ser chamada na main com Struct (como se eu tivese criado um tipo de variável)
typedef struct {
    int dia, mes, ano;
}Data;

//Função para imprimir a data a partir do ponteiro de Data
void imprimeData(Data *x){
        printf("%d/%d/%d", x->dia, x->mes, x->ano);//Pra manipulação de ponteiro pra data, utiliza-se "->"
}

int main(){

    Data data; //Variável do tipo data criada
    Data *p; //Declaração do ponteiro de data

    p = &data;

    printf("data: %p\tp: %p\n", &data, p); //Imprime o endereço de data e a variável p, que contém o endereço de data

    //Atribui os valor aos objetos de data
    data.dia = 31;
    data.mes = 07;
    data.ano = 2005;

    printf("Data impressa na main: %d/%d/%d\n\n", data.dia, data.mes, data.ano);
    printf("Data impressa na funcao: ");
    imprimeData(p);


    return 0;
}
