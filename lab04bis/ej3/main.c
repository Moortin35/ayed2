#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    int i; //largo de la lista
    List l; //lista a retornar
    Node *p; //puntero p para trabajar
    /*
    printf("Inserte largo de la lista: "); //Ingreso el largo de la lista
    scanf("%d", &i);
    */
    i = 3;
    l = malloc(sizeof(Node)); //inicializo la lista
    p = l; //asigno el puntero p a l para poder iterar   
    i--; //Primer nodo construído.

    while(i > 0){
        p->data = i*10;
        p->next = malloc(sizeof(Node));
        p = p->next;
        i--;
    }
    p->data = 0;
    p->next = NULL;
    p = NULL;

    return l;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {

    Node *p;
    p = xs;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = malloc(sizeof(Node));
    p->next->data = 88;
    p->next->next = NULL;

}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
