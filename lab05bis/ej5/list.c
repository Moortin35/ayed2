#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(){
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}


list addl(elem e, list l){
    assert(!(l->size == MAX_LENGTH));  
    for(int i = l->size-1; i >= 0;i --){
        l->elems[i+1] = l->elems[i];
    }
    l->elems[0] = e;
    l->size++;
    return l;
}

bool is_empty(list l){
    return (l->size == 0);
}

elem head(list l){
    assert(!is_empty(l));
    return l->elems[0];
}

list tail(list l){
    assert(!is_empty(l));
    for(int i = 0; i < l->size ;i++){
        l->elems[i] = l->elems[i+1];
    }
    l->size--;
    return l;
}

list addr(list l, elem e){
    l->elems[l->size] = e;
    l->size++;
    return l;
}

int length(list l){
    return l->size;
}

list concat(list l, list l0){
    for (int i = 0; i < l0->size; i++){
        l->elems[l->size+i] = l0->elems[i];
    }
    l->size = l->size + l0->size;
    return l;
}


elem index(list l, int n){
    assert(n < length(l));
    return l->elems[n];
}

list take(list l, int n){
    assert(n <= l->size);
    l->size = n;
    return l;
}

list drop(list l, int n){
    assert(n <= l->size);
    for(int i = 0; i < n-1; i++){
        l->elems[i] = l->elems[i+(n-1)];
    }
    l->size = l->size - n;
    return l;
}


list copy_list(list l){
    list l2 = empty();
    for (int i = 0; i < l->size; i++){
        l2->elems[i] = l->elems[i];
    }
    l2->size = l->size;
    return l2;
}

void destroy_list(list l){
    free(l);
}