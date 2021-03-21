/*
    interface_model.ino
    Este arquivo e uma implementacao da interface hw_interface para uso no Arduino Uno
    Autor: Jonnes Nascimento
    Data: 21/03/2021
*/

#include <Arduino.h>
#include "hw_interface.h"

// prototipos das funcoes que serao passadas para a interface
static void arduino_init(void);
static void arduino_wait(int seconds);
static void arduino_set(uint8_t state);

#define LED_PIN 13

// associa as funcoes a interface
hw_interface intfc = {
    .init = arduino_init,
    .wait = arduino_wait,
    .set = arduino_set
};

// funcao setup() do arduino
void setup(){

}

// funcao loop() do arduino
void loop() {
    // executa o metodo hw_run_toggle_led implementado em hw_interface.c
    hw_run_toggle_led(&intfc, 1);
}

static void arduino_init(void) {
    pinMode(LED_PIN, OUTPUT);
}

static void arduino_wait(int seconds) {
    delay(seconds * 1000);
}

static void arduino_set(uint8_t state) {
    digitalWrite(LED_PIN, state);
}
