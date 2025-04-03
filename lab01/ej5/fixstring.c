#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int s_length = 0;
    assert(s != NULL);
    while(s[s_length] != '\0'){
        s_length++;
    }
    return s_length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool are_equal = false;

    if (fstring_length(s1) == fstring_length(s2)){
        are_equal = true;
        for (unsigned int i = 0; i < fstring_length(s1); i++){
            if (s1[i] != s2[i])
            {
                are_equal = are_equal && false;
            }
        }
    }
    return are_equal;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    assert(s1 != NULL && s2 != NULL);
    bool are_less = false;
    int s1_length = fstring_length(s1);
    int s2_length = fstring_length(s2);
    int i = 0;

    while(s1[i] == s2[i] && i < s1_length && i < s2_length){
        i++;
    }

    are_less = s1[i] <= s2[i];
    return are_less;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);    
}


