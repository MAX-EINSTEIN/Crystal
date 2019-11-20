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


#include "../include/queue.h"

#include "../include/list.h"


struct _Queue{
    List* list;
};


Queue* queue_new(){
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->list = list_new();
    return new_queue;
}


void queue_free(Queue* queue){
    list_free(queue->list);
    free(queue);
}


bool queue_push(Queue* queue, QueueValue data){
    return list_push_back(queue->list,data);
}


bool queue_pop(Queue* queue){
    return list_pop_front(queue->list);    
}


QueueValue queue_front(Queue* queue){
    return list_nth_data(queue->list,1);    
}


QueueValue queue_back(Queue* queue){
    return list_nth_data(queue->list,list_size(queue->list));    
}


bool queue_empty(Queue* queue){
    return list_empty(queue->list);
}


size_t queue_size(Queue* queue){
    return list_size(queue->list);
}