#include <stdio.h>

int main() {
    int N, F;
    printf("Calculo do produto dos primeiros N numeros.\nIndique N:");
    scanf("%d", &N);
    F = 1;
    for (int i = 1; i <= N; i++) {
        F *= i;
        printf("  Factorial(%d)=%d\n", i, F);
    }
    printf("Resultado: %d", F);
}