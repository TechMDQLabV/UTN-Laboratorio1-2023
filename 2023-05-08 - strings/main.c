#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pal1[20];
    char pal2[20];

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
