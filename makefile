all: list slist clist stack queue vector
	echo "All tests generated"

list: include/list.h src/list.c test/list_test.c
	gcc -O3 src/list.c test/list_test.c -o build/list_test.out

slist: include/slist.h src/slist.c test/slist_test.c
	gcc -O3 src/slist.c test/slist_test.c -o build/slist_test.out

clist: include/clist.h src/clist.c test/clist_test.c
	gcc -O3 src/clist.c test/clist_test.c -o build/clist_test.out

stack: include/stack.h src/stack.c test/stack_test.c src/list.c
	gcc -O3 src/list.c src/stack.c test/stack_test.c -o build/stack_test.out

queue: include/queue.h src/queue.c test/queue_test.c src/list.c
	gcc -O3 src/list.c src/queue.c test/queue_test.c -o build/queue_test.out

vector: include/vector.h  src/vector.c test/vector_test.c
	gcc -O3 src/vector.c test/vector_test.c -o build/vector_test.out

clean:
	rm build/list_test.out
	rm build/stack_test.out
	rm build/queue_test.out
	rm build/vector_test.out
