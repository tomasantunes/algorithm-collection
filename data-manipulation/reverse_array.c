#include <stdio.h>

int main() {
    
    int arr[5] = {1, 2, 3, 4, 5};
    int i;
    
    for (i = 0; i < 5; i++) {
        if (i < 5 / 2) {
            int a = arr[i];
            int b = arr[4-i];
            arr[i] = b;
            arr[4-i] = a;
        }
        else {
            int a = arr[i];
            int b = arr[4-i];
            arr[i] = a;
            arr[4-i] = b;
        }
        printf("%d\n", arr[i]);
    }

    return 0;
}
