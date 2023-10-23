#ifndef LISTA_H
#define LISTA_H

#include "tabelaHash.h"

// Insere um nodo do tipo nodoHash em um slot da tabela Hash
void inserirNodoHash (struct slot* S, struct nodoHash* novo, int chave);

// Exclui o nodo passado como parâmetro do slot em questão
void excluirNodoHash (struct slot* Slot, struct nodoHash* nodo);


#endif