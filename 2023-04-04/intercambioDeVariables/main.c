#include <stdio.h>
#include <stdlib.h>
float algo(int a, int b);
int main()
{
    int n1 = 10;
    int n2 = 5;
    int aux;
    printf("\n n1 = %d - n2 = %d", n1, n2);

    aux = n1;
    n1 = n2;
    n2 = aux;
    printf("\n n1 = %d - n2 = %d", n1, n2);

    /// ----------------------------------
    intercambio(&n1, &n2);
    printf("\n Fuera de la funcion Intercambio");
    printf("\n n1 = %d - n2 = %d", n1, n2);
    intercambio2(&n1, &n2);
    printf("\n n1 = %d - n2 = %d", n1, n2);
    printf("\n %d / %d = %f",n1, n2, algo(n1, n2));
    return 0;
}

void intercambio(int* nro1, int* nro2){
    int aux;
    printf("\n En la funcion Intercambio");
    printf("\n nro1 %p = %d - nro2 %p = %d", nro1, *nro1, nro2, *nro2);

    aux = *nro1;
    *nro1 = *nro2;
    *nro2 = aux;
    printf("\n nro1 = %d - nro2 = %d", *nro1, *nro2);
    system("pause");
}

void intercambio2(int* nro1, int* nro2){
    *nro1 = *nro1 + *nro2;
    *nro2 = *nro1 - *nro2;
    *nro1 = *nro1 - *nro2;
}

float algo(int a, int b){
    return (float)a/b;
}
