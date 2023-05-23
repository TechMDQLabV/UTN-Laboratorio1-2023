#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stDomicilio.h"

#define DIM_DOMICILIOS 1000
#define ESC 27

int main()
{
    stDomicilio domicilios[DIM_DOMICILIOS];
    int vDomicilios = 0;

    vDomicilios = cargaArregloDomicilios(domicilios, DIM_DOMICILIOS);
    printf("\n <<<<<<<<<<< Listado de Domicilios >>>>>>>>>>>>");
    muestraArregloDomilios(domicilios, vDomicilios);

    return 0;
}

int cargaArregloDomicilios(stDomicilio d[], int dim){
    char opcion=0;
    int i=0;

    while(i<dim && opcion!=ESC){
        system("cls");
        d[i]=cargaUnDomicilio();
        i++;
        printf("\n\n ESC para salir o cualquier tecla para continuar... ");
        opcion = getch();
    }

    return i;
}

void muestraArregloDomilios(stDomicilio d[], int v){
    for(int i=0; i<v; i++){
        muestraUnDomicilio(d[i]);
    }
}
