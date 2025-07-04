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
int qtd_maior_n(Lista* l, int n);
int lst_ultimo_no(Lista* l);
Lista* concatena(Lista* l1, Lista* l2);
Lista* lst_tira_valor(Lista* l, int n);
Lista* lst_separa(Lista* l, int n);

int main(){

    Lista* lista = cria();
    Lista* lista2 =  cria();
    Lista* Concat = cria();
    Lista* separada = cria();
    int num_escolhido;
   
    for(int i=1; i<11; i++){
        lista = lst_insere(lista, i);
    }

    for(int i=11; i<21; i++){
        lista2 = lst_insere(lista2, i);
    }

    printf("LISTA\n");

    lst_imprime(lista);

    int comprimento = lst_comprimento(lista);

    printf("O comprimento da lista eh %d\n\n", comprimento);

    printf("Digite um numero para saber quantos numeros da lista sao maiores que ele: ");
    scanf("%d", &num_escolhido);

    int qtd_maior_num = qtd_maior_n(lista, num_escolhido);

    printf("A quantidade de numeros maior que %d eh %d\n\n", num_escolhido, qtd_maior_num);

    int ultimo = lst_ultimo_no(lista);

    printf("O ultimo no da lista eh: %d\n\n", ultimo);

    Concat = concatena(lista, lista2);

    printf("Lista concatenada: \n");
    lst_imprime(Concat);
    printf("\n\n");

    separada = lst_separa(lista, 5);

    printf("Lista original: \n");
    lst_imprime(lista);
    printf("Lista Separada no numero escolhido\n");
    lst_imprime(separada);

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

    Lista* p;
    int i=0;

    for(p = l; p != NULL; p = p->prox){
        i++;
    }

    return i;
}

int qtd_maior_n(Lista* l, int n){

    Lista* p;
    int i=0;

    for(p = l; p != NULL; p = p->prox){     
        if(p->dado > n)
            i++;
    }

    return i;
}

int lst_ultimo_no(Lista* l){

    Lista* p;
    Lista* u;

    for(p = l; p != NULL; p = p->prox){
        if(p->prox == NULL){
            u = p;
        }
    }
    
    return u->dado;
}

Lista* concatena(Lista* l1, Lista* l2){

        Lista* p = l1;

        if(l1 == NULL)
            return l2;

        while(p->prox != NULL){
            p = p->prox;
        }
        
        p->prox = l2;

    return l1;

}

Lista* lst_tira_valor(Lista* l, int n){

    Lista* ant = NULL; //Ponteiro que aponta para o nó anterior
    Lista* p = l; //Ponteiro p para auxiliar na navegação da lista

    while(p != NULL && p->dado != n){ //Percorre a lista verificiando se a posição atual da lista é diferente de n
        ant = p; //Se for diferente de n, o nó atual vai para posição anterior
        p = p->prox; //E a posição atual recebe o próximo
    }

    if (p == NULL) //Se o valor não foi encontrado
        return l; //Retorna a lista original

    if(ant == NULL){ // Se o valor a ser removido é o primeiro da lista
        l = p->prox; // O início da lista passa a ser o segundo nó
    }
    else {
        ant->prox = p->prox; // O nó anterior agora aponta para o próximo do nó removido
    }
    free(p); //Libera a memória alocada do nó removido
    return l;  
}

Lista* lst_separa(Lista* l, int n) {
    Lista* p = l;

    // Se a lista estiver vazia
    if (p == NULL)
        return NULL;

    while (p != NULL && p->dado != n) {
        p = p->prox;
    }

    if (p == NULL || p->prox == NULL)
        return NULL; // valor n não encontrado ou último elemento

    Lista* nova_lista = p->prox;
    p->prox = NULL; // separa a lista

    return nova_lista;
}

    

