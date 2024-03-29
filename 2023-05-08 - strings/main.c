#include <stdio.h>
#include <stdlib.h>

#define NAMES_DIM 100

int cargaStrings(char n[][20], int dim);
void muestraStrings(char n[][20], int v);
int cargaArreglos(int e[], char n[][20], char a[][30], char d[][13], int dim);

int main()
{
    char pal1[20];
    char pal2[20];
    char names[NAMES_DIM][20];
    int vNames=0;


    vNames = cargaStrings(names, NAMES_DIM);
    muestraStrings(names, vNames);


    printf("\n Ingrese una palabra: ");
    fflush(stdin);
    scanf("%s", pal1);
    printf("\n Ingrese una palabra: ");
    fflush(stdin);
    gets(pal2);
    for(int i=0;i<strlen(pal1);i++){
        printf("\n%c",pal1[i]);
    }
    pal1[2]='\0';
        printf("\n pal1: %s - %d", pal1, strlen(pal1));
    pal1[2]='L';
    printf("\n pal1: %s - %d", pal1, strlen(pal1));
    printf("\n pal2: %s - %d", pal2, strlen(pal2));
    strcat(pal1, pal2);
    printf("\n pal1: %s - %d", pal1, strlen(pal1));
    printf("\n pal2: %s - %d", pal2, strlen(pal2));
    return 0;
}

int cargaStrings(char n[][20], int dim){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        system("cls");
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        gets(n[i]);
        i++;

        printf("ESC para salir o cualquier tecla para continuar ...");
        opcion = getch();
    }

    return i;
}

void muestraStrings(char n[][20], int v){
    for(int i=0;i<v;i++){
        printf("\n %s",n[i]);
    }
}

int cargaArreglos(int e[], char n[][20], char a[][30], char d[][13], int dim){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        system("cls");

        printf("\n Ingrese el nombre: ");
        fflush(stdin);
        gets(n[i]);

        printf("\n Ingrese el apellido: ");
        fflush(stdin);
        gets(a[i]);

        printf("\n Ingrese el DNI: ");
        fflush(stdin);
        gets(d[i]);

        printf("\n Ingrese la edad: ");
        scanf("%d", &e[i]);

        i++;

        printf("ESC para salir o cualquier tecla para continuar ...");
        opcion = getch();
    }

    return i;

}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void getName(char n[]){
    char names[][20]={"Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    strcpy(n, names[randomRango(0,(sizeof(names)/sizeof(char))*20)]);
}

void getDni(char d[]){
    itoa(randomRango(5000000,60000000),d,10);
}



void ordenaPorSeleccionString(char a[][20], int v){
    int posMenor=0;
    char aux[20];
    for(int i=0;i<v-1;i++){
        posMenor = buscaPosMenorString(a, v, i);
        strcpy(aux, a[posMenor]);
        strcpy(a[posMenor], a[i]);
        strcpy(a[i], aux);
    }
}

int buscaPosMenorString(char a[][20], int v, int comienzo){
    int i = comienzo;
    int posMenor = i;
    i++;
    while(i<v){
        if(strcmp(a[i],a[posMenor])<0){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

int buscaPosMenorStringConFor(char a[][20], int v, int comienzo){
    int posMenor = comienzo;
    comienzo++;
    for(int i=comienzo;i<v;i++){
        if(strcmp(a[i],a[posMenor])<0){
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenaPorInsercionString(char a[][20], int v){
    for(int i=0; i<v-1; i++){
        insertarOrdenadoString(a, i, a[i+1]);
    }
}

void insertarOrdenadoString(char a[][20], int v, char elemento[]){
    int i = v;
    while(i>=0 && strcmp(a[i], elemento)>0){
        strcpy(a[i+1], a[i]);
        i--;
    }
    strcpy(a[i+1], elemento);
}

int muestraPantallaIngreso(){
    color(23);
    printf("\n Ingrese el nombre...: ");
    printf("\n Ingrese el apellido.: ");
    printf("\n Ingrese el DNI......: ");
    printf("\n Ingrese la edad.....: ");
}

int cargaArreglosConGotoXY(int e[], char n[][20], char a[][30], char d[][13], int dim){
    int i = 0;
    char opcion = 0;

    while(i<dim && opcion != 27){
        system("cls");
        muestraPantallaIngreso();
        color(23);
        gotoxy(25,2);
        fflush(stdin);
        gets(n[i]);

        gotoxy(25,3);
        fflush(stdin);
        gets(a[i]);

        gotoxy(25,4);
        fflush(stdin);
        gets(d[i]);

        gotoxy(25,5);
        scanf("%d", &e[i]);

        i++;

        printf("ESC para salir o cualquier tecla para continuar ...");
        opcion = getch();
    }

    return i;

}
