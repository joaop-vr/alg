#ifndef OPERACOES_H_
#define OPERACOES_H_

#include "tabelaHash.h"

// A partir do resultado de obterComando() chama as funções de tabelaHash.c
void operacoes(struct slot* tabelaHash[], size_t tamTabela);

// Lê o comando do usuário e o interpreta (indifica o comando e a chave)
long int obterComando();

// Printa as opções de comando válidas
void help ();

// Lê o tamanho da tabela passado pelo usuário
size_t obterTamTabela ();

#endif