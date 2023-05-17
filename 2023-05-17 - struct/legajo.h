#ifndef LEGAJO_H_INCLUDED
#define LEGAJO_H_INCLUDED

typedef struct{
    char name[20];
    char lastName[30];
    char dni[13];
    int edad;
} stLegajo;

void muestraUnLegajo(stLegajo legajo);
stLegajo cargaUnLegajo();

#endif // LEGAJO_H_INCLUDED
