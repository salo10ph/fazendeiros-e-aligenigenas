#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "celeiro.h"
#include "pontuacao.h"
#include "nave.h"
#include "jogador.h"
#include "cercado.h"

char letra1 = '1';
int main()
{
    p.tamanho = 0;
    p.topo = NULL;
    p2.tamanho = 0;
    p2.topo = NULL;
    do{
        fflush(stdin);
        system("cls");
        printf("\n Pontuacao: %d \n Animal que a nave quer: %s \n Animal no Celeiro: %s \n Animal Carregado: %s\n\n", retornaPontuacao(), retornaAnimalDaVez(), retornaAnimalDaVezCeleiro(), retornaAnimalCarregado());

            printf("\n-------- PILHA: %d --------\n", p.tamanho);
            imprimir(p.topo);
            printf("\n-------- PILHA --------");
        printf("---\nDigite um dos seguntes comandos: \nWASD: Andar \n1: Adicionar Pontos \n2: Adicionar Pontos com Bonus \n3: Remover Pontos \n4: Aleatorizar Animal da Nave \n5: Entregar Animal para a Nave \n6: Aleatorizar Animal do Celeiro \n7: Pegar Animal do Celeiro \n8: Empilhar animais no Cercado \n9: Pegar animal do topo \nP: Pegar Pilha de animais\n---\n\n");

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
                    printf("\nAleatorizar animal\n\n");
                    aleatorizarAnimal();
                    break;
                case '5':
                    printf("\nEntregar animal para a nave\n\n");
                    entregarAnimal(animalCarregado);
                    animalCarregado = 'N';
                    break;
                case '6':
                    printf("\nAleatorizar animal do celeiro\n\n");
                    aleatorizarAnimalDaVezCeleiro();
                    break;
                case '7':
                    printf("\nPegar animal do celeiro\n\n");
                    pegarAnimalDoCeleiro();
                    break;
                case '8':
                    printf("\nAndando para esquerda\n\n");
                    empilhar( & p, animalCarregado);
                    animalCarregado = 'N';
                    break;
                case '9':
                    printf("\nAndando para esquerda\n\n");
                    if(animalCarregado == 'N') {
                        desempilhar( & p, &animalCarregado);
                    }
                    break;
                case 'p':
                    printf("\nAndando para esquerda\n\n");
                    break;
                case 'v':
                    printf("\nAndando para esquerda\n\n");
                    empilhar( & p, animalCarregado);
                    animalCarregado = 'N';
                    break;
                case 'c':
                    printf("\nAndando para esquerda\n\n");
                    if(animalCarregado == 'N') {
                        desempilhar( & p, &animalCarregado);
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
            usleep(1000000);
    } while (letra1 != '0');
    return 0;
}
