char animalCarregado = 'N';

void pegarAnimalDoCeleiro(){
    if(animalCarregado == 'N') {
        animalCarregado = animalDaVezCeleiro;
        aleatorizarAnimalDaVezCeleiro();
    }
}

char* retornaAnimalCarregado(){
    switch (animalCarregado){
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
            return "Nenhum";
            break;
    }
}
