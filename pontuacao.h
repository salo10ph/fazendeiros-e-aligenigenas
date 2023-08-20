int pontuacao = 0;

#define PONTOS 10

void adicionaPontos(){
    pontuacao += PONTOS;
}

void adicionaPontosBonus(){
    pontuacao += PONTOS * 5;
}

void removePontos(){
    pontuacao -= PONTOS;
}

int retornaPontuacao(){
    return pontuacao;
}
