#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
    /**11.	Suponiendo la existencia de una pila MODELO que no este vacía, eliminar
     de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO*/
int main()
{
    Pila modelo, dada, auxDada, basura;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&basura);

    apilar(&modelo, 4);

    for(int i=0; i<15; i++){
        apilar(&dada, rand()%20);
    }

    printf("\n<<<<<<<<<< Pila Modelo >>>>>>>>>>>>");
    mostrar(&modelo);
    printf("\n<<<<<<<<<< Pila Dada >>>>>>>>>>>>");
    mostrar(&dada);

    if(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&dada)==tope(&modelo)){
                apilar(&basura, desapilar(&dada));
            }else{
                apilar(&auxDada, desapilar(&dada));
            }
        }
        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }
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
