#include <stdio.h>

#define USER1 "Alice"
#define USER2 "Bob"

int main()
{
    char name[80];
    printf("What's your name?\n");
    scanf("%s", name);
    
    if (strcmp(name, USER1) == 0 || strcmp(name, USER2) == 0) {
        printf("Hello, %s!\n", name);
    }
    else {
        printf("Access Denied\n");
    }

    return 0;
}
