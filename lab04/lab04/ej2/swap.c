#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int x, y;
    x = 6;
    y = 4;
    printf("valor de x es: %d, el valor de y es: %d\n", x,y);
    swap(&x, &y);
    printf("valor de x es: %d, el valor de y es: %d\n", x,y);
    return 0;
}

/*
proc swap(in/out a : int, in/out b : int)
    var aux : int
    aux := a
    a := b  
    b := aux
end proc

fun main() ret r : int
    var x, y : int
    x := 6
    y := 4
    print(x, y)
    swap(x, y)
    print(x, y)
    r := 0
end fun
*/