#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc == 2) {

        for(int i = 0; argv[1][i] != '\0'; i++) {
            printf("%c\n", argv[1][i]);
        }
    } else {
        return 1;
    }

    return 0;
}