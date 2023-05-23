#include <stdio.h>
#include <stdlib.h>
#include "stDomicilio.h"

void muestraUnDomicilio(stDomicilio domicilio){
    printf("\n Calle.............: %s", domicilio.calle);
    printf("\n Altura............: %d", domicilio.altura);
    printf("\n Localidad.........: %s", domicilio.ciudad);
    printf("\n================================================");
}

stDomicilio cargaUnDomicilio(){
    stDomicilio domicilio;

    printf("\n Calle.............: ");
    fflush(stdin);
    gets(domicilio.calle);

    printf(" Altura............: ");
    scanf("%d", &domicilio.altura);

    printf(" Localidad.........: ");
    fflush(stdin);
    gets(domicilio.ciudad);

    return domicilio;
}
