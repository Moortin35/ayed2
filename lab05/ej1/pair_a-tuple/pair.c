#include <stdio.h>
#include "pair.h"


pair_t pair_new(int x, int y){
    
    pair_t p;
    p.fst = x;
    p.snd = y;

    return p;
}

int pair_first(pair_t p){
    return p.fst;
}


int pair_second(pair_t p){
    return p.snd;
}


pair_t pair_swapped(pair_t p){
    pair_t q = pair_new(p.snd, p.fst);
    return q;
}

void pair_destroy(pair_t p){
    p.fst = 0;
    p.snd  = 0;
}