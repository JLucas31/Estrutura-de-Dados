#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;           // Valor/dado do nó da lista
    struct lista* prox; // Ponteiro para o próximo nó (O ponteiro tem que ser do mesmo tipo da struct em que ele está)
};

typedef struct lista Lista;

// Funções declaradas
Lista* lst_cria();
Lista* lst_insere(Lista* l, int i);
Lista* lst_insere_ordenado(Lista* l, int i);
Lista* lst_retira(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
void lst_libera(Lista* l);
Lista* lst_busca(Lista* l, int v);
int lst_igual(Lista* l1, Lista* l2);

int main(){
    Lista* minha_lista1 = lst_cria();
    Lista* minha_lista2 = lst_cria(); // Cria a lista inicialmente vazia
    Lista* minha_lista_att;
    int escolha_retira, num, iguais;

    for(int i=0; i<5000; i++)
        minha_lista1 = lst_insere(minha_lista1, i); // Insere elementos na lista

    lst_imprime(minha_lista1); // Imprime os elementos da lista
    lst_imprime(minha_lista2);

    printf("# Buscando na lista #\n");
    printf("Digite o valor a ser buscado: ");
    int valor_busca = 0;
    scanf("%d", &valor_busca);

    printf("Elemento ");

    if(lst_busca(minha_lista1, valor_busca))  // Chama a função para buscar um valor na lista
        printf("encontrado...\n");
    else
        printf("não encontrado...\n");

    printf("Gostaria de retirar um elemento da lista [sim = 1 | nao = 2]: ");
    scanf("%d", &escolha_retira);

    switch(escolha_retira){
        case 1:
            printf("Escolha o numero que deseja retirar: ");
            scanf("%d", &num);
            minha_lista_att = lst_retira(minha_lista1, num);
            lst_imprime(minha_lista_att);
            break;
        case 2:
            lst_imprime(minha_lista1);
            break;
    }

    iguais = lst_igual(minha_lista1, minha_lista2);

    switch (iguais)
    {
    case 1:
        printf("Sao iguais");
        break;
    default:
        printf("Sao diferentes");
        break;
    }

    lst_libera(minha_lista1);
    lst_libera(minha_lista2); // Libera a memória alocada para a lista

    return 0;
}

// Cria uma lista vazia e retorna um ponteiro para ela (NULL indica lista vazia)
Lista* lst_cria(){
    return NULL;
}

// Insere um novo elemento no início/na cabeça da lista
Lista* lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista)); // Aloca memória para um novo nó/elemento

    if(!novo){  // Verifica se a alocação foi bem-sucedida
        printf("Não foi possível inserir novo elemento...\n");
        exit(1);  // Encerra o programa caso não consiga alocar memória
    }

    novo->info = i;  // Atribui o valor ao campo 'info' do novo nó
    novo->prox = l;  // O ponteiro 'prox' do novo nó aponta para o início da lista (pode ser NULL)

    return novo;  // Retorna o novo nó que agora é o início da lista
}

// Imprime todos os elementos da lista
void lst_imprime(Lista* l){
    Lista* p; // Ponteiro auxiliar para percorrer a lista

    for(p = l; p != NULL; p = p->prox)  // Enquanto p não for NULL (fim da lista)
        printf("info: %d\n", p->info);  // Imprime o valor do nó
}

// Verifica se a lista está vazia
int lst_vazia(Lista* l){
    return l == NULL;  // Retorna 1 (verdadeiro) se a lista estiver vazia, 0 caso contrário
}

// Libera toda a memória alocada para a lista
void lst_libera(Lista* l){
    Lista* p = l;

    while(p != NULL){  // Enquanto houver elementos na lista
        Lista* t = p->prox; // Salva o ponteiro para o próximo elemento
        free(p); // Libera a memória do nó atual
        p = t; // Move para o próximo nó
    }
}

// Busca um elemento na lista e retorna um ponteiro para o nó encontrado, ou NULL se não encontrado
Lista* lst_busca(Lista* l, int v){
    for(Lista* p = l; p != NULL; p = p->prox)  // Percorre a lista
        if(p->info == v)  // Se o valor for encontrado
            return p;  // Retorna o ponteiro para o nó encontrado

    return NULL;  // Retorna NULL se não encontrar o valor
}

// Retira um elemento da lista (se encontrado)
Lista* lst_retira(Lista* l, int v){
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info != v){  // Busca o valor na lista
        ant = p;  // O ponteiro 'ant' aponta para o nó anterior
        p = p->prox;  // Move para o próximo nó
    }

    if (p == NULL)  // Se o valor não foi encontrado
        return l;  // Retorna a lista original sem alterações

    if(ant == NULL){  // Se o valor a ser removido é o primeiro da lista
        l = p->prox;  // O início da lista passa a ser o segundo nó
    }
    else {
        ant->prox = p->prox;  // O nó anterior agora aponta para o próximo do nó removido
    }
    free(p);  // Libera a memória do nó removido
    return l;  // Retorna a lista com o nó removido
}

// Insere um elemento na lista de forma ordenada
Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista));  // Cria o novo nó
    Lista* ant = NULL;  // Ponteiro para o nó anterior
    Lista* p = l;  // Ponteiro para percorrer a lista

    // Encontra o local adequado para inserir o novo nó
    while(p != NULL && p->info < v){  // Enquanto o valor do nó for menor que v
        ant = p;  // O ponteiro 'ant' recebe o valor de 'p'
        p = p->prox;  // O ponteiro 'p' avança para o próximo nó
    }

    novo->info = v;  // Atribui o valor ao novo nó
    novo->prox = p;  // O ponteiro 'prox' do novo nó aponta para o nó atual (que será maior que o novo nó)

    if(ant == NULL){  // Se o nó anterior for NULL, significa que o novo nó será o primeiro da lista
        l = novo;  // O início da lista passa a ser o novo nó
    }
    else {  // Se o nó anterior não for NULL, o novo nó é inserido após o nó anterior
        ant->prox = novo;  // O nó anterior passa a apontar para o novo nó
    }

    return l;  // Retorna a lista com o novo nó inserido
}

int lst_igual(Lista* l1, Lista* l2){

    Lista* p1 = l1;
    Lista* p2 = l2;

    for(p1= l1, p2 = l2; p1 != NULL && p1 != NULL; p1 = p1->prox, p2 = p2->prox)
        if(p1->info != p2->info)
            return 0;
        else    
            return 1;    
}


