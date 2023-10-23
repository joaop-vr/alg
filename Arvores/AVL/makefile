parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o avl.o fila.o menu.o
	gcc -o $(nomePrograma) main.o avl.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

avl.o: avl.h avl.c
	gcc -c avl.c $(parametrosCompilacao)

menu.o: menu.c menu.h
	gcc -c menu.c $(parametrosCompilacao)

fila.o: fila.c fila.h
	gcc -c fila.c $(parametrosCompilacao)

menu.o: menu.c menu.h
	gcc -c menu.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
