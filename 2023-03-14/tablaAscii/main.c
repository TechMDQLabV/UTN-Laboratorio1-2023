#include <stdio.h>
#include <stdlib.h>

#define COLUMNAS 7

int main()
{
    printf("Hello world!\n");
    for(int i=0;i<256;i++){
        ///if(i==5 || i==10 || i==15){
        if(i%COLUMNAS==0){
            printf("\n");
        }
        printf(" %d - %c |", i, i);
    }
    system("pause");
    return 0;
}
