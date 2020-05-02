#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

int main() {
    srand(time(NULL));
    int input;
    int r = rand() % (MAX + 1);

    printf("Guess the number\n");
    scanf("%d", &input);
    while (input != r) {    
        if (input > r) {
            printf("Too high.\n");
        }
        else if (input < r) {
            printf("Too low.\n");
        }
        scanf("%d", &input);
    }
    printf("Success!\n");

    return 0;
}
