#include <stdio.h>

int main()
{
    int n;
    int i;
    int s = 0;
    
    printf("Enter a Number:\n");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        
        if (i % 3 == 0 || i % 5 == 0) {
            s += i;
        }
    }
    
    printf("Sum = %d\n", s);
    return 0;
}
