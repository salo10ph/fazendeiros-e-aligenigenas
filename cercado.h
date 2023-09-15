#define TAMANHO_MAXIMO 3
char array1[2][3] = {'N', 'N', 'N', 'N', 'N', 'N'};

typedef struct no {
    char valor;
    struct no * proximo;
}
No;

typedef struct {
    No * topo;
    int tamanho;
}
Pilha;

char empilhar(Pilha * p, char x) {
    if(p -> tamanho < TAMANHO_MAXIMO){
        No * no = malloc(sizeof(No));
        no -> valor = x;
        no -> proximo = p -> topo;
        p -> topo = no;
        p -> tamanho++;
        return 'N';
    }
    return x;
}

No * desempilhar(Pilha * p, char * a, int cercado) {
    No * no = NULL;
    if (p -> topo) {
        no = p -> topo;
        *a = no -> valor;
        p -> topo = no -> proximo;
        p -> tamanho--;
        array1[cercado][p -> tamanho] = 'N';
    }
    return no;
}

char* mapearPilha(No * no, int local, int cercado){
        local--;
    if(no) {
        array1[cercado][local] = no -> valor;
        mapearPilha(no -> proximo, local, cercado);
    }
}

    int op, valor;
    No * no;
    Pilha p;
    Pilha p2;
