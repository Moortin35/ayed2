#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* Definitions */

    typedef int list_elem;
    /* list as a pointer to struct to guarantee encapsulation */
    typedef struct _list * list;

/* Constructors */

    list empty_list();
    //{- Crea una lista vacía. -}

    list addl(list l, list_elem e);
    //{- Agrega el elemento e al comienzo de la lista l. -}

/* Destroy */
    
    list destroy(list l);
    // {- Libera memoria en caso que sea necesario. -}

/* Operations */

    bool is_empty(list l);
    // {- Devuelve True si l es vacía. -}

    list_elem head(list l);
    /*  {- Devuelve el primer elemento de la lista l -}
        {- PRE: not is_empty(l) -} */

    list tail(list l);
    /*  {- Elimina el primer elemento de la lista l -}
        {- PRE: not is_empty(l) -} */

    list addr(list l, list_elem e);
    //{- Agrega el elemento e al final de la lista l. -}

    int length(list l);
    //{- Devuelve la cantidad de elementos de la lista l -}

    list concat(list l1, list l2);
    // {- Agrega al final de l todos los elementos de l0 en el mismo orden.-}

    list_elem index(list l, int n);
    /*  {- Devuelve el n-ésimo elemento de la lista l -}
        {- PRE: length(l) > n -} */

    list take(list l, int n);
    /*  {- Deja en l sólo los primeros n elementos, eliminando el resto -}
        {- PRE: length(l) > n -} */

    list drop(list l, int n);
    //  {- Elimina los primeros n elementos de l -}fun copy_list(l1 : List of T) ret l2 : List of T
    //  {- PRE: length(l) > n -} */

    list copy_list(list l1);
    //{- Copia todos los elementos de l1 en la nueva lista l2 -}

#endif