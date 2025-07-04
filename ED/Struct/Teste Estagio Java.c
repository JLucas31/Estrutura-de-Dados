#include <stdio.h>

int getBattery(int n, int porcentagem, int* eventos);

int main(){

    int Porcentagem_inicial, Porcentagem_final, qtd;

    printf("Digite a porcentagem inicial de bateria do laptop: ");
    scanf("%d", &Porcentagem_inicial);

    printf("Digite a quantidade de eventos: ");
    scanf("%d", &qtd);

    int Eventos[qtd];

    for(int i=0; i<qtd ; i++){

        printf("Digite o numero de minutos do evento[%d](positivo para carregando e negativo para jogando): ", i);
        scanf("%d", &Eventos[i]);
        printf("\n\n");
    }

    Porcentagem_final = getBattery(qtd, Porcentagem_inicial, Eventos);

    printf("Porcentagem apos os eventos: %d", Porcentagem_final);

    return 0;
}

int getBattery(int n, int porcentagem, int* eventos){

    int porcentagem_f = porcentagem;

    for(int i=0; i<n; i++)
    {
        porcentagem_f = porcentagem_f + eventos[i];

        if(porcentagem_f > 100)
            porcentagem_f = 100;

        else if(porcentagem < 0)
            porcentagem_f = 0;    
    }

    return porcentagem_f;
}    