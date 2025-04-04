#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

unsigned int globVar_length;

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
    unsigned int pivot = izq;
    if (der > izq){
        //array_dump(a, length);
        pivot = partition(a, izq, der);
        array_dump(a, length);
        if (pivot == 0){
            quick_sort_rec(a, pivot+1, der, length);
        }
        else{
            quick_sort_rec(a, izq, pivot-1, length);
            quick_sort_rec(a, pivot+1, der, length);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    array_dump(a, length);
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);

}

