#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct Person {
    char nome[10];
    uint8_t age;
    uint8_t height;
    void(*show)(struct Person *);
};

void person_print(struct Person *self) {
    printf("nome: %s age: %d height: %d\n", self->nome, self->age, self->height);
}

// esta declaracao diz que newPerson retorna um ponteiro para a estrutura Person (struct Person *)
struct Person * newPerson(char name[], uint8_t age, uint8_t height) {
    
    struct Person *self = (struct Person *) malloc(sizeof(struct Person));
    strcpy(self->nome, "Fabio");
    self->age = 43;
    self->height = 172;

    self->show = &person_print;

    return self;
}

int main(void) {
    struct Person *person2 = newPerson("Fabio", 43, 172);

    person2->show(person2);

    return 0;
}