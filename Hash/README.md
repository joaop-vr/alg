Para a implementação da Tabela Hash foi criado um vetor de "struct slot".

A estrutura de "struct slot" contém:
"struct nodoHash* inicio" ponteiro para o primeiro nodo da lista encadeada;
"struct nodoHash* fim" ponteiro para o último nodo da lista encadeada;

A estrutura de "struct nodoHash" contém:
"int chave" referente a chave do nodo;
"struct nodoHash* proximo" ponteiro para o próximo nodo da lista;
"struct nodoHash* anterior" ponteiro para o nodo antecessor da lista;

============================================================

Arquivo "main.c": possui chamada para as funções:
"imprimirDadosAlunos()", "gerarTabelaHash()" e "liberarTabelaHas" (implementadas no arquivo tabelaHash.c);
"obterTamTabela()" e "operacoes()" (implementadas no arquivo operacoes.c);

============================================================

Arquivo "operacoes.c": possui a implementação das funções "help()", "obterTamTabela()", "obterComando()", "operacoes()".

A função "help()" é chamada para os casos em que o usuário fornece instruções inválidas e printa na tela os comando corretos;

A função "obterTamTabela()" lê o tamanho da tabela passada pelo usuário e trata os casos de tamanhos inválidos;

A função "obterComando()" é responsável por ler o comando passado pela entrada padrão (stdin),
interpretá-lo e retorna um inteiro correspondente a concatenação do valor passado pelo usuário
e da TAG identificadora da operação. Nesse contexto, as TAGs funcionam da seguinte forma: "1" é Inserir,
"2" é excluir, "3" é buscar, "4" é imprimir e "5" é finalizar o programa.
Por exemplo:
	
			comando: i 23 -->> 231
			comando: r 17 -->> 172
			comando: b 56 -->> 563
			comando: l    -->> 004
			comando: f    -->> 005

Foi realizado dessa forma para que o "comando()" pudesse retornar apenas um inteiro,
ao invés de retornar uma struct com campo "instrução" e "valor".
A função "operacoes()" recebe o resultado de "comando()"
e o processa (utilizando divisão por 10 para pegar o valor passado pelo usuário
e o módulo para pegar a TAG).
A partir disso chama as funções que manipulam a árvore (inserir, excluir, etc..).

============================================================

Arquivo "lista.c": possui a implementação das funções "inserirNodoHash()" e "excluirNodoHash()". Ou seja, ele é responsável pelas manipulaçoes dos nodos da lista duplamente encadeada.

A função "inserirNodoHash()" recebe a chave que será atribuida ao novo nodo, o ponteiro para o novo nodoHash e para o Slot onde ele será inserido;

A função "excluirNodoHash()" recebe o ponteiro para o nodo que se deseja excluir e o ponteiro para o Slot em que ele está armazenado;

============================================================

Arquivo "tabelaHash.c": possui a implementação das funções referentes a manipulação da Tabela Hash.

inserir: primeiramente é necessário checar se há duplicatas, se não houver, damos continuação e inserimos o novo nodoHash na lista encadeada referente ao seu Slot, caso contrário, informamos o erro;

excluir: foi criado a função "wrapperExcluir()" que realiza a busca da chave na tabela, se ela for encontrada chamamos a função "excluir()", caso contrário, informamos o erro;

funçãoHash: há dois cenários:

1) chave positiva: retorna-se (chave % tamTabela);

2) chave negativa: primeiramente multiplica-se a chave por "-1" afim de evitar situações inesperadas com o operador "%" para então calcular e retornar (chave % tamTabela);