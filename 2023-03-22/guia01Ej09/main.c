#include <stdio.h>
#include <stdlib.h>
#include "../../Libraries/pila.h"

int main()
{
    Pila pila1, pila2, auxPila1, auxPila2;
    inicpila(&pila1);
    inicpila(&pila2);
    inicpila(&auxPila1);
    inicpila(&auxPila2);

    for(int i=0; i<10; i++) {
        apilar(&pila1, i);
    }

    for(int i=0; i<18; i++) {
        apilar(&pila2, i);
    }

    printf("\n <<<<<< Pila pila1 >>>>>>>>");
    mostrar(&pila1);
    printf("\n <<<<<< Pila pila2 >>>>>>>>");
    mostrar(&pila2);

    while(!pilavacia(&pila1) && !pilavacia(&pila2)){
        apilar(&auxPila1, desapilar(&pila1));
        apilar(&auxPila2, desapilar(&pila2));
    }

    if(pilavacia(&pila1) && pilavacia(&pila2)){
        printf("\n Las 2 pilas tienen la misma cantidad de elementos");
    }else{
        if(pilavacia(&pila1)){
            printf("\n La pila 2 tiene mas cantidad de elementos");
        }else{
            printf("\n La pila 1 tiene mas cantidad de elementos");
        }
    }

    return 0;
}
