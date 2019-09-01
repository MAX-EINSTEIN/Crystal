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


#include "../include/vector.h"
#include <string.h>


/**
 * A _Vector struct is used to represent a vector.
 * The empty list is represented by a NULL pointer. 
 */

struct _Vector{
    VectorValue array;
    size_t cur_index;
    size_t size;
    size_t capacity;
};


Vector* vector_new(size_t init_size){
    Vector * new_vector = (Vector*) malloc(sizeof(Vector));
    new_vector->array = (VectorValue) malloc(sizeof(VectorValue)*init_size);
    new_vector->cur_index = 0;
    new_vector->size = 0;
    new_vector->capacity = init_size;
    return new_vector;
}


void vector_free(Vector* vector){
    free(vector->array);
    free(vector);
}


VectorValue vector_realloc(Vector* vector){
    size_t reallocation_factor = 2;
    vector->capacity *= reallocation_factor;
    return realloc(vector->array,vector->capacity);
}


bool vector_push_back(Vector* vector,VectorValue data){
    if(vector->size==vector_capacity){
        vector->array = vector_realloc(vector);
    }
    
    ++vector->cur_index;
}