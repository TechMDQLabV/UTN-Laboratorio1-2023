#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila edades, aux;
    inicpila(&edades);
    inicpila(&aux);

    int edad;
    char opcion = 's';

    while(opcion=='s'){
        printf("\n Ingrese una edad: ");
        scanf("%d",&edad);
        apilar(&edades, edad);
        fflush(stdin);
        printf("\n Desea continuar? (s / n): ");
        scanf("%c", &opcion);
    }

    printf("\n <<<<<< Lista de edades de los alumnos >>>>>>>");
    mostrar(&edades);

    printf("Hello world!\n");
    return 0;
}
