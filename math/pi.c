#include <math.h>
#include <stdio.h>

long double factorial(n) {
    double f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    double pi;
    int k;
    double sum = 0;
    
    scanf("%d", &k);
    for (int i = 0; i <= k; i++) {
        sum += factorial(4 * i) * (1103 + 26390 * k) / (pow(factorial(i), 4) * pow(396, 4 * i));
    }
    
    pi = 1/(2 * sqrt(2) / 9801 * sum);
    printf("%.16f", pi);
}
