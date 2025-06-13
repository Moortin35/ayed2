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

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

