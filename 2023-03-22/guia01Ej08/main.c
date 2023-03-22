#include <stdio.h>
#include <stdlib.h>
#include "../../Libraries/pila.h"

int main()
{
    Pila mazo, jugador1, jugador2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    for(int i=0; i<18; i++) {
        apilar(&mazo, i);
    }

    printf("\n <<<<<< Pila mazo >>>>>>>>");
    mostrar(&mazo);

    while(!pilavacia(&mazo)) {
        apilar(&jugador1, desapilar(&mazo));
        if(!pilavacia(&mazo)){
            apilar(&jugador2, desapilar(&mazo));
        }
    }

    printf("\n <<<<<< Pila mazo >>>>>>>>");
    mostrar(&mazo);

    printf("\n <<<<<< Pila jugador1 >>>>>>>>");
    mostrar(&jugador1);

    printf("\n <<<<<< Pila jugador2 >>>>>>>>");
    mostrar(&jugador2);
    return 0;
}
