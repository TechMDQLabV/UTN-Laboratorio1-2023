#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "gotoxy.h"

#define ESC 27
#define CAR 219

int main()
{
    char c;
    int x=0;
    int y=0;
    int i=0;

    do{
        c = getch();

        switch(c){
            case 59:
                    color(9);
                    break;
            case 60:
                    color(23);
                    break;
            case 61:
                    color(33);
                    break;
            case 62:
                    color(44);
                    break;
            case ESC:
                    x=10;
                    y=10;
                    while(!kbhit()){
                        gotoxy(x,y);
                        color(i);
                        printf("Hasta la vista Baby.....");
                        Sleep(500);
                        i++;
                    }
                    break;
            case 72:
                    if(y>0){
                        y--;
                        gotoxy(x,y);
                        printf("%c",CAR);
                    }else{
                        Beep(523,523);
                    }
                    break;
            case 75:
                    if(x>0){
                        x--;
                        gotoxy(x,y);
                        printf("%c",CAR);
                    }else{
                        Beep(523,523);
                    }
                    break;
            case 77:
                    if(x<80){
                        x++;
                        gotoxy(x,y);
                        printf("%c",CAR);
                    }else{
                        Beep(523,523);
                    }
                    break;

            case 80:
                    if(y<25){
                        y++;
                        gotoxy(x,y);
                        printf("%c",CAR);
                    }else{
                        Beep(523,523);
                    }
                    break;
        }


    }while(c!=ESC);


    return 0;
}
