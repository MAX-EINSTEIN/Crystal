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


/**
 * @file queue.h
 *
 * @brief Queue
 *
 * A queue stores a collection of values and provide operations like adding
 * values/elements at back and removing from front. A queue is FIFO structure
 * i.e. First In First Out
 *
 * To insert an element into a queue use queue_push while passing the Queue
 * pointer and the value to insert.
 *
 * To remove an element from a queue use queue_pop while passing the Queue
 * pointer. The first entry pushed would be popped/removed.
 * 
 * Access the element at front of the queue using queue_front
 * 
 * Access the element at back of the queue using queue_back
 * 
 * Check for the emptiness of queue using queue_empty
 * 
 * Size of the queue can be retrieved using queue_size
 */

#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


/**
 * A queue is represented by a struct _Queue and typedef-ed to Queue.
 * An empty queue is represented by a NULL pointer.
 */

typedef struct _Queue Queue;


/**
 * A value stored in a queue.
 */

typedef void* QueueValue;


/**
 * Returns a new instance of Queue
 * @return            Pointer to the new queue (Queue)
 */

Queue* queue_new();


/**
 * Frees the passed instance of Queue
 */

void queue_free(Queue* queue);


/**
 * Inserts an element at front of the queue
 * @return            True if successfull, false otherwise
 */

bool queue_push(Queue* queue, QueueValue data);


/**
 * Removes an element from front of the queue
 * @return            True if successfull, false otherwise
 */

bool queue_pop(Queue* queue);


/**
 * Returns an element which is at front of the queue
 * @return            Value at the front of the queue
 */

QueueValue queue_front(Queue* queue);


/**
 * Returns an element which is at back of the queue
 * @return            Value at the back of the queue
 */

QueueValue queue_back(Queue* queue);


/**
 * Checks for the emptiness of a queue
 * @return            Tur if the queue is empty, false otherwise
 */

bool queue_empty(Queue* queue);


/**
 * Returns size of the queue
 * @return            Size of the queue
 */

size_t queue_size(Queue* queue);