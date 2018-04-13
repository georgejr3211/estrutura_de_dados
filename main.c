#include <stdio.h>
#include <malloc.h>

typedef struct Lista {
    int valor;
    struct Lista *proximo;
    struct Lista *anterior;
} lista;

lista *p, *aux, *inicio = NULL, *fim = NULL;
int contador = 0;

void inserir(int valor) {
    p = (lista *) malloc(sizeof(lista));
    if (p == NULL) {
        printf("Memoria cheia\n");
    } else {
        contador++;
        p->valor = valor;
        p->proximo = NULL;
        p->anterior = NULL;
        if (inicio == NULL) {
            inicio = p;
        } else {
            aux = inicio;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = p;
            p->anterior = aux;
            fim = p;
        }
    }
}

void imprimir() {
    aux = inicio;
    while (aux != NULL) {
        printf("valor: %i\n", aux->valor);
        printf("atual: %x\n", aux);
        printf("anterior: %x\n", aux->anterior);
        printf("proximo: %x\n", aux->proximo);
        printf("-------------\n");
        aux = aux->proximo;
    }
    printf("total de elementos na lista: %i\n", contador);
}

int main() {
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    imprimir();
    return 0;
}