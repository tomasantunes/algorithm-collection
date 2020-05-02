#include <stdio.h>

int main()
{
    int n;
    int i;
    int s = 0;
    int f = 1;
    char str[80];
    printf("Enter a positive integer:\n");
    scanf("%d", &n);
    printf("(S)um or (F)actorial?\n");
    scanf("%s", str);
    
    if (strcmp(str, "S") == 0) {
        for (i = 1; i <= n; i++) {
            s += i;
        }
        printf("Sum = %d\n", s);
    }
    else if (strcmp(str, "F") == 0) {
        for (i = 1; i <= n; i++) {
            f *= i;
        }
        printf("Factorial = %d\n", f);
    }
    else {
        printf("Invalid operation\n");
    }

    return 0;
}
