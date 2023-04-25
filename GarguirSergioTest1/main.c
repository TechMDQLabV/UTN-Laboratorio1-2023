#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define DIM_NOTAS 100
#define ESC 27

int randomRangoInt(int min, int max);
int cargaNotasInt(int a[], int v, int dim);
int cargaArreglRandomInt(int a[], int dim, int cant);
void muestraArregloInt(int a[], int v);
int buscaDatoEnArregloInt(int a[], int v, int dato);

int main()
{
    srand(time(NULL));

    int notas[DIM_NOTAS];
    int vNotas = 0;

    vNotas = cargaArreglRandomInt(notas, DIM_NOTAS, 2);
    vNotas = cargaNotasInt(notas, vNotas, DIM_NOTAS);
    printf("\n <<<<<<<<<<<<<< Notas >>>>>>>>>>>>>>>>>>");
    muestraArregloInt(notas, vNotas);
    int encontrado = buscaDatoEnArregloInt(notas, vNotas, 10);

    if(!encontrado){ /// encontrado==0
        printf("\n El dato no se encuentra en la coleccion");
    }else{
        printf("\n El dato se encuentra en la coleccion");
    }
    return 0;
}

int randomRangoInt(int min, int max){
    return rand()%(max-min)+min;
}


/** \brief Carga un arreglo de notas con intervencion del usuario validando la carga entre 1 y 10
 *
 * \param El arreglo de notas
 * \param Los validos del arreglo
 * \param La dimension del arreglo
 * \return los validos
 *
 */
int cargaNotasInt(int a[], int v, int dim){
    int i = v;
    char opcion=0;

    while(i<dim && opcion!=ESC){
        do{
            printf("\n Ingrese una nota (1-10) ");
            scanf("%d",&a[i]);
            if(a[i]<1 || a[i]>10){
                printf("\n La nota no es valida debe ser de 1 a 10");
                getch();
                system("cls");
            }
        }while(a[i]<1 || a[i]>10);
        i++;

        printf("\n ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }

    return i;
}

/** \brief Carga un arreglo random
 *
 * \param El arreglo de enteros
 * \param La dimension del arreglo
 * \param La cantidad de datos a cargar
 * \return Validos
 *
 */
int cargaArreglRandomInt(int a[], int dim, int cant){
    int i=0;
    if(cant <= dim){
        for(i=0;i<cant;i++){
            a[i]=randomRangoInt(1,10);
        }
    }
    return i;
}

/** \brief Muestra un arreglo de enteros
 *
 * \param El arreglo de enteros
 * \param Validos
 * \return Void
 *
 */
void muestraArregloInt(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%20 == 0){
            printf("\n");
        }
        printf("%3d - ", a[i]);
    }
}

/** \brief Busca un dato en un arreglo de enteros y retorna 0 o 1
 *
 * \param Arreglo de enteros
 * \param  validos del arreglo
 * \param  dato a buscar
 * \return 0 si no lo encuentra o 1 si el dato existe
 *
 */
int buscaDatoEnArregloInt(int a[], int v, int dato){
    int i = 0;
    int flag = 0;
    while(i<v && flag==0){
        if(a[i]==dato){
            flag = 1;
        }else{
            i++;
        }
    }
    return flag;
}
