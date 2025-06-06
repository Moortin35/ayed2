#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"

static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq;
    unsigned int i = izq+1;
    unsigned int j = der;
    while(i <= j){
        if (goes_before(a[i],a[pivot])){
            i++;
        }
        else if (goes_before(a[pivot], a[j])){
            j--;
        }
        else{
            swap(a,i,j);
            i++;
            j--;
        }        
    }
    swap(a, pivot, j);
    pivot = j;
    return pivot;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq;
    if (der > izq){
        pivot = partition(a, izq, der);
        if (pivot == 0){
            quick_sort_rec(a, pivot+1, der);
        }
        else{
            quick_sort_rec(a, izq, pivot-1);
            quick_sort_rec(a, pivot+1, der);
        }
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}