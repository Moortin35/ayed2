#include <stdio.h>

//Dado los tad conjunto y lista:

List cambio(List monedas, int cambio_cliente){
    int moneda_de_cambio;
    int resto = cambio_cliente;
    List lista_monedas = is_empty();
    List caux = copy_list(monedas);
    while(!is_empty(caux)){
        moneda_de_cambio = head(caux) //El criterio es que tome la moneda de mayor denominacion disponible
        if(moneda_de_cambio > resto){
            tail(caux, moneda_de_cambio);
        }
        else{
            resto = resto-moneda_de_cambio;
            addl(lista_monedas, moneda_de_cambio);
        }
    }
    list_destroy(caux);
    return lista_monedas;
}