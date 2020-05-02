#include <stdio.h>

int main() {
    int N, F;
    int fib[128];
    printf("Calculo do valor da funcao Fibonacci:\n");
    printf("Indique N:");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        if (i == 1 || i == 2) {
            F = i;
            fib[i] = F;
        }
        else {
            F = fib[i - 1] + fib[i - 2];
            fib[i] = F;
            printf("  Fib(%d)=%d\n", i, fib[i]);
        }
    }
    printf("Resultado: %d", F);
}