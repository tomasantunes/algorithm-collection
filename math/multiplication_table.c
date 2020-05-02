#include <stdio.h>

int main() {
    int table[13][13];
    int y;
    int x;
    
    for (y = 1; y <= 12; y++) {
        for (x = 1; x <= 12; x++) {
            table[y][x] = y * x;
        }
    }
    
    printf("-------------------------------------------------------------------------\n");
    for (y = 1; y <= 12; y++) {
        for (x = 1; x <= 12; x++) {
            if (table[y][x] < 10) {
                printf("| %d   ", table[y][x]);
            }
            else if (table[y][x] >= 10 && table[y][x] < 100) {
                printf("| %d  ", table[y][x]);
            }
            else {
                printf("| %d ", table[y][x]);
            }
        }
        printf("|\n-------------------------------------------------------------------------\n");
    }
    
    return 0;
}
