#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "celeiro.h"
#include "nave.h"
#include "jogador.h"
#include "cercado.h"
#include "Temporizador.h"
#include "mapa.h"

char letra1 = '1';
int main()
{
    struct timespec inicio, fim;
    clock_gettime(CLOCK_REALTIME, &inicio);
    p.tamanho = 0;
    p.topo = NULL;
    p2.tamanho = 0;
    p2.topo = NULL;
    do{
        fflush(stdin);
        system("cls");
        printf("\n\n");
        printf("\t\t----------------------------------------------------------\n\t\t   |  ");
        imprimeTempo();
        mapearPilha(p.topo, p.tamanho, 0);
        mapearPilha(p2.topo, p2.tamanho, 1);
        retornaAnimalDaVezCeleiro();
        retornaAnimalDaVez();
        printf("\t|\tPontuacao: %d  |   \n", retornaPontuacao());
        printf("\t\t----------------------------------------------------------\n");
        printarMapa(animalDaVez, array1[0][2], array1[0][1], array1[0][0], array1[1][2], array1[1][1], array1[1][0], animalDaVezCeleiro);
        printf("--------------------------------\n |  Animal Carregado: %s |\n--------------------------------\n\n", retornaAnimalCarregado());
        printf("\nDigite um dos seguntes comandos: \nWASD: Andar \n");

        if (kbhit()){
            letra1 = _getch();
            switch(letra1){
                case 'w':
                case 's':
                case 'd':
                case 'a':
                    switch(movimentar(letra1)){
                        case 2:
                            entregarAnimal(animalCarregado);
                            animalCarregado = 'N';
                            tempo_atual += tempo_extra;
                            break;
                        case 3:
                            pegarAnimalDoCeleiro();
                            break;
                        case 4:
                            if(animalCarregado != 'N'){
                                animalCarregado = empilhar( & p, animalCarregado);
                            }
                            else {

                                if(animalCarregado == 'N') {
                                    desempilhar( & p, &animalCarregado, 0);
                                }
                            }
                            break;
                        case 5:
                            if(animalCarregado != 'N'){
                                animalCarregado = empilhar( & p2, animalCarregado);
                            }
                            else {
                                if(animalCarregado == 'N') {
                                    desempilhar( & p2, &animalCarregado, 1);
                                }
                            }
                            break;
                    }
                    break;
                default:
                    printf("\nComando invallido!!!\n\n");
                    break;
            }
            while (_kbhit()) _getch();
        }
            usleep(60000);
    } while (tempo_atual > 0);
     system("cls");
        printf("\n Pontuacao: %d \n\n FIM DE JOGO!!!\n\n\n\n\n\n\n\n", retornaPontuacao());

    return 0;
}
