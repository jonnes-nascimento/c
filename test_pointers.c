#include <stdio.h>
#include <stdlib.h>

void f1(int *);
void f2(int *);

int main(void) {

    int numero = 7;

    printf("Valor da variavel 'numero' = %d\n", numero);
    printf("Endereco da variavel 'numero' = %p\n", &numero);

    f1(&numero);

    printf("Valor da variavel 'numero' = %d\n", numero);
    printf("Endereco da variavel 'numero' = %p\n", &numero);

    return 0;
}

void f1(int *var) {
    printf("Valor da variavel em f1 = %d\n", *var);
    printf("Endereco da variavel em f1 = %p\n", &var);

    f2(var);
}

void f2(int *var) {
    printf("Valor da variavel em f2 = %d\n", *var);
    printf("Endereco da variavel em f2 = %p\n", &var);

    *var = 77;
}