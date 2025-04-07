#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

bool tiene_cima(int a[], int length) {
    bool tiene_cima = false;

    if (length == 1){
        tiene_cima = true;
    }
    else{

        int i = 0;
        while (i < length && a[i] <= a[i+1]){
            i++;
        }
        
        int j = length-1;
        while (j > 0 && a[j-1] >= a[j]) {
            j--;
        };
        if (i == j && (i != length-1 && i != 0) && (j != length-1 && j != 0)){
            tiene_cima = true;
        }
    }
    return tiene_cima;
}

int cima_sec(int array[], int length){
    int i = 0;
    //
    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    while(i < length && array[i] <= array[i+1]){
        printf("Comparo el valor de %d y de %d\n",array[i], array[i+1]);
        i++;
    }
    printf("El valor de la cima es: %d y su indice es: %d\n", array[i], i);
    printf("\n");
    return i;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {

    //assert(tiene_cima(a, length));
    int cima = cima_sec(a,length);

    return cima;
}
