#include <stdio.h>

int main() {
    float n;
    int two, one, pfifty, ptwenty, pten, pfive, ptwo, pone;
    printf("Introduza um montante em euros, podendo ter centimos: "); 
    scanf("%f", &n);

    int cents = n * 100;

    two = cents / 200;
    cents %= 200;
    
    if (two > 0) {
        printf("2 euros: %d\n", two);
    }

    one = cents / 100;
    cents %= 100;
    
    if (one > 0) {
        printf("1 euro: %d\n", one);
    }

    pfifty = cents / 50;
    cents %= 50;
    
    if (pfifty > 0) {
        printf("50 centimos: %d\n", pfifty);
    }
    
    ptwenty = cents / 20;
    cents %= 20;
    
    if (ptwenty > 0) {
        printf("20 centimos: %d\n", ptwenty);
    }
    
    pten = cents / 10;
    cents %= 10;
    
    if (pten > 0) {
        printf("10 centimos: %d\n", pten);
    }
    
    pfive = cents / 5;
    cents %= 5;
    
    if (pfive > 0) {
        printf("5 centimos: %d\n", pfive);
    }
    
    ptwo = cents / 2;
    cents %= 2;
    
    if (ptwo > 0) {
        printf("2 centimos: %d\n", ptwo);
    }
    
    pone = cents / 1;
    cents %= 1;
    
    if (pone > 0) {
        printf("1 centimo: %d\n", pone);
    }

    return 0;
}