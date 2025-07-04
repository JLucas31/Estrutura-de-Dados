#include <stdio.h>
#include <stdlib.h>

struct lista{
    int dado;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* cria();
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_comprimento(Lista* l);

int main(){

    Lista* lista = cria();
   
    
    for(int i=0; i<5; i++){
        lista = lst_insere(lista, i);
    }

    printf("LISTA\n");

    lst_imprime(lista);

     int comprimento = lst_comprimento(lista);

    printf("O comprimento da lista eh %d", comprimento);

    return 0;
}

Lista* cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, int i){
    
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    
    if(!novo){  // Verifica se a alocação foi bem-sucedida
        printf("Não foi possível inserir novo elemento...\n");
        exit(1);  // Encerra o programa caso não consiga alocar memória
    }

    novo->dado = i;  // Atribui o valor ao campo 'info' do novo nó
    novo->prox = l;  // O ponteiro 'prox' do novo nó aponta para o início da lista (pode ser NULL)

    return novo;  // Retorna o novo nó que agora é o início da lista

}

void lst_imprime(Lista* l){
    
    Lista* p;

    for(p = l; p != NULL; p = p->prox){

        printf("%d ", p->dado);

    }

}

int lst_comprimento(Lista* l){

    Lista* p = l;
    int i=0;

    for(p = l; p != NULL; p = p->prox){
        i++;
    }

    return i;
}