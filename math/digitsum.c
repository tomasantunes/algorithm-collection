#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int soma;
    char *N = (char*) malloc(128);
    printf("Calculo da soma do quadrado dos digitos de um numero:\n");
    printf("Numero: ");
    scanf("%s", N);
    soma = 0;
    for (int i = strlen(N); i > 0 ; i--) {
        char *sub = (char*) malloc(128);
        strncpy(sub, N, i);
        soma += pow(strlen(sub), 2);
        printf("  n=%s; soma=%d\n", sub, soma);
    }
    printf("Resultado: %d", soma);
}