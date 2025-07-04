#include <stdio.h>
#include <stdlib.h>

int main(){

    int *x;

    x = malloc(sizeof(int));

    printf("%d\n", *x);

    *x = 69;

    printf("%d", *x);

    return 0;
}

