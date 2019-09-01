/*
Copyright (c) 2019, Junaid Siddiqui
Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted, provided
that the above copyright notice and this permission notice appear
in all copies.
THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "../include/stack.h"

#include "../include/list.h"


struct _Stack{
    List* list;
};


Stack* stack_new(){
    Stack* new_stack =(Stack*) malloc(sizeof(Stack));
    new_stack->list = list_new();
    return new_stack;
}


void stack_free(Stack* stack){
    list_free(stack->list);
    free(stack);
}


bool stack_push(Stack* stack, StackValue data){
    List** stack_list = &(stack->list);
    return list_push_back(stack_list,data);
}


bool stack_pop(Stack* stack){
    List** stack_list = &(stack->list);
    return list_pop_back(stack_list);
}


StackValue stack_top(Stack* stack){
    return list_nth_data(stack->list,list_size(stack->list));
}     


bool stack_empty(Stack* stack){
    return list_empty(stack->list);
}


size_t stack_size(Stack* stack){
    return list_size(stack->list);
}