#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct _list{
    elem elem; //Elemento del nodo
    struct _list* next; //Puntero que apunta al siguiente nodo de la lista
};
/* 
    Definición de lo que es un nodo, o elemento de lista, con su elemento y puntero
    Colocado en la implementación para garantizar encapsulamiento.
*/

//-----------------------CONSTRUCTORS------------------------------

/* Crea una lista vacía */
list empty(void){
   return NULL;
}

/* Agrega un elemento e al inicio de la lista l */
list addl(elem e, list l){
    list new_node = malloc(sizeof(list)); //Reservo memoria para otro nodo
    new_node->elem = e; //Al contenido del elem le asigno 'e'
    new_node->next = l; //Conecto por izquierda el nodo a la lista que tenía

    return new_node; //Devuelvo la lista final
}

//------------------------OPERATIONS-------------------------------

/* Determina si una lista es vacía */
bool is_empty(list l){
    return l == NULL;
}

/*
    Devuelve el primer elemento de la lista l
    PRE: !is_empty(l)
*/
elem head(list l){
    assert(!is_empty(l)); //Verifico PRECONDICIÓN
    elem e = l->elem; //Le asigno el primer elemento de la lista a e
    
    return e; //Lo devuelvo
}

/*
    Elimina el primer elemento de la lista l
    PRE: !is_empty(l)
*/
list tail(list l){
    assert(!is_empty(l)); //Verifico PRECONDICIÓN
    list fst_node = l; //Guardo el primer elemento
    l = l->next; //Paso al siguiente
    free(fst_node); //Elimino el primer elemento

    return l; //Devuelvo la l modificada
}

/* Agrega el elemento e al final de la lista l */
list addr(list l, elem e){
    list search; //Puntero para ir recorriendo la lista
    list new_node; //Nodo a agregar
    new_node = malloc(sizeof(list)); //Reservo memoria para el nuevo nodo
    
    new_node->elem = e; //Asigno el elemento
    new_node->next = NULL; //De momento no apunta a nada
    
    //Nos posicionamos en el último nodo de la lista con search, y agregamos por derecha a new_node
    if(!is_empty(l)){
        search = l;
        while(search->next != NULL){
            search = search->next;
        }
        search->next = new_node;
    }else{
        l = new_node;
    }

    return l; //Devolvemos la lista modificada

}

/* Calcula el largo de la lista l */
int length(list l){
    list search = l; //Puntero de búsqueda
    int n = 0; //Variable contador

    //Por cada elemento que encontremos, incrementamos en 1 n
    while(search != NULL){
        n++;
        search = search->next;
    }

    return n; //Devolvemos el largo
}

/* Agrega al final de l1 todos los elementos de l2 */
list concat(list l, list l0){
    list result,search; //Creo un puntero para la lista concatenada y otro para conectar ambas listas
    
    result = l; //Inicio siempre desde l1

    //Primer caso: La primer lista es vacía, entonces directamente la concatenacion es la segunda
    if(is_empty(l)){
        result = l0;
    }else{ //Segundo caso, hay una primer lista no vacia y hay que recorrerla
        search = l;
        while(search->next != NULL){
            search = search->next;
        }
        search->next = l0;
    }

    return result;
}

/*
    Devuelve el n-ésimo elemento de la lista l
    PRE: length(l) > n && n>0
*/
elem index(list l, int n){
    assert(length(l) > n); //Verifico PRECONDICIÓN
    
    list search = l; //Declaro puntero de búsqueda del n-ésimo elemento
    int i = 0; //Variable contador para determinar cuando llegué

    //Mientras no haya llegado al valor necesario, sigo incrementando
    while(i<n){
        search = search->next;
        i++;
    }

    return search->elem; //Devuelvo el elemento
}

/* Deja en l solo los primeros n elementos, eliminando el resto*/
list take(list l, int n){
    //Un puntero para recorrer, el otro para eliminar y otro para devolver el resultado:
    list search;
    list kill; 
    list result; 
    int i; //Indice para ir recorriendo la lista
    result = l; //Apuntamos al inicio de la lista
    //Si la lista es vacía no habría nada que eliminar
    if(!is_empty(l)){
        //Si tomamos 0 elementos, eliminamos todo:
        if(n == 0){
            while(l != NULL){
                kill = l;
                l = l->next;
                free(kill);
            }
            result = NULL; //Eliminamos todo, asi que nos queda la lista vacía
        }else if(n > 0){
            search = l;
            i = 1;
            //Buscamos el n-ésimo elemento:
            while(i < n && search->next != NULL){
                search = search->next;
                i++;
            }
            //Cortamos la lista en el n-ésimo elemento:
            list aux = search->next;
            search->next = NULL;

            //Eliminamos los posteriores al n-ésimo elemento con el puntero auxiliar:
            while(aux!= NULL){
                kill = aux;
                aux = aux->next;
                free(kill);
            }
        }
    }

    return result; //Devolvemos la lista modificada
}

/* Elimina los primeros n elementos de la lista l, dejando el resto*/
list drop(list l, int n){
    list kill; //Un puntero para eliminar

    //Si la lista es vacía no se puede eliminar nada
    if(!is_empty(l) && n!=0){
        while(n>0 && l!=NULL){ //Vamos contando con n los nodos que vamos eliminando, y cuando se elimine el último ya está
            kill = l;
            l = l->next;
            free(kill);
            n--; //Idea de chatgpt, ingenioso :0
        }
    }

    return l;
}

/* Copia la lista l en otra completamente nueva */
list copy_list(list l){
    /*
        NOTA: node* y list son lo mismo practicamente, uso uno u otro para mayor
        comodidad según lo que quiero hacer referencia
    */
    list search;
    list l_copy = empty();

    search = l;

    while(search != NULL){
        l_copy = addr(l_copy, search->elem);
        search = search->next;
    }

    return l_copy;
}

/* Libera memoria en caso de ser necesario */
void destroy_list(list l){
    list kill;

    while(l != NULL){
        kill = l;
        l = l->next;
        free(kill);
    }
}




