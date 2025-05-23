#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    messi = malloc(sizeof(data_t));
    messi->age = 37;
    messi->height = 169;
    strcpy(messi->name, "Leo Messi");
    
    print_data(*messi);

    printf("name-size  : %lu bytes\n"
       "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi->name), sizeof(messi->age), sizeof(messi->height), sizeof(messi));

    printf("name-size direction: %p \n"
           "age-size  direction: %p \n"
           "height-size direction: %p \n"
           "data_t-size direction: %p \n", (void *)&messi->name, (void *)&messi->age, (void *)&messi->height, (void *)&messi);
    
    printf( "name-size índice: %lu \n"
            "age-size  índice: %lu \n"
            "height-size índice: %lu \n"
            "data_t-size índice: %lu \n", (uintptr_t)&messi->name, (uintptr_t)&messi->age, (uintptr_t)&messi->height, (uintptr_t)&messi);


    free(messi);
    return EXIT_SUCCESS;
}
