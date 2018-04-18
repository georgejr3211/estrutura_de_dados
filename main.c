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
        } else if (posicao == contador) {
            // adiciona sempre no final da lista
            aux = inicio;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = p;
            p->anterior = aux;
            fim = p;
        } else if (posicao == 0) {
            p->proximo = inicio;
            p->anterior = NULL;
            inicio->anterior = p;
            inicio = p;
        } else{
            if((contador % 2)== 0){
                aux = inicio;
                for(int i = 1; i < contador/2; i++){
                    aux = aux->proximo;
                }
                p->anterior = aux;
                p->proximo = aux->proximo;
                aux->proximo = p;
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
// editado a inserçao no inicio, agora falta ajeitar a insersao no meio
int main() {
    inserir(50, 1);
    inserir(150, 2);
    // valor aqui
    inserir(25, 3);
    inserir(120, 5);
    inserir(122, 5);
    inserir(123, 9);
    imprimir();
    return 0;
}