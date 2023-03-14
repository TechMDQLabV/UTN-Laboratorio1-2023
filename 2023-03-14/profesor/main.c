#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    int menor;
    int mayor;
    int cantNotas = 0;
    int totalNotas = 0;
    float promedio;

    do
    {
        system("cls");
        printf("\n Ingrese un a nota: ");
        scanf("%d", &nota);

        if(nota!=0)
        {
            if(cantNotas==0)
            {
                menor = nota;
                mayor = nota;
            }
            else
            {
                if(nota<menor)
                {
                    menor = nota;
                }
                else
                {
                    if(nota>mayor)
                    {
                        mayor = nota;
                    }
                }
            }

            cantNotas = cantNotas + 1;
            totalNotas = totalNotas + nota;
        }
    }
    while(nota != 0);
    if(cantNotas>0){
        promedio = (float)totalNotas / cantNotas;
    }
    printf("\n====================================================");
    printf("\n La cantidad de notas ingresadas....: %d", cantNotas);
    printf("\n Total de notas ingresadas..........: %d", totalNotas);
    printf("\n El promedio de las notas es........: %.2f", promedio);
    printf("\n La nota menor es...................: %d", menor);
    printf("\n La nota mayor es...................: %d", mayor);
    printf("\n====================================================");
    return 0;
}
