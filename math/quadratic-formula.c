#include <math.h>
#include <stdio.h>

int main() {
    int a, b, c, d, k;
    double raiz1, raiz2;

    scanf("%d", &k);

    for (int i = -k; i <= k; i++) {
        for (int j = -k; j <= k; j++) {
            for (int m = -k; m <= k; m++) {
                if (i != 0 && j != 0 && m != 0) {
                    a = i;
                    b = j;
                    c = m;
                    d = b*b - 4*a*c;
                    if (d >= 0) {
                        raiz1 = (-b + sqrt(d)) / (2 * a);
                        raiz2 = (-b - sqrt(d)) / (2  *a);
                        
                        if (round(raiz1) == raiz1 && round(raiz2) == raiz2) {
                            printf("%d %d %d\n", a, b, c);
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}