#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0){
        y = x;
    }
    else{
        y = -x;
    }
}

int main(void) {
    int a = 0;
    int res = 0;
    a = -10;
    absolute(a, res);
    //{- supongamos que print() muestra el valor de una variable -}
    printf("%d", res);
    //{- esta última asignación es análoga a `return EXIT_SUCCESS;` -}
    return EXIT_SUCCESS;
}

