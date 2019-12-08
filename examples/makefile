all: list_test stack_test queue_test vector_test
	echo "All builds successful"

list_test: ../build/list.o
	gcc -O3 -o list_test.out ../build/list.o ../src/list_test.c 

stack_test: ../build/stack.o 
	gcc -O3 -o stack_test.out ../build/list.o ../build/stack.o ../src/stack_test.c

queue_test: ../build/queue.o
	gcc -O3 -o queue_test.out ../build/list.o ../build/queue.o ../src/queue_test.c

vector_test: ../build/vector.o
	gcc -O3 -o vector_test.out ../build/vector.o ../src/vector_test.c

clean:
	rm list_test.out
	rm stack_test.out
	rm queue_test.out
	rm vector_test.out
