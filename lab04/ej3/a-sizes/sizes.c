#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    
    data_t *messi;
    messi = calloc(1, sizeof(data_t));
    messi->age = 36;
    messi->height = 169;
    messi->name = malloc(20 * sizeof(char)); // Asigna memoria dinámica
    messi->name, "Leo Messi";       // Copia el contenido del literal a la memoria asignada

 


    /*
    print_data(messi);


    printf("name-size  : %llu bytes\n"
           "age-size   : %llu bytes\n"
           "height-size: %llu bytes\n"
           "data_t-size: %llu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));

    printf("name-size direction: %p \n"
           "age-size  direction: %p \n"
           "height-size direction: %p \n"
           "data_t-size direction: %p \n", (void *)&messi.name, (void *)&messi.age, (void *)&messi.height, (void *)&messi);
    
    printf( "name-size índice: %llu \n"
            "age-size  índice: %llu \n"
            "height-size índice: %llu \n"
            "data_t-size índice: %llu \n", (uintptr_t)&messi.name, (uintptr_t)&messi.age, (uintptr_t)&messi.height, (uintptr_t)&messi);
    */
            free(messi);
            free(messi->name); // Libera la memoria asignada para el nombre
    return EXIT_SUCCESS;
}
