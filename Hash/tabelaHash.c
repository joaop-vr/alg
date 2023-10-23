#include "tabelaHash.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matarProgramaFaltaMemoria() {
    fputs("Falha ao alocar memoria.\n", stderr);
    exit(1);
}

struct aluno* getAluno1() {
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if (!retorno) matarProgramaFaltaMemoria();
    retorno->nome = malloc(sizeof("Joao Pedro Vicente Ramalho"));  // sizeof conta o \0
    if (!retorno->nome)
        matarProgramaFaltaMemoria();
    retorno->nomeDinf = malloc(sizeof("jpvr22"));
    if (!(retorno->nomeDinf))
        matarProgramaFaltaMemoria();

    strcpy(retorno->nome, "Joao Pedro Vicente Ramalho");
    strcpy(retorno->nomeDinf, "jpvr22");
    retorno->grr = 20224169;

    return retorno;
}

struct aluno* getAluno2() {
    return NULL;
}

void imprimirDadosAlunos() {
    struct aluno* aluno = getAluno1();

    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);

    aluno = getAluno2();
    if (!aluno) return;

    printf("...E... \n\n");
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);
}

struct slot** gerarTabelaHash(size_t tamTabela) {

    struct slot** tabela = (struct slot**)malloc(tamTabela * sizeof(struct slot*));

    if (tabela == NULL)
        return NULL;

    for (int i = 0; i < tamTabela; i++) {

        tabela[i] = alocarNodo();

        // Verifica se houve um erro na alocação de memória
        if (tabela[i] == NULL)
            return NULL;

    }

    return tabela;
}

struct nodoHash* inserir(struct slot* tabelaHash[], size_t tamTabela, int chave) {

    long int indice;
    
    struct nodoHash* novo = malloc(sizeof(struct nodoHash));
    if (!novo) matarProgramaFaltaMemoria();

    // funcaoHash() retorna o indice da tabela em que a chave será inserida
    indice = funcaoHash(tamTabela, chave);

    // Checando se há duplicatas
    if (buscar(tabelaHash, tamTabela, chave) != NULL) { 
        free(novo);
        return NULL;
    }

    // Insere o novo nodo na lista
    inserirNodoHash(tabelaHash[indice], novo, chave);

    return novo;
}

void liberarTabelaHash(struct slot* tabelaHash[], size_t tamTabela){

    int i;
    struct nodoHash* prox, *apagar;

    for (i = 0; i < tamTabela; i++) {
        if (tabelaHash[i]->inicio != NULL) {
            apagar = tabelaHash[i]->inicio;
            while (apagar != NULL) {
                prox = apagar->proximo;
                free(apagar);
                apagar = prox;
            }
            
        }
        free(tabelaHash[i]);
    }

    free(tabelaHash);
}

void imprimirTabelaHash(struct slot* tabelaHash[], size_t tamTabela) {

    int i;
    struct nodoHash* aux;

    for (i = 0; i < tamTabela; i++) {
        printf("%i", i);
        if(tabelaHash[i]->inicio == NULL)
            printf(" NULL\n");
        else {
            for (aux = tabelaHash[i]->inicio; aux != NULL; aux = aux->proximo) {
                if ((aux) && (aux->proximo != NULL))
                    printf(" [%i] ->", aux->chave);
                else if ((aux) && (aux->proximo == NULL))
                    printf(" [%i] -> NULL", aux->chave);
            }
            printf("\n");
        }
        
    }
}

struct nodoHash* buscar(struct slot* tabelaHash[], size_t tamTabela, int chave) {

    long int indice;
    struct nodoHash* aux;

    // funcaoHash() retorna o indice da tabela em que a chave será inserida
    indice = funcaoHash(tamTabela, chave);

    for (aux = tabelaHash[indice]->inicio; aux != NULL; aux = aux->proximo) {
        if (aux->chave == chave)
            return aux; // Encontrou
    }

    return NULL; // Não achou
}


void excluir (struct slot* tabelaHash[], size_t tamTabela, struct nodoHash* nodo) {

    long int indice;

    // funcaoHash() retorna o indice da tabela em que a chave será inserida
    indice = funcaoHash(tamTabela, nodo->chave);

    // Chamando a função que excluirá o nodo
    excluirNodoHash(tabelaHash[indice], nodo);

}

struct slot* alocarNodo() {

    struct slot* nodoSlot = (struct slot*)malloc(sizeof(struct slot));

    // Verifica se a alocação de memória foi bem-sucedida
    if (!nodoSlot) matarProgramaFaltaMemoria();
    
    // Inicializando os campos do nodo
    nodoSlot->inicio = NULL;
    nodoSlot->fim = NULL;

    return nodoSlot;
}

void wrapperExcluir (struct slot* tabelaHash[], size_t tamTabela, int chave) {

    struct nodoHash* alvoExclusao;
    
    alvoExclusao = buscar(tabelaHash, tamTabela, chave);

    // Se a busca encontrou o nodo, chamamos a função para excluí-lo
    // caso contrário informamos a falha
    if (alvoExclusao != NULL)
        excluir(tabelaHash, tamTabela, alvoExclusao);
    else
        printf("Falha ao remover %i.\n", chave);

}

long int funcaoHash (size_t tamTabela, int chave) {
    
    long int aux;

    if (chave >= 0) 
        return chave % tamTabela;
    else {                          // Tratando chaves negativas
        chave = (-1)*chave;
        aux = chave % tamTabela;
        return aux;
    }

}