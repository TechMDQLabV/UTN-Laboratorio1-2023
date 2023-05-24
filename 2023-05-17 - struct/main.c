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
int archivo2arreglo(char nombreArchivo[], stLegajo legajos[], int dim);
void arreglo2archivo(stLegajo legajos[], int v, char nombreArchivo[]);
void arreglo2archivoBis(stLegajo legajos[], int v, char nombreArchivo[]);
int cuentaDatosArchivo(char nombreArchivo[]);

int main()
{
    stLegajo legajos[DIM_LEGAJOS];
    int vLegajos=0;

    //cargaArchivoLegajos(ARCHI_LEGAJOS);
    printf("\n <<<<<<<< Listado de Legajos del archivo >>>>>>>>");
    muestraArchivoDeLegajos(ARCHI_LEGAJOS);
//    vLegajos = cargaArregloLegajos(legajos, DIM_LEGAJOS);
    vLegajos = archivo2arreglo(ARCHI_LEGAJOS, legajos, DIM_LEGAJOS);

    printf("\n <<<<<<<< Listado de Legajos del arreglo >>>>>>>>");
    muestraLegajos(legajos, vLegajos);

    int cont;
    arreglo2archivoBis(legajos, vLegajos, ARCHI_LEGAJOS);
    cont = cuentaDatosArchivoBis(ARCHI_LEGAJOS)/sizeof(stLegajo);
    printf("\n <<<<<<<< Listado de Legajos del archivo %d >>>>>>>>", cont);
    muestraArchivoDeLegajos(ARCHI_LEGAJOS);
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
        while(fread(&legajo, sizeof(stLegajo), 1, archi)>0){  ///NO USAR FEOF()
            muestraUnLegajo(legajo);
        }
        fclose(archi);
    }
}

int archivo2arreglo(char nombreArchivo[], stLegajo legajos[], int dim){
    int i=0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&legajos[i], sizeof(stLegajo), 1, archi)>0 && i<dim){
            i++;
        }
        fclose(archi);
    }
    return i;
}

void arreglo2archivo(stLegajo legajos[], int v, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        for(int i=0;i<v;i++){
            fwrite(&legajos[i], sizeof(stLegajo), 1, archi);
        }
        fclose(archi);
    }
}

void arreglo2archivoBis(stLegajo legajos[], int v, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        fwrite(legajos, sizeof(stLegajo), v, archi);
        fclose(archi);
    }
}

int cuentaDatosArchivo(char nombreArchivo[]){
    int cont=0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        fseek(archi,0,SEEK_END);
        cont = ftell(archi)/sizeof(stLegajo);
        fclose(archi);
    }
    return cont;
}

int cuentaDatosArchivoBis(char nombreArchivo[]){
    int cont=0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        fseek(archi,0,SEEK_END);
        cont = ftell(archi);
        fclose(archi);
    }
    return cont;
}
