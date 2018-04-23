#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Fila {
    int valor;
    struct Fila *proximo;
} fila;

fila *p, *inicio = NULL, *aux;
int cont = 0;

// fila = primeiro que entra, primeiro que sai (FIFO)

void inserir(int valor) {
    p = (fila *) malloc(sizeof(fila));
    if (p == NULL) {
        printf("memoria insuficiente\n");
    } else {
        p->valor = valor;
        p->proximo = NULL;

        if (inicio == NULL) {
            inicio = p;
        } else {
            aux = inicio;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = p;
        }

    }
}

bool isEmpty() {
    if (inicio == NULL) {
        return true;
    }
    return false;
}

void remover() {
    if (!isEmpty()) {
        aux = inicio;
        aux = aux->proximo;
        free(inicio);
        inicio = aux;
    }
}

void consultar(int valor) {
    aux = inicio;
    while (aux != NULL) {
        if (valor == aux->valor) {
            printf("indice: %i - valor: %i ", cont, aux->valor);
            break;
        }
        aux = aux->proximo;
        cont++;
    }
    printf("\n");
}

void imprimir() {
    aux = inicio;
    while (aux != NULL) {
        printf("%i  ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}


void menu(){
    int op = 0;
    int valor = 0;
    do {
        printf(" 1. inserir\n 2. remover\n 3. consultar\n 4. imprimir\n 0. sair\n");
        scanf("%i", &op);
        switch (op) {
            case 1:
                printf("informe o valor: ");
                scanf("%i", &valor);
                inserir(valor);
                printf("elemento adicionado\n");
                break;
            case 2:
                remover();
                printf("elemento removido\n");
                break;
            case 3:
                printf("informe o valor: ");
                scanf("%i", &valor);
                consultar(valor);
                break;
            case 4:
                imprimir();
                break;
            case 0:
                op = 0;
                break;
        }
    } while (op != 0);
}

int main() {
    menu();
    return 0;
};
