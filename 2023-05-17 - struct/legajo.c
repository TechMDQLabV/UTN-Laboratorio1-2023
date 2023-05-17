#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"


void muestraUnLegajo(stLegajo legajo){
    printf("\n Nombre...............: %s", legajo.name);
    printf("\n Apellido.............: %s", legajo.lastName);
    printf("\n DNI..................: %s", legajo.dni);
    printf("\n Edad.................: %d", legajo.edad);
    printf("\n========================================================");
}

stLegajo cargaUnLegajo(){
    stLegajo legajo;

    printf("\n Ingrese el nombre....: ");
    fflush(stdin);
    gets(legajo.name);

    printf(" Ingrese el apellido....: ");
    fflush(stdin);
    gets(legajo.lastName);

    printf(" Ingrese el DNI.........: ");
    fflush(stdin);
    gets(legajo.dni);

    printf(" Ingrese el edad........: ");
    scanf("%d", &legajo.edad);

    return legajo;
}
