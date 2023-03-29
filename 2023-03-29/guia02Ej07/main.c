#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila dnis, auxDnis;
    inicpila(&dnis);
    inicpila(&auxDnis);

    int dni;
    int flag=0;

    for(int i=0; i<10; i++){
        apilar(&dnis, i);
    }

    printf("\n <<<<<<<<<<<<< Listado de DNIs >>>>>>>>>>>>>");
    mostrar(&dnis);

    printf("\n Ingrese un DNI para buscar: ");
    scanf("%d",&dni);

    while(!pilavacia(&dnis) && flag==0){
        if(tope(&dnis)==dni){
            flag=1;
        }else{
            apilar(&auxDnis, desapilar(&dnis));
        }
    }

    if(flag==1){
        printf("\n El dni: %d se encuentra en la lista", dni);
    }else{
        printf("\n El dni: %d NO se encuentra en la lista", dni);
    }

    while(!pilavacia(&auxDnis)){
        apilar(&dnis, desapilar(&auxDnis));
    }






    return 0;
}
