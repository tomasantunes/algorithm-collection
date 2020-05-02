#include <stdio.h>

int main() {
    
    int numbers[5] = { 10, 8, 4, 99, 2 };
    int max = getMax(numbers, 5);
    printf("%d\n", max);

    return 0;
}

int getMax(int arr[], int len) {
    int n;
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] > n) {
            n = arr[i];
        }
    }
    return n;
}
