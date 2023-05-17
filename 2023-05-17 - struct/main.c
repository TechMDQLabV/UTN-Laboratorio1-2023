#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"

#define DIM_LEGAJOS 1000
#define ESC 27

int cargaArregloLegajos(stLegajo legajos[], int dim);

int main()
{
    stLegajo legajos[DIM_LEGAJOS];
    int vLegajos=0;

    vLegajos = cargaArregloLegajos(legajos, DIM_LEGAJOS);

    printf("\n <<<<<<<< Listado de Legajos >>>>>>>>");
    muestraLegajos(legajos, vLegajos);
    return 0;
}

int cargaArregloLegajos(stLegajo legajos[], int dim){
    char opcion=0;
    int i=0;
    while(i<dim && opcion!=ESC){
        system("cls");
        legajos[i]=cargaUnLegajo();
        i++;
        printf("\n ESC para salir o cualquier tecla para continuar... ");
        opcion=getch();
    }
    return i;
}

void muestraLegajos(stLegajo legajos[], int v){
    for(int i=0;i<v;i++){
        muestraUnLegajo(legajos[i]);
    }
}
