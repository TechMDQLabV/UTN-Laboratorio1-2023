#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27
#define LIMITE 2

int main()
{
    Pila edades, auxEdades, edades2;
    inicpila(&edades);
    inicpila(&auxEdades);
    inicpila(&edades2);

    int edad;
    int cont=0;
    char opcion;

    do{
        printf("\n Ingrese una edad: ");
        scanf("%d", &edad);
        apilar(&edades, edad);

        printf("\n Desea continuar. Presione ESC para salir");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n Listado de Edades");
    while(!pilavacia(&edades)){
        if(cont%LIMITE==0){
            printf("\n");
        }
        printf("%5d - ", tope(&edades));
        apilar(&auxEdades, desapilar(&edades));
        cont++;
    }

    while(!pilavacia(&auxEdades)){
        apilar(&edades, desapilar(&auxEdades));
    }

    /// duplicar pila
    while(!pilavacia(&edades)){
        apilar(&edades2, tope(&edades));
        apilar(&auxEdades, desapilar(&edades));
    }

    while(!pilavacia(&auxEdades)){
        apilar(&edades, desapilar(&auxEdades));
    }

    return 0;
}
