#define MAPW 4
#define MAPH 4

char tecla = '0';
int jogadorY = 21;
int jogadorX = 53;
char caracterAnterior = ' ';
char matrix[400][400] = {
"                                                      ()",
"                                             _________||_________",
"                                            /     ||||||||||||   \\",
"                                           /                      \\",
"                                          / |||||||||||||||||||||  \\",
"                                         /__________________________\\",
"                                         \\  |||||||||||||||||||||   /",
"                                          \\________________________/",
"                                               \\______________/",
"                                                /  ------  \\",
"                                               /  --------  \\",
"                                              / ------------ \\",
"                                             /----------------\\",
"                                            |        0        |",
"                                            |                 |",
"                                            |                 |",
"                                            |                 |",
"                                            |                 |",
"|---------------|                           |                 |                         |--------------------------|",
"|               |                           |                 |                         |                          |",
"|       F       |                           |                 |                         |             C1           |",
"|               |---------------------------                   -------------------------|                          |",
"|               |0                                                                     0|                          |",
"|---------------|--------------------------------------------------------------------|  |---------------------------|",
"                                                                                     |  |                           |",
"                                                                                     |  |                           |",
"                                                                                     | 0|             C2            |",
"                                                                                     |--|                           |",
"                                                                                        |                           |",
"                                                                                        |---------------------------|"};

/*
"------"
"|****|"
"|****|"
"|****|"
"|****|"
"------"
*/

//int map [MAPH][MAPH];

//int mapa = {}
void printarMapa() {
    for(int i = 0; i < 30; i++)
    if(i != jogadorY)
        printf("%s\n", matrix[i]);
    else {
        for(int j = 0; j < strlen(matrix[i]); j++){
            if(j != jogadorX) printf("%c", matrix[i][j]);
            else printf("P");
        }
        printf("\n");
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
            matrix[jogadorY][jogadorX] = 'P';
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
        case 22:
            if(jogadorX == 17) opcao = 3;
            else opcao = 4; //87
            break;
        case 26:
            opcao = 5;
            break;
    }
    return opcao;
}
/*
void printMap(){



    for(int lin= 0; lin<6; lin++){


        if(lin > 0 &&lin < 5){
            for(int col = 0; col<6; col++){

                if(col > 0 && col < 5){
                    printf("*");
                }
                else{
                    printf("|");
                }

            }

        }
        else{

            for(int col = 0; col<6; col++){

                printf("-");

            }
        }
        printf("\n");
    }
}*/
