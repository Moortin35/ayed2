#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

size_t string_length(const char *str){

    size_t s_length = 0;
    assert(str != NULL);
    while(str[s_length] != '\0'){
        s_length++;
    }
    return s_length;
}

char *string_filter(const char *str, char c){
    size_t new_length = 0;
    for (size_t i = 0; i < string_length(str); i++){
        if(str[i] != c){
            new_length++;
        }
    }
    char* new_str = calloc(new_length+1, sizeof(char));

    size_t j = 0;
    for(size_t i = 0; i < string_length(str); i++){
        if(str[i] != c){
            new_str[j] = str[i];
            j++;
        }
    }
    return new_str;
}

bool string_is_symmetric(const char *str){
    bool symmetric = true;
    size_t length = string_length(str);
    size_t der = length-1; 
    //como los strings empiezan indexados en 0, 
    //tengo que restar uno al length para que no compare el \0
    size_t izq = 0;
    while (izq <= der){
        if(str[izq] == str[der]){
            symmetric = symmetric && true;
            izq++;
            der--;
        }
        else{
            symmetric = symmetric && false;
            izq++;
            der--;
        }
    }
    return symmetric;
}