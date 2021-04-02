/*
    Description: 
        State machine implemented using switch-case block.
        The state toggle is fired by an user key press.
        This test is for implements this state machine:

            (init) -> (a) -> (b) -> (c)
              ^                      |
              |______________________|

    Author: 
        Jonnes Nascimento
    Date: 
        2021, 1, April
*/

#include <stdlib.h>
#include <stdio.h>

// defines
#define INITIAL_STATE 0
#define STATE_A      1
#define STATE_B      2
#define STATE_C      3

// prototypes
void executeStateMachine(void);

// globals
volatile char actualState;

int main(void) {

    actualState = INITIAL_STATE;

    while(1) {
        executeStateMachine();
    }

    return 0;
}

void executeStateMachine(void) {

    char keyPressed;

    // clears the stdin (keyboard) buffer
    fflush(stdin);

    // simulates the event that changes the state
    keyPressed = getche();

    switch(actualState) {

        case INITIAL_STATE:

            if (keyPressed == 'a') {
                actualState = STATE_A;
            } else if (keyPressed == 'x') { // it's just for control of THIS code (exists the main loop)
                printf("\nBye!\n");
                exit(0);
            } else {
                printf("\nWaiting by 'a' char (received %c). Stay into initial state.\n", keyPressed);
            }

            break;

        case STATE_A:
        
            if(keyPressed == 'b') {
                actualState = STATE_B;
            } else {
                printf("\nWaiting by 'b' char (received %c). Returning to initial state.\n", keyPressed);
                actualState = INITIAL_STATE;
            }

            break;

        case STATE_B:
        
            if(keyPressed == 'c') {
                actualState = STATE_C;
            } else {
                printf("\nWaiting by 'c' char (received %c). Returning to initial state.\n", keyPressed);
                actualState = INITIAL_STATE;
            }

            break;

         case STATE_C:
        
            if(keyPressed == 'd') {
                printf("\nSequence OK!\n");
            } else {
                printf("\nWaiting by 'd' char (received %c). Returning to initial state.\n", keyPressed);
            }

            actualState = INITIAL_STATE;

            break;

        default:

            actualState = INITIAL_STATE;

    }

}