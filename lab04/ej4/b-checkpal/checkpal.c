#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 100

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.', '\n'};
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);
    //scanf("%s", user_input);
    fgets(user_input, MAX_LENGTH, stdin);

    if(user_input[string_length(user_input)-1] == '\n'){
        user_input[string_length(user_input)-1] = '\0';
    }

    filtered = string_filter(user_input, ignore_chars[0]);
    char* aux = NULL;
    for (unsigned int i=1; i < SIZEOF_ARRAY(ignore_chars); i++) {
        aux = calloc(string_length(filtered)+1,sizeof(char));
        strcpy(aux,filtered);
        free(filtered);
        filtered = string_filter(aux, ignore_chars[i]);
        free(aux);
    }
    
    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    free(filtered);
    return EXIT_SUCCESS;
}