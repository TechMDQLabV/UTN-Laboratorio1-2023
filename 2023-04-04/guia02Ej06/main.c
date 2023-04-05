#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
void cargaPilaRandom(Pila* p, int cant);
void muestraPila(Pila c, char* titulo);

int main()
{
    srand(time(NULL));
    Pila numeros, menor, aux;
    inicpila(&numeros);
    inicpila(&menor);
    inicpila(&aux);

    cargaPilaRandom(&numeros, 40);
    muestraPila(numeros, "Pila Numeros");

    while(!pilavacia(&numeros)){
        apilar(&menor, desapilar(&numeros));

        while(!pilavacia(&numeros)){
            if(tope(&numeros)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&numeros));
            }else{
                apilar(&aux, desapilar(&numeros));
            }
        }

        while(!pilavacia(&aux)){
            apilar(&numeros, desapilar(&aux));
        }
    }

    muestraPila(numeros, "Pila Numeros");
    muestraPila(menor, "Pila Menor");

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
