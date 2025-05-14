#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 100

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    //char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    
    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: \n", MAX_LENGTH);
    //scanf("%s", user_input);
    fgets(user_input, sizeof(user_input), stdin);

    //char *filtered=NULL;
    //char *aux = NULL;
    //filtered = calloc(string_length(user_input),sizeof(char));
    //strcpy(filtered, user_input);
    printf("%s",user_input);
    /*
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        aux = string_filter(filtered, ignore_chars[i]);
        free(filtered);
        strcpy(filtered, aux);
        free(aux);
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    */
    return EXIT_SUCCESS;
}

