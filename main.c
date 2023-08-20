#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "celeiro.h"
#include "pontuacao.h"

char letra1 = '1';
int main()
{
    do{
        fflush(stdin);
        //system("cls");
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
                case '1':
                    printf("\nAdicionando pontos\n\n");
                    adicionaPontos();
                    break;
                case '2':
                    printf("\nAdicionando pontos com bonus\n\n");
                    adicionaPontosBonus();
                    break;
                case '3':
                    printf("\Removendo pontos\n\n");
                    removePontos();
                    break;
                case '4':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case '5':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case '6':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case '7':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case '8':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case '9':
                    printf("\nAndando para esquerda\n\n");
                    break;
                default:
                    printf("\nComando invallido!!!\n\n");
                    break;
            }
            printf("\n%d\n\n", retornaPontuacao());
            while (_kbhit()) _getch();
        }
        else{
            printf("Pontos: %d --- Nada inserido!!!\n", retornaPontuacao());
            usleep(500000);
        }
    } while (letra1 != '0');
    return 0;
}
