#include <stdio.h>
#include "../include/stack.h"

int main(){

    printf("\nTESTING stack\n");

    int a[10] = {1, 2, 3, 4, 5};

    Stack* stack = stack_new();

    printf("\nTESTING all stack methods\n");
    {
        if(stack_empty(stack)){
            printf("The stack is empty\n");
        }
        stack_push(stack,&a[0]);
        stack_push(stack,&a[1]);
        stack_push(stack,&a[2]);
        if(stack_empty(stack)){
            printf("The stack is empty\n");
        }
        printf("Stack size: %ld\n",stack_size(stack));
        int data1 = *((int*)stack_top(stack));
        printf("Top element: %d\n",data1);
        stack_pop(stack);
        stack_pop(stack);
        printf("Stack size: %ld\n",stack_size(stack));
        int data2 = *((int*)stack_top(stack));
        printf("Top element: %d\n",data2);
        stack_push(stack,&a[3]);
        stack_push(stack,&a[4]);
        printf("Stack size: %ld\n",stack_size(stack));
        int data3 = *((int*)stack_top(stack));
        printf("Top element: %d\n",data3);
    }

    stack_free(stack);

    return 0;
}