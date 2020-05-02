#include <math.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    primo(n);
}

int primo(n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            printf("%d\n", i);
            return;
        }
    }
    printf("0");
}