#include <stdbool.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], unsigned int izq, unsigned int der);
bool goes_before(int x, int y);
void swap(int a[], unsigned int i, unsigned int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], unsigned int length, unsigned int k) {

    unsigned int izq = 0;
    unsigned int der = length-1;
    unsigned int piv;
    int elem;

    piv = partition(a, izq, der);
        
    while(piv != k){
        if (piv < k){
            izq = piv+1;
        }
        else{
            der = piv-1;
        }
        piv = partition(a, izq, der);
    }
    elem = a[piv];
    return elem;
}

int partition(int a[], unsigned int izq, unsigned int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
