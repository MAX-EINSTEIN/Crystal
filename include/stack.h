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
 * @file stack.h
 *
 * @brief Stack.
 *
 * A stack stores a collection of values and provide operations like adding
 * and removing values/elements only on top of the stack. A stack is a LIFO 
 * data structure i.e (Last In First Out)
 *
 * To insert an element into a stack use stack_push while passing the Stack
 * pointer and the value to insert.
 *
 * To remove an element from a stack use stack_pop while passing the Stack
 * pointer. The last entry pushed would be popped/removed.
 * 
 * Access the element on the top of the stack using stack_top
 * 
 * Check for the emptiness of stack using stack_empty
 * 
 * Size of the stack can be retrieved using stack_size
 */

#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


/**
 * A stack is represented by a struct _Stack and typedef-ed to Stack.
 * A null stack is represented by a NULL pointer.
 */

typedef struct _Stack Stack;


/**
 * A value stored in a stack.
 */

typedef void* StackValue;


/**
 * Returns a new instance of _Struct
 * @return            Pointer to the new stack (Stack*)
 */

Stack* stack_new();


/**
 * Frees the passed instance of _Struct
 */

void stack_free(Stack* stack);


/**
 * Pushes an element on top of the stack
 * @return            True if successfull, false otherwise
 */

bool stack_push(Stack* stack, StackValue data);


/**
 * Pops an element from top of the stack
 * @return            True if successfull, false otherwise
 */

bool stack_pop(Stack* stack);


/**
 * Returns an element which is at top of the stack
 * @return            Value on the top of the stack
 */

StackValue stack_top(Stack* stack);


/**
 * Checks for the emptiness of a stack
 * @return            True if the stack is empty, false otherwise
 */

bool stack_empty(Stack* stack);


/**
 * Returns size of the stack
 * @return            Size of the stack
 */

size_t stack_size(Stack* stack);