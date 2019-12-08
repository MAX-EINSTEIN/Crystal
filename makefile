all: list stack queue vector
	ar -rcs build/libcrystal.a build/list.o build/stack.o build/queue.o build/vector.o

list: include/list.h src/list.c
	gcc -O3 -c src/list.c -o build/list.o

stack: list include/stack.h src/stack.c
	gcc -O3 -c src/stack.c build/list.o -o build/stack.o

queue: list include/queue.h src/queue.c
	gcc -O3 -c src/queue.c build/list.o -o build/queue.o

vector: include/vector.h  src/vector.c
	gcc -O3 -c src/vector.c -o build/vector.o	

clean:
	rm build/libcrystal.a
	rm build/list.o
	rm build/stack.o
	rm build/queue.o
	rm build/vector.o
