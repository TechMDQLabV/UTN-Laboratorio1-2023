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
void muestraPila(Pila c);

int main()
{
    menuDeOpciones();
    return 0;
}

void menuDeOpciones(){
    Pila temp;
    inicpila(&temp);
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
                    muestraPila(temp);
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
