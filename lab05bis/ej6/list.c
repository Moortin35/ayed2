#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty(){
    list l = malloc(sizeof(struct _list));
    l->start = 0;
    l->size = 0;   
}

list addl(elem e, list l){
    assert(l->size < MAX_LENGTH);
    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e;
    l->size++;
    return l;
}

bool is_empty(list l){
    return(l->size == 0);
}

elem head(list l){
    assert(!is_empty(l));
    return l->a[l->start];
}

list tail(list l){
    assert(!is_empty(l));
    l->start = (l->start+1) % MAX_LENGTH;
    l->size--;
    return l;
}

list addr(list l, elem e){
    assert(l->size < MAX_LENGTH);
    l->a[(l->start+l->size) % MAX_LENGTH] = e;
    l->size++;
    return l;
}