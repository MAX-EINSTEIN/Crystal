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
 * @file vector.h
 *
 * @brief Vector (a dynamic sized array)
 *
 * A vector is a sequential stored collection of values. The size of the
 * vector keeps on increasing whenever new elements are added.
 *
 * To create an empty vector, create a new variable which is a pointer to
 * a @ref Vector structure, and initialise it to NULL.
 * To destroy an entire vector, use @ref vector_free.
 *
 * To add a value to a vector, use @ref vector_push_back or @ref vector_push_front or @ref vector_insert.
 *
 * To remove a value from a vector, use @ref vector_remove_at or
 * @ref vector_remove_data.
 *
 *
 * To access the data in a vector by index, use @ref vector_at
 *
 * To sort a vector, use @ref vector_sort.
 *
 */


#include <stdlib.h>
#include <stdbool.h>


/**
 * A _Vector struct is used to represent a vector.
 * The empty list is represented by a NULL pointer. 
 * To initialise a new vector, 
 * simply create a variable of this type
 * by calling @ref vector_new
 */
typedef struct _Vector Vector;


/**
 * A value stored in a vector
*/
typedef void* VectorValue;


/**
 * Returns a newly instantiated _Vector struct
 * @param init_size   Initial size of vector
 * @return            A pointer to the instantiated structure           
 */
Vector* vector_new(size_t init_size);


/**
 * Destroys and frees the memory occupied by Vector
 * @param vector      The vector to be freed
 */
void vector_free(Vector* vector);


/**
 * Inserts a value at specified index of a vector
 * @param vector      Pointer to the vector to insert to
 * @param data        Value to insert
 * @param index       Index to insert at
 * @return            True if successful, false otherwise
 */
bool vector_insert(Vector* vector, VectorValue data, size_t index);


/**
 * Prepends a value at the begining of a vector
 * @param vector      Pointer to the vector to append to
 * @param data        Value to prepend
 * @return            True if successful, false otherwise
 */
bool vector_push_front(Vector* vector, VectorValue data);


/**
 * Appends a value at the end of a vector
 * @param vector      Pointer to the vector to append to
 * @param data        Value to append
 * @return            True if successful, false otherwise
 */
bool vector_push_back(Vector* vector, VectorValue data);


/**
 * Erases a value at the specified index of the vector
 * @param vector      Pointer to the vector to erase from
 * @param index       Index of the value to be erased
 * @return            True if successful, false otherwise
 */
bool vector_erase(Vector* vector, size_t index);


/**
 * Pops a value from the front of the vector
 * @param vector      Pointer to the vector to erase from
 * @return            True if successful, false otherwise
 */
bool vector_pop_front(Vector* vector);


/**
 * Pops a value from the back of the vector
 * @param vector      Pointer to the vector to erase from
 * @return            True if successful, false otherwise
 */
bool vector_pop_back(Vector* vector);


/**
 * Returns true if there are no elements in a vector
 * @param vector      Pointer to the vector
 */
bool vector_empty(Vector* vector);


/**
 * Returns the no. of elements in a vector
 * @param vector      Pointer to the vector
 * @return            Size of the vector
 */
size_t vector_size(Vector *vector);


/**
 * Returns the capicity of a vector
 * @param vector      Pointer to the vector
 * @return            Capicity of the vector
 */
size_t vector_capacity(Vector *vector);


/**
 * Returns the element in a vector at a specified index
 * @param vector      Pointer to the vector
 * @param index       Index of the value required
 * @return            VectorValue stored at index
 */
VectorValue vector_at(Vector* vector, size_t index);


/**
 * Returns the element in a vector at the front
 * @param vector      Pointer to the vector
 * @return            VectorValue stored at front
 */
VectorValue vector_front(Vector* vector);


/**
 * Returns the element in a vector at the back
 * @param vector      Pointer to the vector
 * @return            VectorValue stored at back
 */
VectorValue vector_back(Vector* vector);