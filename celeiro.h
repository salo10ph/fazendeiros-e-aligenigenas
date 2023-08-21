#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char animais4[4] = {'V', 'P', 'C', 'O'};
char animalDaVezCeleiro = 'Z';

void aleatorizarAnimalDaVezCeleiro(){
    int numero = rand() % 4;
    animalDaVezCeleiro = animais4[numero];
}

char* retornaAnimalDaVezCeleiro(){
    switch (animalDaVezCeleiro){
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
            aleatorizarAnimalDaVezCeleiro();
            retornaAnimalDaVezCeleiro();
    }
}
