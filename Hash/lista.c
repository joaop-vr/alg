#include "tabelaHash.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void inserirNodoHash (struct slot* S, struct nodoHash* novo, int chave) {

    /*lista vazia*/
    if (S->fim == NULL) {
        novo->anterior = NULL;
        novo->proximo = NULL;
        novo->chave = chave;
        S->inicio = novo;
        S->fim = novo;
    }   
    else {
        /*Inserindo no fim*/
        novo->anterior = S->fim;
        S->fim->proximo = novo;
        S->fim = novo;
        novo->proximo = NULL;
        novo->chave = chave;
    }

}

void excluirNodoHash (struct slot* Slot, struct nodoHash* nodo) {

    if ((Slot->inicio == nodo) && (Slot->fim == nodo)) {    // Excluindo o único nodo da lista
        Slot->inicio = NULL;
        Slot->fim = NULL;
    }         
    else if (Slot->inicio == nodo) {                        // Excluindo o primeiro nodo 
        Slot->inicio = nodo->proximo;
        nodo->proximo->anterior = NULL;
    }
    else if (Slot->fim == nodo) {                           // Excluindo o último nodo
        Slot->fim = nodo->anterior;
        Slot->fim->proximo = NULL;
    }
    else {
        nodo->anterior->proximo = nodo->proximo;
        nodo->proximo->anterior = nodo->anterior;
    }

    free(nodo);
}