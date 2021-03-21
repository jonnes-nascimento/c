/*
    main.c
    Este arquivo e uma implementacao da interface hw_interface para uso no PC
    Autor: Jonnes Nascimento
    Data: 21/03/2021
*/

#include "hw_interface.h"
#include <stdio.h>
#include <unistd.h>

// prototipos das funcoes que serao passadas para a interface
static void pc_init(void);
static void pc_wait(uint16_t seconds);
static void pc_set(uint8_t state);

int main(void) {

    // cria uma variavel do tipo hw_interface e associa as implementacoes das funcoes
    hw_interface intfc = {
        .init = pc_init,
        .wait = pc_wait,
        .set = pc_set
    };

    // hw_run_toggle_led esta definida em hw_interface.h e implementada em hw_interface.c
    if(hw_run_toggle_led(&intfc, 1) == false)
        printf("Ocorreu um erro.\n");

    return 0;
}

static void pc_init(void) {
    printf("Inicializando o dispositivo (PC).\n");
}

static void pc_wait(uint16_t seconds) {
    sleep(seconds);
}

static void pc_set(uint8_t state) {
    printf("State: %d\n", state);
}