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
    No * no = malloc(sizeof(No));
    no -> valor = x;
    no -> proximo = p -> topo;
    p -> topo = no;
}

No * desempilhar(Pilha * p, char * a) {
    No * no = NULL;
    if (p -> topo) {
        no = p -> topo;
        *a = no -> valor;
        p -> topo = no -> proximo;
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

int main2() {
    do {
        printf("\n0-Sair\n1-Empilhar\n2-Desempilhar\n3-Imprimir\n");
        scanf("%d", & op);
        switch (op) {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Valor a ser empilhado:");
            scanf("%d", & valor);
            empilhar( & p, valor);
            break;
        case 2:
            //no = desempilhar( & p, char);
            if (no) {
                printf("\tDesempilhando: %d\n", no -> valor);
            }
            break;
        case 3:
            printf("\n-------- PILHA --------\n");
            imprimir(p.topo);
            printf("\n-------- PILHA --------");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (op != 0);
    return 0;

}
