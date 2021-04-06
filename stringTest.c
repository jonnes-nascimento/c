#include <stdlib.h>
#include <string.h>

int main(void) {

    char str[10] = "Jonnes!";

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }

    printf("\n");
    
    // strlen is in string.h
    for (int i = 0, n = strlen(str); i < n; i++) {
        printf("%c", str[i]);
    }

    return 0;
}