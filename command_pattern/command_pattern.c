/*
    Description:
        Command pattern inspired by examples of the book of Elicia White
        'Making Embedded Systems'.
    Author:
        Jonnes Nascimento
    Date: 
        Mar,29 2021
*/

#include <stdio.h>
#include <string.h>

#define VERSION "1.2.3"

// prototypes of receivers
void cmdVersion(void);
void blinkLed(void);

// defines the function pointer type to point to a receiver
typedef void (*functionPointerType)(void);

// struct type of a command
struct commandStruct {
    const char *name;
    functionPointerType execute;
    const char *help;
};

// maps the receivers onto commands that maps receivers
const struct commandStruct commands[] = {
    {"ver", &cmdVersion, "Displays the firmware version."},
    {"blink", &blinkLed, "Blink the builtin LED in a determinated frequency (param: frequency [Hz])."}
};

int main (void) {

    char command[5];
    
    do {
        printf("Command: ");
        scanf("%s", command);

        int size = sizeof(commands) / sizeof(commands[0]);

        // this is an invoker which executes a command
        for (int i = 0; i < size; i++) {
            
            struct commandStruct cmd = commands[i];

            if (strcmp(command, cmd.name) == 0) {

                printf("Description: %s\n", cmd.help);
                
                cmd.execute();
            }
        }
    } while (strcmp(command, "exit") != 0);

    printf("Bye!\n");

    return 0;
}

// receiver
void cmdVersion(void) {
    printf("Firmware version: %s\n", VERSION);
}

// receiver
void blinkLed(void) {
    
    int state = 0, count = 0;

    while (count < 10) {

        state ^= 1;

        printf("State: %d\n", state);

        count++;
    }
}