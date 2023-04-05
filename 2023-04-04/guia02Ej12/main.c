#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila ordenada, aux, elementos;
    inicpila(&ordenada);
    inicpila(&aux);
    inicpila(&elementos);

    cargaPilaRandom(&elementos, 40);
    muestraPila(elementos, "Pila Elementos");
    printf("\n");
    system("pause");
    while(!pilavacia(&elementos)){
        while(!pilavacia(&ordenada)&&tope(&ordenada)<tope(&elementos)){
            apilar(&aux, desapilar(&ordenada));
        }

        apilar(&ordenada, desapilar(&elementos));

        while(!pilavacia(&aux)){
            apilar(&ordenada, desapilar(&aux));
        }
    }
    muestraPila(ordenada, "Pila Ordenada");


    return 0;
}

void cargaPilaRandom(Pila* p, int cant){
    for(int i=0;i<cant;i++){
        apilar(p, rand()%100);
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
