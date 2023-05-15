#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define DIM_LEGAJO 100
#define DIM_13 13
#define DIM_20 20
#define DIM_30 30
#define DIM_40 40

int cargaLegajos(char n[][DIM_20], char ln[][DIM_30], char d[][DIM_13], int e[], int v, int dim);
void muestraLagajos(char n[][DIM_20], char ln[][DIM_30], char d[][DIM_13], int e[], int v);
int randomRango(int min, int max);
void getNames(char name[]);
void getDni(char dni[]);

int main()
{
    char names[DIM_LEGAJO][DIM_20];
    char lastNames[DIM_LEGAJO][DIM_30];
    char dnis[DIM_LEGAJO][DIM_13];
    int edades[DIM_LEGAJO];
    int vLegajo = 0;

    vLegajo = cargaLegajosRandom(names, lastNames, dnis, edades, 50);
    vLegajo = cargaLegajos(names, lastNames, dnis, edades, vLegajo, DIM_LEGAJO);
    system("cls");
    printf("\n<<<<< Listado de Legajos >>>>>");
    muestraLagajos(names, lastNames, dnis, edades, vLegajo);

    return 0;
}

int cargaLegajos(char n[][DIM_20], char ln[][DIM_30], char d[][DIM_13], int e[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion!=ESC){
        system("cls");
        printf("\n Ingrese el nombre.....: ");
        fflush(stdin);
        gets(n[v]);

        printf("\n Ingrese el apellido....: ");
        fflush(stdin);
        gets(ln[v]);

        printf("\n Ingrese el dni.........: ");
        fflush(stdin);
        gets(d[v]);

        printf("\n Ingrese la edad........: ");
        scanf("%d", &e[v]);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();

        v++;
    }

    return v;
}

void muestraLagajos(char n[][DIM_20], char ln[][DIM_30], char d[][DIM_13], int e[], int v){
    for(int i=0;i<v;i++){
        printf("\n Nombre..: %s", n[i]);
        printf("\n Apellido: %s", ln[i]);
        printf("\n DNI.....: %s", d[i]);
        printf("\n Edad....: %d", e[i]);
        printf("\n=============================================");
    }
}

int cargaLegajosRandom(char n[][DIM_20], char ln[][DIM_30], char d[][DIM_13], int e[], int limite){
    int i=0;
    for(i=0;i<limite;i++){
        getNames(n[i]);
        getLastNames(ln[i]);
        getDni(d[i]);
        e[i]=randomRango(12,90);
    }
    return i;
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void getNames(char name[]){
    char names[][20]= {"Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    strcpy(name, names[randomRango(0,sizeof(names)/(sizeof(char)*20))]);
}

void getLastNames(char lastName[]){
    char lastNames[][20]= {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};
    strcpy(lastName, lastNames[randomRango(0,sizeof(lastNames)/(sizeof(char)*20))]);
}

void getDni(char dni[]){
    itoa((randomRango(549,1982)*randomRango(549,1982)), dni, 10);
}
