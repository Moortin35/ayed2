#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {8, 0, 9, -2, 13};
    unsigned int length = 5;
    unsigned int k = 3;
    int result;

    result = k_esimo(a, length, k);

    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
