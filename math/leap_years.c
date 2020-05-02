#include <stdio.h>

int main() {
    int current_year;
    int end_year;
    int year;
    
    printf("Enter current year:\n");
    scanf("%d", &current_year);
    printf("Enter end year:\n");
    scanf("%d", &end_year);
    printf("Leap years:\n");
    for (year = current_year; year <= end_year; year++) {
        if (year % 4 == 0) {
            printf("%d\n", year);
        }
    }
}
