/*
    Description: 
        State machine implemented using function pointer.
        The state toggle is fired by an user key press.
        This test is for implements this state machine:

            (init) -> (a) -> (b) -> (c)
              ^                      |
              |______________________|

    Author: 
        Jonnes Nascimento
    Date: 
        2021, 2, April
*/

#include <stdlib.h>
#include <stdio.h>

// globals
void (*funcActualState)(void);

// prototypes
void initialState(void);
void stateA(void);
void stateB(void);
void stateC(void);

int main(void) {

    // call the initial state;
    funcActualState = initialState;

    while(1) {

        // calls the function that funcActualState points to
        (*funcActualState)();
    }

    return 0;
}

void initialState(void) {

    char keyPressed;

    // clears the stdin (keyboard) buffer
    fflush(stdin);

    keyPressed = getche();

    if (keyPressed == 'a') {        
        funcActualState = stateA;
    } else if (keyPressed == 'x') {
        printf("\nBye!\n");
        exit(0);
    } else {
        printf("\nWaiting by 'a' char (received %c). Stay into initial state.\n", keyPressed);
    }
}

void stateA(void) {

    char keyPressed;

    fflush(stdin);

    keyPressed = getche();

    if (keyPressed == 'b') {
        funcActualState = stateB;
    } else {
        printf("\nWaiting by 'b' char (received %c). Returning to initial state.\n", keyPressed);
        funcActualState = initialState;
    }
}

void stateB(void) {

    char keyPressed;

    fflush(stdin);

    keyPressed = getche();

    if (keyPressed == 'c') {
        funcActualState = stateC;
    } else {
        printf("\nWaiting by 'c' char (received %c). Returning to initial state.\n", keyPressed);
        funcActualState = initialState;
    }
}

void stateC(void) {

    char keyPressed;

    fflush(stdin);

    keyPressed = getche();

    if(keyPressed == 'd') {
        printf("\nSequence OK!\n");
    } else {
        printf("\nWaiting by 'd' char (received %c). Returning to initial state.\n", keyPressed);
    }

    funcActualState = initialState;
}