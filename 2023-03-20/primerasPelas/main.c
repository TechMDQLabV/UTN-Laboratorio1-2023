#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila pilita, menores, mayores;
    inicpila(&pilita);
    inicpila(&menores);
    inicpila(&mayores);

    leer(&pilita);

    for(int i=0;i<40;i++){
        apilar(&pilita,rand()%100);
    }

    printf("<<<<<<<<<<<<<<<<< Pila pilita antes de while >>>>>>>>>>>>>>>>>>>>\n");
    mostrar(&pilita);

    while(!pilavacia(&pilita)){
        if(tope(&pilita)>50){
            apilar(&mayores, desapilar(&pilita));
        }else{
            apilar(&menores, desapilar(&pilita));
        }
    }

    printf("<<<<<<<<<<<<<<<<< Pila pilita >>>>>>>>>>>>>>>>>>>>\n");
    mostrar(&pilita);
    printf("<<<<<<<<<<<<<<<<< Pila menores >>>>>>>>>>>>>>>>>>>>\n");
    mostrar(&menores);
        printf("<<<<<<<<<<<<<<<<< Pila mayores >>>>>>>>>>>>>>>>>>>>\n");
    mostrar(&mayores);
    printf("Hello world!\n");
    return 0;
}
