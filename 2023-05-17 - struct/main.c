#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"

#define DIM_LEGAJOS 1000
#define ESC 27
#define ARCHI_LEGAJOS "legajos.dat"

int cargaArregloLegajos(stLegajo legajos[], int dim);
void muestraLegajos(stLegajo legajos[], int v);
void cargaArchivoLegajos(char nombreArchivo[]);
void muestraArchivoDeLegajos(char nombreArchivo[]);

int main()
{
    stLegajo legajos[DIM_LEGAJOS];
    int vLegajos=0;

    cargaArchivoLegajos(ARCHI_LEGAJOS);
    printf("\n <<<<<<<< Listado de Legajos del archivo >>>>>>>>");
    muestraArchivoDeLegajos(ARCHI_LEGAJOS);
//    vLegajos = cargaArregloLegajos(legajos, DIM_LEGAJOS);


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

void cargaArchivoLegajos(char nombreArchivo[]){
    char opcion=0;
    stLegajo legajo;
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        while(opcion!=27){
            legajo = cargaUnLegajo();
            fwrite(&legajo, sizeof(stLegajo), 1, archi);
            printf("\n ESC para salir o cualquier tecla para continuar... ");
            opcion=getch();
        }

        fclose(archi);
    }
}

void muestraArchivoDeLegajos(char nombreArchivo[]){
    stLegajo legajo;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&legajo, sizeof(stLegajo), 1, archi)>0){
            muestraUnLegajo(legajo);
        }
        fclose(archi);
    }
}
