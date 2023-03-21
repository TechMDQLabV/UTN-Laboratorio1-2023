#include <stdio.h>
#include <stdlib.h>

/**
Hacer un algoritmo que calcule el total
 a pagar por la compra de camisas.
 Si se compran tres camisas o más se aplica
  un descuento del 20% sobre el total
  de la compra y si son menos de tres camisas un descuento del 10%
*/

#define DESCUENTO_10 .1
#define DESCUENTO_20 .2
#define VALOR_CAMISA 1000

int main()
{
    int cantidadCamisas;
    int total;
    float descuento;
    float totalApagar;

    printf("\nIngrese el total de camisas compradas:");
    scanf("%d", &cantidadCamisas);

    total = (VALOR_CAMISA * cantidadCamisas);

    if(cantidadCamisas < 3){
          descuento =  total * DESCUENTO_10;
    }else{
          descuento = total * DESCUENTO_20;
    }

    totalApagar = total - descuento;
    printf("\n El total a pagar con descuento es de: %.2f", totalApagar);

    return 0;
}
