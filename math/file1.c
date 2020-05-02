#include <stdio.h>

int main()
{
printf("Calculo dos arranjos de N, R a R:");

int N, R, i=N-R+1, Resultado=1;
printf("\nIndique N:");
scanf("%d", &N);
printf("Indique R:");
scanf("%d", &R);

if(N<R || R<1)
printf("Erro: N tem de ser maior que R e este maior que 0.");

else
{
i=N-R+1;
Resultado=1;
while(i<=N)
{
Resultado = Resultado*i;
printf(" i=%d; arranjos=%d\n", i, Resultado);
i++;
}
printf("Resultado: %d", Resultado);
}
}