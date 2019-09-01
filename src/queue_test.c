#include <stdio.h>
#include "../include/queue.h"

int main(){

    printf("\nTESTING queue\n");

    int a[10] = {1, 2, 3, 4, 5};

    Queue* queue = queue_new();

    printf("\nTESTING all queue methods\n");
    {
        if(queue_empty(queue)){
            printf("The stack is empty\n");
        }
        queue_push(queue,&a[0]);
        queue_push(queue,&a[1]);
        queue_push(queue,&a[2]);
        if(queue_empty(queue)){
            printf("The stack is empty\n");
        }
        size_t size = queue_size(queue);
        printf("Size of the queue : %ld\n",size);
        queue_pop(queue);

        int front, back;
        front = *((int*)queue_front(queue));
        back = *((int*)queue_back(queue));
        printf("Element in front: %d\n",front);
        printf("Element in back: %d\n",back);
        queue_pop(queue);
        queue_push(queue,&a[3]);
        queue_push(queue,&a[4]);
        size = queue_size(queue);
        printf("Size of the queue : %ld\n",size);

        front = *((int*)queue_front(queue));
        back = *((int*)queue_back(queue));
        printf("Element in front: %d\n",front);
        printf("Element in back: %d\n",back);
    }

    queue_free(queue);

    return 0;
}