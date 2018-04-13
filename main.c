#include <stdio.h>
#include <malloc.h>

typedef struct Lista {
    int valor;
    struct Lista *proximo;
    struct Lista *anterior;
} lista;

lista *p, *aux, *inicio = NULL, *fim = NULL;
int contador = 0;

void inserir(int valor, int posicao) {
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
            // adiciona sempre no final da lista
            if (posicao == contador) {
                aux = inicio;
                while (aux->proximo != NULL) {
                    aux = aux->proximo;
                }
                aux->proximo = p;
                p->anterior = aux;
                fim = p;
            } else if (posicao == 0) { // adiciona sempre no inicio da lista
                p->proximo = inicio;
                inicio->anterior = p;
                fim = inicio;
                inicio = p;
            } else { // se caso nao for nenhum dos dois, entao será adicionado no meio da lista

            }
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
// falta ajeitar a inserção no inicio da lista, porque ela nao consegue dar continuidade na lista se for inserida entre os valores normais
// falta inserir no meio, rever lógica
int main() {
    inserir(1, 1);
    inserir(2, 2);
    inserir(3, 3);
    inserir(4, 4);
    inserir(22, 0);
    imprimir();
    return 0;
}