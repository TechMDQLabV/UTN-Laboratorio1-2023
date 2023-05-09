#include <stdio.h>
#include <stdlib.h>

#define MAT_FIL 3
#define MAT_COL 3
#define MAT1_FIL 2
#define MAT1_COL 2
#define NAMES_DIM 100

void cargaMatriz(int fil, int col, int m[fil][col]);
void muestraMatriz(int fil, int col, int m[fil][col]);

int main()
{
    int mat[MAT_FIL][MAT_COL];
    int mat1[MAT1_FIL][MAT1_COL];
    int j=0;
    int i;
    char names[NAMES_DIM][20];
    int vNames=0;

    for(i=0;i<2;i++){
        printf("\n Ingrese un nombre:  ");
        scanf("%s", names[i]);
    }
    vNames = i;

    for(i=0;i<vNames;i++){
        printf("\n Nombre: %s", names[i]);
    }

    printf("\n Cargando la matriz MAT");
    cargaMatriz(MAT_FIL, MAT_COL, mat);

    printf("\n Listado de la matriz MAT\n");
    muestraMatriz(MAT_FIL, MAT_COL, mat);

    printf("\n Cargando la matriz MAT1");
    cargaMatriz(MAT1_FIL, MAT1_COL, mat1);

    printf("\n Listado de la matriz MAT1\n");
    muestraMatriz(MAT1_FIL, MAT1_COL, mat1);

    printf("\nHello world!\n");
    return 0;
}

void cargaMatriz(int fil, int col, int m[fil][col]){
    int j;
    for(int i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("\nIngrese un dato: ");
            scanf("%d", &m[i][j]);
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    int j;
    for(int i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}






