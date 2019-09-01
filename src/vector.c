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
    VectorValue* array;
    size_t size;
    size_t capacity;
};


Vector* vector_new(size_t init_size){
    // If a non-positive size is provided, initialize with an appropriate value
    if(init_size <= 0){
        init_size = 32;
    }

    Vector * new_vector = (Vector*) malloc(sizeof(Vector));
    if(new_vector == NULL){
        return NULL;
    }

    new_vector->size = 0;
    new_vector->capacity = init_size;

    new_vector->array = (VectorValue) malloc(sizeof(VectorValue)*init_size);
    if(new_vector->array == NULL){
        return NULL;
    }

    return new_vector;
}


void vector_free(Vector* vector){
    if(vector != NULL){
        free(vector->array);
        free(vector);
    }
}


static bool vector_realloc(Vector* vector){
    size_t reallocation_factor = 2;
    size_t new_size = vector->size * reallocation_factor;

    VectorValue* new_array = realloc(vector->array,sizeof(VectorValue) * new_size);

    if(new_array == NULL){
        return false;
    }

    vector->array = new_array;
    vector->capacity = new_size;
    return true;
}


bool vector_insert(Vector* vector, VectorValue data, size_t index){
    // Return false if index is greater than vector's size
    if(index > vector->size){
        return false;
    }

    // Reallocate the vector if required
    if(vector->size + 1 > vector->capacity){
        if(!vector_realloc(vector)){
            return false;
        }
    }

    // Move the index of vector array from index onwards
    memmove(&vector->array[index + 1],
            &vector->array[index],
            (vector->size - index) * sizeof(VectorValue));

    // Insert the new data at specified index
    vector->array[index] = data;
    ++vector->size;

    return true;
}


bool vector_push_front(Vector* vector, VectorValue data){
    return vector_insert(vector, data, 0);
}


bool vector_push_back(Vector* vector,VectorValue data){
    return vector_insert(vector, data, vector->size);
}


size_t vector_size(Vector *vector){
    return vector->size;
}


size_t vector_capacity(Vector *vector){
    return vector->capacity;
}


VectorValue vector_at(Vector* vector, size_t index){
    return vector->array[index];
}