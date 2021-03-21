#include "hw_interface.h"

// prototipos
static bool hw_is_initialized(hw_interface *interface);

// implementacao do metodo hw_run_toggle_led da hw_hardware.h
bool hw_run_toggle_led(hw_interface *interface, uint16_t seconds) {
    
    bool is_init = hw_is_initialized(interface);
    uint8_t state = 0;

    if(is_init) {
        
        // executa o metodo 'init' de 'interface'
        // o operador '->' serve para executar o metodo de uma funcao que eh um ponteiro para uma estrutura
        // se fosse declarada uma variavel ordinaria de uma estrutura, deve-se usar o operador '.' 
        interface->init();

        while(true) {
            interface->wait(seconds);
            interface->set(state);
            state ^= 0x01;
        }
    }

    return is_init;

}

static bool hw_is_initialized(hw_interface *interface) {

    bool is_config = true;

    // verifica se a interface ou seus metodos foram implementados
    if(!interface || !interface->init || !interface->wait || !interface->set) {
        is_config = false;
    }

    return is_config;
}