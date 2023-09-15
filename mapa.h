
#define MAPW 4
#define MAPH 4

char tecla = '0';
int jogadorY = 20;
int jogadorX = 53;
char caracterAnterior = ' ';
char matrix[400][400] = {
"                                         ()",
"                                _________||_________",
"                               /     ||||||||||||   \\",
"                              /                      \\",
"                             / |||||||||||||||||||||  \\",
"                            /__________________________\\",
"                            \\  |||||||||||||||||||||   /",
"                             \\________________________/",
"                                 \\______________/           Animal que a nave quer: ",
"                                   /  ------  \\",
"                                  /  --------  \\",
"                                 / ------------ \\",
"                                /----------------\\",
"                               |        0        |",
"                               |                 |",
"  Animal no Celeiro: ",
"|---------------|              |                 |                         |--------------------------|",
"|               |              |                 |                         |   ",
"|       F       |              |                 |                         |             C1           |",
"|               |--------------                   -------------------------|      ",
"|               |0                                                        0|         ",
"|---------------|----------------------------------------------------|     |--------------------------|",
"                                                                     |     |   ",
"                                                                     |     |      ",
"                                                                     |    0|            C2            |",
"                                                                     |-----|                  ",
"                                                                           |                          |",
"                                                                           |--------------------------|"};

void printarMapa(char animalDaVez, char animal1Pilha1, char animal2Pilha1, char animal3Pilha1, char animal1Pilha2, char animal2Pilha2, char animal3Pilha2, char animalDoCeleiro) {
    for(int i = 0; i < 30; i++)
    if(i != jogadorY && i != 8 && i != 15 && i != 17 && i != 19 && i != 20 && i != 22 && i != 23 && i != 25){ printf("%s\n", matrix[i]); }
    else {
        if(i != jogadorY){
            printf("%s", matrix[i]);
            switch(i){
                case 8:
                    escreveAnimal(animalDaVez);
                    break;
                case 15:
                    escreveAnimal(animalDoCeleiro);
                    printf("    |                 |");
                    break;
                case 17:
                    escreveAnimal(animal1Pilha1);
                    printf("                 |");
                    break;
                case 19:
                    escreveAnimal(animal2Pilha1);
                    printf("              |");
                    break;
                case 20:
                    escreveAnimal(animal3Pilha1);
                    printf("           |");
                    break;
                case 22:
                    escreveAnimal(animal1Pilha2);
                    printf("                 |");
                    break;
                case 23:
                    escreveAnimal(animal2Pilha2);
                    printf("              |");
                    break;
                case 25:
                    escreveAnimal(animal3Pilha2);
                    printf("  |");
                    break;
            }
            printf("\n");
        } else {
            for(int j = 0; j < strlen(matrix[i]); j++){
                if((j != jogadorX || i != jogadorY) && j != strlen(matrix[i])-1) printf("%c", matrix[i][j]);
                else if(j == jogadorX && i == jogadorY) printf("R");
                else {
                    switch(i){
                        case 8:
                            printf(" ");
                            escreveAnimal(animalDaVez);
                            break;
                        case 15:
                            printf(" ");
                            escreveAnimal(animalDoCeleiro);
                            char aux[] = "    |                 |";
                            for(int k = 0; k < strlen(aux); k++){
                                    if (j+k+7 != jogadorX)printf("%c", aux[k]);
                                    else printf("R");
                            }
                            break;
                        case 17:
                            printf(" ");
                            escreveAnimal(animal1Pilha1);
                            printf("                 |");
                            break;
                        case 19:
                            printf(" ");
                            escreveAnimal(animal2Pilha1);
                            printf("              |");
                            break;
                        case 20:
                            printf(" ");
                            escreveAnimal(animal3Pilha1);
                            printf("           |");
                            break;
                        case 22:
                            printf(" ");
                            escreveAnimal(animal1Pilha2);
                            printf("                 |");
                            break;
                        case 23:
                            printf(" ");
                            escreveAnimal(animal2Pilha2);
                            printf("              |");
                            break;
                        case 25:
                            printf(" ");
                            escreveAnimal(animal3Pilha2);
                            printf("  |");
                            break;
                        default:
                            printf("|");
                            break;
                    }
                }
            }
        printf("\n");
            }
    }
}

void escreveAnimal(char animal){
    switch(animal){
        case 'V':
            printf("Vaca  ");
            break;
        case 'P':
            printf("Porco ");
            break;
        case 'C':
            printf("Cavalo");
            break;
        case 'O':
            printf("Ovelha");
            break;
        default:
            printf("      ");
            break;
    }
}

int movimentar(char direcao) {
    int y = jogadorY, x = jogadorX;
    switch(direcao){
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
        }
    if (matrix[y][x] == '-' || matrix[y][x] == '/' || matrix[y][x] == '|') return 0;
    else {
            matrix[jogadorY][jogadorX] = caracterAnterior;
            switch(direcao){
                case 'w':
                    jogadorY--;
                    break;
                case 's':
                    jogadorY++;
                    break;
                case 'a':
                    jogadorX--;
                    break;
                case 'd':
                    jogadorX++;
                    break;
            }
            caracterAnterior = matrix[jogadorY][jogadorX];
            matrix[jogadorY][jogadorX] = 'R';
            if(caracterAnterior == '0') return realizaAcao();
            return 1;
    }
}

int realizaAcao(){
    int opcao = 999;
    switch(jogadorY){
        case 13:
            opcao = 2;
            break;
        case 20:
            if(jogadorX == 17) opcao = 3;
            else opcao = 4; //87
            break;
        case 24:
            opcao = 5;
            break;
    }
    return opcao;
}
