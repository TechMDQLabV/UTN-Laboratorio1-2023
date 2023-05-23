#ifndef STDOMICILIO_H_INCLUDED
#define STDOMICILIO_H_INCLUDED

typedef struct{
    char calle[30];
    int altura;
    char ciudad[30];
} stDomicilio;

void muestraUnDomicilio(stDomicilio domicilio);
stDomicilio cargaUnDomicilio();

#endif // STDOMICILIO_H_INCLUDED
