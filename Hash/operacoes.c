#include "tabelaHash.h"
#include "lista.h"
#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

void operacoes(struct slot* tabelaHash[], size_t tamTabela) {

    long int comando;
    struct nodoHash* retorno;
	int op;
	int valor;

    comando = obterComando();

	// Variavel 'op' recebe a identificacao da operacao
	op = comando % 10;

	// Variavel 'valor' recebe o valor passado na linha de comando
	valor = comando / 10;

	while (op != 5) {

        // Tratando chaves negativas
        if (op < 0)
            op = (-1)*op;

		switch (op) {
            
            // Caso de Inserção
			case 1:
                retorno = inserir(tabelaHash, tamTabela, valor);
                if (retorno == NULL)
                    printf("Falha ao inserir %i.\n", valor);
				break;

            // Caso de Excluir
			case 2:
                wrapperExcluir(tabelaHash, tamTabela, valor);
                break;

            // Caso de Busca
			case 3: {
                struct nodoHash* output = NULL;
                output = buscar(tabelaHash, tamTabela, valor);
                if (output != NULL)
                    printf("Encontrado %i\n", output->chave);
                else
                    printf("Não encontrado %i.\n", valor);
                
				break;}

            // Cado de Imprimir
			case 4:
                imprimirTabelaHash(tabelaHash, tamTabela);
                break;
                
		}

        comando = obterComando();
		op = comando % 10;
		valor = comando / 10;
	}
}

long int obterComando() {

    int valor;
    long int output = 0;
    char *operacao, *token;
    char linhaComando[25];

    // Obtem a linha de comando do usuário
    scanf("%[^\n]", linhaComando);
    getchar(); 

    // Variavel 'token' recebe a operacao (ex.: i, r, b, l, f)
    token = strtok(linhaComando, " ");

    if (token == NULL) {
        printf("Erro: comando inválido.\n");
        help();
    }

    // Variável 'operacao' recebe a operacao que será realizada
    operacao = token;

    switch (*operacao) {

        case 'i':
            token = strtok(NULL, " ");  
            if (token == NULL) {
                printf("Erro: comando inválido.\n");
                help();
            }
            else {
                valor = strtol(token, NULL, 10);    // Variavel 'valor' recebe a chave passada pelo usuário
                if (valor < 0)                      // Tratando chaves negativas
                    output = (valor*10) - 1;
                else
                    output = (valor*10) + 1;
            }
            break;
        
        case 'r': 
            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Erro: comando inválido.\n");
                help();
            }
            else {
                valor = strtol(token, NULL, 10);    // Variavel 'valor' recebe a chave passada pelo usuário
                if (valor < 0)                      // Tratando chaves negativas
                    output = (valor*10) - 2;
                else
                    output = (valor*10) + 2;
            }
            break;

        case 'b': 
            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Erro: comando inválido.\n");
                help();
            }
            else {
                valor = strtol(token, NULL, 10);    // Variavel 'valor' recebe a chave passada pelo usuário
                if (valor < 0)                      // Tratando chaves negativas
                    output = (valor*10) - 3;
                else
                    output = (valor*10) + 3;
            }
            break;

        case 'l': output =  4; break;

        case 'f': output =  5; break;

        default:
            printf("Erro: comando inválido.\n");
            help();
            break;
    }

    return output;
}

void help () {
    printf("Formato de comando aceito: <operacao> <valor>. Sendo:\n");
    printf("Operacoes:\n    - i: inserir\n");
    printf("    - r: remover\n");
    printf("    - b: busca\n");
    printf("    - l: imprimir\n");
    printf("    - f: finalizar\n");
    printf("Valor: valor inteiro, aceito para as funcoes i, r e b\n");
}

size_t obterTamTabela () {

    char aux[5]; 
    size_t tamTabela; //tamanho da tabela hash

    // Lendo o tam da tabela
    scanf("%[^\n]", aux);
    getchar();
    tamTabela = atoi(aux);

    // Tratando valores inválidos para a tabela
    while ((tamTabela == 0) || (strchr(aux, '-') != NULL)) {
        printf("Erro: valor inválido (deve ser um inteiro maior que zero).\n");
        scanf("%[^\n]", aux);
        getchar();
        tamTabela = atoi(aux);
    }

    return tamTabela;
}