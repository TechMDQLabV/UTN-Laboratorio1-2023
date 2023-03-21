#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
Leer 10 números y obtener su cubo y su cuarta.
*/

int main()
{
    int numero, cubo, cuarta, cuboPow, cuartaPow;

    for(int i=0; i<10; i++) {
        printf("\n%p Ingrese el nunero %d: ", &numero, i+1);
        scanf("%d", &numero);
        cubo = numero * numero * numero;
        cuboPow = round(pow(numero, 3));
        cuarta = cubo * numero;
        cuartaPow = round(pow(numero, 4));

        printf("\n El cubo del nro %d es %d - %d", numero, cubo, cuboPow);
        printf("\n La cuarta del nro %d es %d - %d", numero, cuarta, cuartaPow);
    }


    return 0;
}
