#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include "pontuacao.h"

char animais2[4] = {'V', 'P', 'C', 'O'};
char animalDaVez = 'Z';

void aleatorizarAnimal(){
    int numero = rand() % 4;
    animalDaVez = animais2[numero];
}

char* retornaAnimalDaVez(){
    switch (animalDaVez){
        case 'V':
            return "Vaca";
            break;
        case 'P':
            return "Porco";
            break;
        case 'C':
            return "Cavalo";
            break;
        case 'O':
            return "Ovelha";
            break;
        default:
            aleatorizarAnimal();
            retornaAnimalDaVez();
    }
}

void entregarAnimal(char animalEntregue){
    if(animalEntregue != 'N') {
        if(animalEntregue == animalDaVez) adicionaPontos();
        else removePontos();
        aleatorizarAnimal();
    }
}
