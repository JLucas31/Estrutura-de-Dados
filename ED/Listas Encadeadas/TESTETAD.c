#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA.h"

int main() {
    Lista* minha_lista = cria();

    minha_lista = lst_insere(minha_lista, 1);
    minha_lista = lst_insere(minha_lista, 2);
    minha_lista = lst_insere(minha_lista, 3);

    lst_imprime(minha_lista);

    return 0;
}
