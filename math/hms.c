#include <stdio.h>

int main() {
    int h, m, s, resultado;
    
    printf("Calculo do numero de segundos desde o inicio do dia.\nHora: ");
    scanf("%d", &h);
    printf("Minuto: ");
    scanf("%d", &m);
    printf("Segundos: ");
    scanf("%d", &s);
    
    resultado = (h * 3600) + (m * 60) + s;
    printf("Numero de segundos desde o inicio do dia: %d", resultado);
}