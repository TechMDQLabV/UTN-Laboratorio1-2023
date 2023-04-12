#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

void menuDeOpciones();
void muestraOpciones();
void replicante(char c, int cant);
void cargaPila(Pila* p);
void cargaPilaRandom(Pila* p, int cant);
void cargaPilaOrdenada(Pila* p, int cant);
void muestraPila(Pila c, char* titulo);
int buscaMenor(Pila* p);
void pasaPilaOrdenada(Pila* o, Pila* d);
void pasaPila(Pila* o, Pila* d);
void insertarEnOrden(Pila* ordenada, int dato);
void ordenarPorInsercion(Pila* o, Pila* ordenada);

int main()
{
    menuDeOpciones();
    return 0;
}

void menuDeOpciones(){
    Pila temp, ordenada;
    inicpila(&temp);
    inicpila(&ordenada);

    char opcion;
    do{
        system("cls");
        muestraOpciones();

        opcion=getch();

        switch(opcion){
            case 49:
                    cargaPila(&temp);
                    break;
            case 50:
                    cargaPilaRandom(&temp, 15);
                    printf("\n Pila cargada con exito...");
                    break;
            case 51:
                    cargaPilaOrdenada(&temp, 15);
                    printf("\n Pila cargada con exito...");
                    break;
            case 52:
                    muestraPila(temp, "Temp");
                    break;
            case 53:
                    if(!pilavacia(&temp)){
                        muestraPila(temp, "Temp");
                        printf("\n");
                        pasaPilaOrdenada(&temp, &ordenada);
                        muestraPila(ordenada, "Ordenada");

                    }else{
                        printf("La pila esta vacia");
                    }

                    break;
            case 54:

                    break;
        }
        getch();
    }while(opcion!=ESC);
}

void muestraOpciones(){
    printf("\n\t\t\t <<<<< Guia de Funciones >>>>>");
    printf("\n");
    replicante('=',80);
    printf("\n");
    printf("\n 1. Carga Pila p/usuario");
    printf("\n 2. Carga Pila random");
    printf("\n 3. Carga Pila ordenada");
    printf("\n 4. Muestra Pila");
    printf("\n 5. Ordena por Seleccion");
    printf("\n 6. Ordena por Insercion");
    printf("\n");
    printf("\n ESC para salir");
}

void replicante(char c, int cant){
    for(int i=0;i<cant;i++){
        printf("%c",c);
    }
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

void cargaPilaRandom(Pila* p, int cant){
    for(int i=0;i<cant;i++){
        apilar(p, rand()%100);
    }
}

void cargaPilaOrdenada(Pila* p, int cant){
    for(int i=0;i<cant;i++){
        apilar(p, i);
    }
}

void muestraPila(Pila c, char* titulo){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    printf("<<<<<<<<< Pila %s >>>>>>>>>", titulo);
    while(!pilavacia(&c)){
        if(cont%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscaMenor(Pila* p){
    Pila aux;
    inicpila(&aux);

    int menor;

    menor = desapilar(p);

    while(!pilavacia(p)){
        if(tope(p) < menor){
            apilar(&aux, menor);
            menor = desapilar(p);
        }else{
            apilar(&aux, desapilar(p));
        }
    }

    pasaPila(&aux, p);

    return menor;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void pasaPilaOrdenada(Pila* o, Pila* d){
    while(!pilavacia(o)){
        apilar(d, buscaMenor(o));
    }
}

/** \brief Esta funcion pasa los datos de una pila a otra
 *
 * \param Puntero a pila origen
 * \param Puntero a pila destino
 * \return Sin retorno
 *
 */
void pasaPila(Pila* o, Pila* d){
    while(!pilavacia(o)){
        apilar(d, desapilar(o));
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void insertarEnOrden(Pila* ordenada, int dato){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(ordenada) && tope(ordenada) > dato){
        apilar(&aux, desapilar(ordenada));
    }
    apilar(ordenada, dato);
    pasaPila(&aux, ordenada);
}

void ordenarPorInsercion(Pila* o, Pila* ordenada){
    while(!pilavacia(o)){
        insertarEnOrden(ordenada, desapilar(o));
    }
}
