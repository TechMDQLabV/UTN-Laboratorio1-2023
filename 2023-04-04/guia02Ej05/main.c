#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila ordenada, aux, elemento;
    inicpila(&ordenada);
    inicpila(&aux);
    inicpila(&elemento);

    cargaPilaRandom(&ordenada, 40);
    muestraPila(ordenada, "Pila Ordenada");

    apilar(&elemento, 10);

    while(!pilavacia(&ordenada)&&tope(&ordenada)<tope(&elemento)){
        apilar(&aux, desapilar(&ordenada));
    }

    apilar(&ordenada, desapilar(&elemento));

    while(!pilavacia(&aux)){
        apilar(&ordenada, desapilar(&aux));
    }

    muestraPila(ordenada, "Pila Ordenada");


    return 0;
}

void cargaPilaRandom(Pila* p, int cant){
    for(int i=cant;i>0;i--){
        apilar(p, i);
    }
}

void muestraPila(Pila c, char* titulo){
    Pila aux;
    inicpila(&aux);
    int cont=0;
    printf("\n <<<<<<<<<<<<< %s >>>>>>>>>>>>", titulo);
    while(!pilavacia(&c)){
        if(cont%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}
