#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

void cargaPila(Pila* p);
void muestraPila(Pila c);
int sumaPila(Pila c);

int main()
{
    Pila numeros, notas;
    inicpila(&numeros);
    inicpila(&notas);
    int suma;
    cargaPila(&numeros);
    //cargaPila(&notas);
    suma = sumaPila(numeros);
    printf("\n <<<<<<<< Pila numeros %d >>>>>>>>",suma);
    muestraPila(numeros);
    muestraPila(numeros);
    return 0;
}


void cargaPila(Pila* p){
    int nro;
    char opcion;

    do{
        system("cls");
        printf("\n Ingrese un dato: ");
        scanf("%d", &nro);
        apilar(p, nro);

        printf("\n Desea continuar? ESC para salir");
        opcion=getch();
    }while(opcion!=ESC);
}

void muestraPila(Pila c){
    Pila aux;
    inicpila(&aux);
    int cont=0;
    while(!pilavacia(&c)){
        if(cont%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}

int sumaPila(Pila c){
    Pila aux;
    inicpila(&aux);
    int suma=0;
    while(!pilavacia(&c)){
        suma=suma+tope(&c);
        apilar(&aux, desapilar(&c));
    }
    return suma;
}
