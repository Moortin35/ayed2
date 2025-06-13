#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

struct _list {
    elem element;
    struct _list * next;
};

struct _pepo {
    elem element;
    struct _pera fruta;
};

struct _pera {
    elem elementito;
    int peso;
};

typedef struct _pepo * pepo;

int main(){
    
    pepo perita;
    perita->fruta.elementito = 15;
    perita->fruta.peso = 12;

    return 0;

}



list empty(void){
    return NULL;
}

list addl(elem e, list l){
    list p = malloc(sizeof(struct _list));
    p->element = e;
    p->next = l;
    return p;
}

bool is_empty(list l){
    return (l ==NULL);
}

elem head(list l){
    assert(!is_empty(l));
    return l->element;
}

list tail(list l){
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
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
    if(!is_empty(l)){
        while(p->next != NULL){
            n++;
            p = p->next;
        }
    }
    return n;
}

list concat(list l, list l0){
    list p;
    list q = copy_list(l0);
    p = l;
    if(!is_empty(l)){
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }else{
        l = q;
    }
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
    int i = 0;
    if(n == 0 || length(l) >= n){
        destroy_list(l);
        l = NULL;
    }
    else{
        list p = l;
        while (i < n && p->next != NULL){
            p = p->next;
            i++;
        }
        list aux = p->next; //guardo en aux el elemento a eliminar
        p->next = NULL; // corto la lqista original
        //procedo a eliminar el resto
        list q; //puntero que uso para eliminar
        while(aux != NULL){
            q = aux;
            aux = aux->next;
            free(q);
        }
    }
    return l;
}

list drop(list l, int n){
    if (!is_empty(l) && n > 0){
        list p,q;
        p = l;
        int i = 0;
        while(i < n && p->next != NULL){
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
        l2 = addr(l2, p->element);
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
    l = NULL;
}