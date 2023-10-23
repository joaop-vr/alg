parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab2_GRR20224169

all: $(nomePrograma)

$(nomePrograma): main.o tabelaHash.o operacoes.o lista.o
	gcc -o $(nomePrograma) main.o tabelaHash.o operacoes.o lista.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

tabelaHash.o: tabelaHash.h tabelaHash.c
	gcc -c tabelaHash.c $(parametrosCompilacao)

operacoes.o: operacoes.h operacoes.c
	gcc -c operacoes.c $(parametrosCompilacao)

lista.o: lista.h lista.c
	gcc -c lista.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)