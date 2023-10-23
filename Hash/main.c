#include <stdio.h>
#include <stdlib.h>

#include "tabelaHash.h"
#include "operacoes.h"

int main() {

	imprimirDadosAlunos();

    size_t tamTabela = obterTamTabela();

    struct slot** tabela = gerarTabelaHash(tamTabela);

    if (!tabela) {
        printf("Erro: não foi possível alocar a tabela.\n");
        exit(1);
    }

    operacoes(tabela, tamTabela);

    liberarTabelaHash(tabela, tamTabela);
    
    return 0;
}