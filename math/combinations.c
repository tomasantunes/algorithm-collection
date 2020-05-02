#include <stdio.h>

int main() {
    int N, R, F, C;
    printf("Calculo das combinacoes de N, R a R:\n");
    printf("Indique N:");
    scanf("%d", &N);
    printf("Indique R:");
    scanf("%d", &R);
    F = 1;
    C = 1;
    for(int i = N - R + 1; i <= N; i++) {
        int n1 = F * i;
        int n2 = n1 / C;
        printf("  %d*%d=%d, %d/%d=%d\n", F, i, n1, n1, C, n2);
        F = n2;
        C++;
    }
    printf("Resultado: %d", F);
}