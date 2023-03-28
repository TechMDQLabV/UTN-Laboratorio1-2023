#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
    /**12.	Suponiendo la existencia de una pila MODELO que no este vacía, eliminar
     de la pila DADA todos los elementos que sean iguales al los elementos de la pila MODELO*/
int main()
{
    Pila modelo, dada, auxDada, basura, auxModelo;
    inicpila(&modelo);
    inicpila(&auxModelo);
    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&basura);

    for(int i=0; i<10; i++){
        apilar(&modelo, i+1);
    }

    for(int i=0; i<15; i++){
        apilar(&dada, rand()%20);
    }

    printf("\n<<<<<<<<<< Pila Modelo >>>>>>>>>>>>");
    mostrar(&modelo);
    printf("\n<<<<<<<<<< Pila Dada >>>>>>>>>>>>");
    mostrar(&dada);

    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&dada)==tope(&modelo)){
                apilar(&basura, desapilar(&dada));
            }else{
                apilar(&auxDada, desapilar(&dada));
            }
        }
        apilar(&auxModelo, desapilar(&modelo));
        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }
    }
    while(!pilavacia(&auxModelo)){
        apilar(&modelo, desapilar(&auxModelo));
    }

    printf("\n<<<<<<<<<< Pila Modelo >>>>>>>>>>>>");
    mostrar(&modelo);
    printf("\n<<<<<<<<<< Pila Dada >>>>>>>>>>>>");
    mostrar(&dada);
    printf("\n<<<<<<<<<< Pila Basura >>>>>>>>>>>>");
    mostrar(&basura);

    printf("Hello world!\n");
    return 0;
}

