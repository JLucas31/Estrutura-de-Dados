#include <stdio.h>
#include <stdlib.h>

struct lista {
    int dado;
    struct lista *prox;
};

typedef struct lista Lista;

// Declarações
Lista *cria();
Lista *lst_insere_ordenado(Lista *l, int i);
void lst_imprime(Lista *l);
int lst_comprimento(Lista *l);
int qtd_maior_n(Lista *l, int n);
int lst_ultimo_no(Lista *l);
Lista *concatena(Lista *l1, Lista *l2);
Lista *lst_tira_valor(Lista *l, int n);
Lista *lst_separa(Lista *l, int n);
Lista *lst_merge(Lista *l1, Lista *l2);

// --------------------- Função principal ---------------------
int main() {
    Lista *lista = cria();
    Lista *lista2 = cria();
    Lista *Concat = cria();
    Lista *separada = cria();
    Lista *Merge = cria();
    int num_escolhido;

    for (int i = 1; i < 11; i++) {
        lista = lst_insere_ordenado(lista, i);
    }

    for (int i = 11; i < 21; i++) {
        lista2 = lst_insere_ordenado(lista2, i);
    }

    printf("LISTA 1:\n");
    lst_imprime(lista);

    printf("LISTA 2:\n");
    lst_imprime(lista2);

    int comprimento = lst_comprimento(lista);
    printf("O comprimento da lista eh %d\n\n", comprimento);

    printf("Digite um numero para saber quantos numeros da lista sao maiores que ele: ");
    scanf("%d", &num_escolhido);

    int qtd_maior_num = qtd_maior_n(lista, num_escolhido);
    printf("A quantidade de numeros maior que %d eh %d\n\n", num_escolhido, qtd_maior_num);

    int ultimo = lst_ultimo_no(lista);
    printf("O ultimo no da lista eh: %d\n\n", ultimo);

    Concat = concatena(lista, lista2);
    printf("Lista concatenada:\n");
    lst_imprime(Concat);

    separada = lst_separa(lista, 5);
    printf("Lista original:\n");
    lst_imprime(lista);
    printf("Lista separada a partir do valor 5:\n");
    lst_imprime(separada);

    Merge = lst_merge(lista, lista2);
    printf("Lista mesclada:\n");
    lst_imprime(Merge);

    return 0;
}

// --------------------- Funções auxiliares ---------------------

Lista *cria() {
    return NULL;
}

Lista* lst_insere_ordenado(Lista* l, int n) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->dado < n) {
        ant = p;
        p = p->prox;
    }

    novo->dado = n;
    novo->prox = p;

    if (ant == NULL) {
        l = novo;
    } else {
        ant->prox = novo;
    }

    return l;
}

void lst_imprime(Lista *l) {
    Lista *p = l;
    while (p != NULL) {
        printf("%d ", p->dado);
        p = p->prox;
    }
    printf("\n\n");
}

int lst_comprimento(Lista *l) {
    int i = 0;
    for (Lista *p = l; p != NULL; p = p->prox) {
        i++;
    }
    return i;
}

int qtd_maior_n(Lista *l, int n) {
    int i = 0;
    for (Lista *p = l; p != NULL; p = p->prox) {
        if (p->dado > n)
            i++;
    }
    return i;
}

int lst_ultimo_no(Lista *l) {
    if (l == NULL) return -1; // lista vazia
    Lista *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p->dado;
}

Lista* concatena(Lista* l1, Lista* l2) {
    Lista* nova = cria();
    Lista* fim = NULL;

    for (Lista* p = l1; p != NULL; p = p->prox) {
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->dado = p->dado;
        novo->prox = NULL;

        if (nova == NULL) {
            nova = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    for (Lista* p = l2; p != NULL; p = p->prox) {
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->dado = p->dado;
        novo->prox = NULL;

        if (nova == NULL) {
            nova = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    return nova;
}

Lista* lst_tira_valor(Lista* l, int n) {
    Lista* nova = cria();
    for (Lista* p = l; p != NULL; p = p->prox) {
        if (p->dado != n) {
            nova = lst_insere_ordenado(nova, p->dado);
        }
    }
    return nova;
}

Lista* lst_separa(Lista* l, int n) {
    Lista* nova = cria();
    int copiar = 0;

    for (Lista* p = l; p != NULL; p = p->prox) {
        if (copiar)
            nova = lst_insere_ordenado(nova, p->dado);
        if (p->dado == n)
            copiar = 1;
    }

    return nova;
}

Lista* lst_merge(Lista* l1, Lista* l2) {
    Lista* nova = cria();
    Lista* fim = NULL;

    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL) {
            Lista* novo = (Lista*)malloc(sizeof(Lista));
            novo->dado = l1->dado;
            novo->prox = NULL;

            if (nova == NULL) {
                nova = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }

            l1 = l1->prox;
        }

        if (l2 != NULL) {
            Lista* novo = (Lista*)malloc(sizeof(Lista));
            novo->dado = l2->dado;
            novo->prox = NULL;

            if (nova == NULL) {
                nova = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }

            l2 = l2->prox;
        }
    }

    return nova;
}
