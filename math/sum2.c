#include <stdio.h>

int main() {
    int N, resultado;
    
    printf("Calculo da soma dos primeiros N numeros.\nIndique N:");
    /* ler na entrada de dados, o valor N solicitado*/
    scanf("%d",&N);
    
    /* coloque em resultado a soma dos primeiros 
       N números inteiros*/
    resultado = 0;
    for(int i = 1; i <= N; i++) {
        resultado += i;
        /* a meio, mostrar o resultado parcial */
        printf("\n  adicionar %d, parcial %d", i, resultado);    
    }
    
    /* mostrar resultado final */
    printf("\nTotal: %d\n", resultado);
}