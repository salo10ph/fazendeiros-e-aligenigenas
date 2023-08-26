#define TAMANHO_MAXIMO 3

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

void empilhar(Pilha * p, char x) {
    if(p -> tamanho < TAMANHO_MAXIMO){
        No * no = malloc(sizeof(No));
        no -> valor = x;
        no -> proximo = p -> topo;
        p -> topo = no;
        p -> tamanho++;
    }
}

No * desempilhar(Pilha * p, char * a) {
    No * no = NULL;
    if (p -> topo) {
        no = p -> topo;
        *a = no -> valor;
        p -> topo = no -> proximo;
        p -> tamanho--;
    }
    return no;
}

void imprimir(No * no) {
    if (no) {
        switch (no -> valor){
            case 'V':
                printf("Vaca \n");
                break;
            case 'P':
                printf("Porco \n");
                break;
            case 'C':
                printf("Cavalo \n");
                break;
            case 'O':
                printf("Ovelha \n");
                break;
    }
        imprimir(no -> proximo);

    }
}

    int op, valor;
    No * no;
    Pilha p;
    Pilha p2;
