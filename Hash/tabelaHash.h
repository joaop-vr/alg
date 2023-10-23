#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stddef.h>

struct nodoHash{
    int chave;
    struct nodoHash* proximo;
    struct nodoHash* anterior;
};

struct aluno{
    char* nome;//nome completo
    char* nomeDinf;//nome de usuário nas servidoras do dinf
    unsigned int grr;
};

struct slot {
    struct nodoHash* inicio;
    struct nodoHash* fim;
};

struct aluno* getAluno1();

//retorne NULL se o aluno2 não existir
struct aluno* getAluno2();

void imprimirDadosAlunos();

//aloca a tabela hash na memória
struct slot** gerarTabelaHash(size_t tamTabela);

//insere a chave na tabela hash. Duplicatas não são permitidas.
//Retorna o nodo inserido, ou NULL em caso de problemas (ex.: caso a chave seja uma duplicata)
struct nodoHash* inserir(struct slot* tabelaHash[], size_t tamTabela, int chave);

//deleta a tabela hash
void liberarTabelaHash(struct slot* tabelaHash[], size_t tamTabela);

//imprime na tela a tabela completa
void imprimirTabelaHash(struct slot* tabelaHash[], size_t tamTabela);

//busca o nodo com o chave, ou retorna NULL caso tal nodo não exista
struct nodoHash* buscar(struct slot* tabelaHash[], size_t tamTabela, int chave);

//exclui o nodo apontado
void excluir(struct slot* tabelaHash[], size_t tamTabela, struct nodoHash* nodo);

//chama a função buscar,
//se ela encontrou o nodo, o programa continua e chama a função excluir(),
//caso contrário informa o erro
void wrapperExcluir (struct slot* tabelaHash[], size_t tamTabela, int chave);

//retorna (chave mod tamTabela)
long int funcaoHash (size_t tamTabela, int chave);

//aloca memória para os nodos do vetor de structs
struct slot* alocarNodo();

#endif // TABELA_HASH_H