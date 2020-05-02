#include <stdio.h>
int main() {
    int n;
    int i;

    printf("Enter a positive integer: ");
    scanf("%d",&n);

    for (i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

int isPrime(n) {
    int i;
    int is_prime = 1;

    for(i = 2; i <= n / 2; i++) {
        if(n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    
    return is_prime;
}
