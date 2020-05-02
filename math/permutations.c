#include <stdio.h>
#include <math.h>

int main() {
    int N, R, a;
    printf("Calculo dos arranjos de N, R a R:\n");
    printf("Indique N:");
    scanf("%d", &N);
    printf("Indique R:");
    scanf("%d", &R);
    if (N > R) {
        a = 1;
        for (int i = R; i <= N; i++) {
            a *= i;
            printf("  i=%d; arranjos=%d\n", i, a);
        }
        printf("Resultado: %d", a);
    }
    else {
        printf("Erro: N tem de ser maior que R e este maior que 0.");
    }
}