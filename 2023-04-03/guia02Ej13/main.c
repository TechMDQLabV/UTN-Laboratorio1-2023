#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void cargaPilaRandom(Pila* p);
void muestraPila(Pila c, char* titulo);

int main()
{
    Pila mazo, jugador1, jugador2, aux;
    inicpila(&aux);
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    int puntosJugador1=0;
    int puntosJugador2=0;

    cargaPilaRandom(&mazo);
    ///printf("\n <<<<<<<<<<<< Mazo >>>>>>>>>>>>");
    muestraPila(mazo, "Mazo");

    while(!pilavacia(&mazo)){
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador1, desapilar(&mazo));

        apilar(&jugador2, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
    }

    while(!pilavacia(&jugador1) && !pilavacia(&jugador2)){
        puntosJugador1=puntosJugador1+tope(&jugador1);
        puntosJugador2+=tope(&jugador2);

        apilar(&aux, desapilar(&jugador1));
        apilar(&aux, desapilar(&jugador2));
    }

    if(puntosJugador1>=puntosJugador2){
        while(!pilavacia(&aux)){
            apilar(&jugador1, desapilar(&aux));
        }
    }else{
        while(!pilavacia(&aux)){
            apilar(&jugador2, desapilar(&aux));
        }
    }

    printf("\n Pila puntos jugador1: %d", puntosJugador1);
    muestraPila(jugador1, "Jugador 1");
    printf("\n Pila puntos jugador2: %d", puntosJugador2);
    muestraPila(jugador2, "Jugador 2");

    return 0;
}

void cargaPilaRandom(Pila* p){
    for(int i=0;i<40;i++){
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
