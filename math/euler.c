#include <stdio.h>

int main() {
    int n, d;
    double e;
    
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            d = 1;
            e = 1.0;
        }
        else {
            d = d * i;
            e = e + (1.0 / d);
        }
    }
    
    printf("%g", e);
}