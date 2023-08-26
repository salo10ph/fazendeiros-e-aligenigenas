#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "celeiro.h"
#include "pontuacao.h"
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
        imprimeTempo();
        printf("\n Pontuacao: %d \n Animal que a nave quer: %s \n Animal no Celeiro: %s \n Animal Carregado: %s\n\n", retornaPontuacao(), retornaAnimalDaVez(), retornaAnimalDaVezCeleiro(), retornaAnimalCarregado());

            printf("\n-------- PILHA 1: %d --------\n", p.tamanho);
            imprimir(p.topo);
            printf("\n-------- PILHA 1: %d --------\n", p.tamanho);

            printf("\n\n-------- PILHA 2: %d --------\n", p2.tamanho);
            imprimir(p2.topo);
            printf("\n-------- PILHA 2: %d --------\n", p2.tamanho);
        printf("---\n\nDigite um dos seguntes comandos: \nWASD: Andar \n\n---\n\n");

        printarMapa();
        if (kbhit()){
            letra1 = _getch();
            switch(letra1){
                case 'w':
                case 's':
                case 'd':
                case 'a':
                    switch(movimentar(letra1)){
                        case 2:
                            printf("\nEntregando animal para a nave\n\n");
                            entregarAnimal(animalCarregado);
                            animalCarregado = 'N';
                            tempo_atual += tempo_extra;
                            break;
                        case 3:
                            printf("\nTentando pegar animal do celeiro\n\n");
                            pegarAnimalDoCeleiro();
                            break;
                        case 4:
                            if(animalCarregado != 'N'){
                                printf("\nTentando Empilhar animal no cercado 1\n\n");
                                empilhar( & p, animalCarregado);
                                animalCarregado = 'N';
                            }
                            else {
                                printf("\nTentando pegar animal do topo da pilha 1\n\n");

                                if(animalCarregado == 'N') {
                                    desempilhar( & p, &animalCarregado);
                                }
                            }
                            break;
                        case 5:
                            if(animalCarregado != 'N'){
                                printf("\nTentando Empilhar animal no cercado 2\n\n");
                                empilhar( & p2, animalCarregado);
                                animalCarregado = 'N';
                            }
                            else {
                                printf("\nTentando pegar animal do topo da pilha 1\n\n");
                                if(animalCarregado == 'N') {
                                    desempilhar( & p2, &animalCarregado);
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
        else{
            printf("Nada inserido!!!\n");
        }
            usleep(60000);
    } while (tempo_atual > 0);
     system("cls");
        printf("\n Pontuacao: %d \n\n FIM DE JOGO!!!\n\n\n\n\n\n\n\n", retornaPontuacao());

    return 0;
}
