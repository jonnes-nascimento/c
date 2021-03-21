#ifndef HW_INTERFACE_H_
#define HW_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

// define uma estrutura que sera o contrato da interface com 3 metodos
typedef struct {
    void (*init)(void); // metodo de inicializacao
    void (*wait)(uint16_t seconds); // metodo de controle de delay
    void (*set)(uint8_t state); // metodo de controle de estado do led
} hw_interface;

// prototipo da funcao para troca de estado do led
bool hw_run_toggle_led(hw_interface *interface, uint16_t seconds);

#ifdef __cplusplus
}
#endif

#endif /* HW_INTERFACE_H_ */