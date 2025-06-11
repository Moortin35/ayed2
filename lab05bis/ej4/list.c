#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"


typedef int elem;
typedef struct _list * list;

struct _list {
    elem element;
    struct _list * next;
};

list empty(){
    list l = malloc(sizeof(struct _list));
    return l;
}

list addl(elem e, list l){
    list p = malloc(sizeof(struct _list));
    p->element = e;
    p->next = l;
    l = p;
    return l;
}

bool is_empty(list l){
    bool b = false;
    if(l == NULL){
        b = true;
    }
    return b;
}

elem head(list l){
    assert(!is_empty(l));
    return l->element;
}

list tail(list l){
    assert(!is_empty(l));
    list p;
    p = l;
    if(p->next!= NULL){
        p = p->next;
        free(l);
        l = p;
    }
    else{
        free(l);
    }
    return l;
}

list addr(list l, elem e){
    list q = malloc(sizeof(struct _list));
    q->element = e;
    q->next = NULL;
    list p;
    if (!is_empty(l)){
        p = l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    else{
        l = q;
    }
    return l;
}

int length(list l){
    int n = 0;
    list p;
    p = l;
    while(p->next != NULL){
        n++;
        p = p->next;
    }
    return n;
}

list concat(list l, list l0){
    list p,q;
    p = l;
    q = l0;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    return l;
}

elem index(list l, int n){
    assert(n < length(l));
    int i = 0;
    list p = l;
    while(i < n){
        p = p->next;
        i++;
    }
    return p->element;
}

list take(list l, int n){
    if(n == 0 || length(l) == n){
        destroy_list(l);
        l = NULL;
    }
    else{
        for(int i = 0; i < n; i++){
            l = l->next;
        }
        list p;
	    while(l != NULL){
            p = l;
            l = l->next;
            free(p);
	    }
    }
    return l;
}

list drop(list l, int n){
    if (!(n == 0) && !(length(l) == n)){
        list p,q;
        p = l;
        int i = 0;
        while(i < n){
            q = p;
            p = p->next;
            free(q);
            i++;
        }
        l = p;
    }
    return l;
}

list copy_list(list l){
    list l2 = empty();
    list p;
    p = l;
    while(p != NULL){
        addr(l2, p->element);
        p = p->next;
    }
    return l2;
}

void destroy_list(list l){
    list p = l;
	while(l != NULL) {
		p = l;
		l = l->next;
		free(p);
	}
    return l;
}