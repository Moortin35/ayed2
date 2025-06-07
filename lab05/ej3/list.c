#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

struct _list {
    list_elem elem;
    struct _list * next;
};

list empty_list(){  
    list l = malloc(sizeof(struct _list));
    return l;
}

list addl(list l, list_elem e){
    list p = malloc(sizeof(struct _list));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

list destroy(list l){
    list p;
    if (l->next != NULL){
        while(l->next != NULL){
            p = l;
            l = l->next;
            free(p);
        }
    }
    else{
        p = l;
        free(p);
    }
    l = NULL;
    return l;
}

bool is_empty(list l){
    return (l == NULL);
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;
}

list addr(list l, list_elem e){
    list p;
    list q = malloc(sizeof(struct _list));
    q->elem = e;
    q->next = NULL;
    if(!is_empty(l)){
        p = l;
        while (p->next != NULL){
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
    list p;
    int n = 0;
    p = l;
    while(p->next != NULL){
        n++;
        p = p->next;
    }
    return n;
 }

 list concat(list l1, list l2){
    list p,q;
    q = l2;
    if(!is_empty(l1)){
        p = l1;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    else{
        l1 = q;
    }
    return l1;
 }

list_elem index(list l, int n){
    list p;
    int contador = 0;
    p = l;
    while(contador != n-1){
        p = p->next;
        contador++;
    }
    list_elem e = p->elem;
    return e;
}

list take(list l, int n){
    list p;
    if(!is_empty(l)){
        int i = 0;
        p = l;
        while (i < n && p->next != NULL){
            p = p->next;
            i++;
        }
        list q;
        q = p->next;
        while (q->next != NULL){
            free(p);
            p = q;
            q = q->next;
        }
    }
    return l;
}

list drop(list l, int n){
    int i = 0;
    list p;
    while (i < n && !(is_empty(l))){
        p = l;
        l = p->next;
        free(p);
        i++;
    }
    return l;
}

list copy_list(list l1){
    list l2 = empty_list();
    list p;
    p = l1;
    while (p != NULL){
        addr(l2, p->elem);
        p = p->next;
    }
    return l2; 
}