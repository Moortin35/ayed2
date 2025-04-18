#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
        res.exists = false;
        res.is_lowerbound = true;
        res.is_upperbound = true;
        res.where = -1;

        for (unsigned int i = 0; i < length; i++) {

            if (value == arr[i]) {
                res.exists = true;
                res.where = i;
            }

            if(value >= arr[i]){
                res.is_upperbound = res.is_upperbound && true;
            }
            else{
                res.is_upperbound = res.is_upperbound && false;
            }
            
            if(value <= arr[i]){
                res.is_lowerbound = res.is_lowerbound && true;
            }
            else{
                res.is_lowerbound = res.is_lowerbound && false;
            }
        }
        
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Por favor ingrese el elemento %d del arreglo\n", i);
        scanf("%d", &a[i]);
    }
    
    printf("Ingrese un valor para comparar con el arreglo: \n");
    scanf("%d", &value);
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    
    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

