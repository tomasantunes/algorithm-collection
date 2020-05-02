#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    algarismos(n);
}

void algarismos(n) {
    int combs[1024][3];
    int c1 = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < n; k++) {
                int comb[3];
                comb[0] = i;
                comb[1] = j;
                comb[2] = k;
                if (i + j + k == n && !checkdups(comb, combs, c1)) {
                    combs[c1][0] = i;
                    combs[c1][1] = j;
                    combs[c1][2] = k;
                    c1++;
                }
            }
        }
    }
    printf("%d", c1);
}

int checkdups(int val[3], int arr[1024][3], int size){
    for (int i = 0; i < size; i++) {
        if (exists(val[0], arr[i]) && exists(val[1], arr[i]) && exists(val[2], arr[i])) {
            return 1;
        }
    }
    return 0;
}

int exists(int val, int arr[3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i] == val) {
            return 1;
        }
    }
    return 0;
}