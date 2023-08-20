#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "celeiro.h"

char letra1 = '1';
int main()
{
    do{
        fflush(stdin);
        if (kbhit()){
            letra1 = _getch();

            switch(letra1){
                case 'w':
                    printf("\nAndando para cima\n\n");
                    break;
                case 's':
                    printf("\nAndando para baixo\n\n");
                    break;
                case 'd':
                    printf("\nAndando para direita\n\n");
                    break;
                case 'a':
                    printf("\nAndando para esquerda\n\n");
                    break;
                default:
                    printf("\nComando invallido!!!\n\n");
                    break;
            }
            //printf("\n%c\n\n", letra1);
            while (_kbhit()) _getch();
        }
        else{
            printf("Nada inserido!!!\n");
            usleep(500000);
        }
    } while (letra1 != '0');
    return 0;
}
