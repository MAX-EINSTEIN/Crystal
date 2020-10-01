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
 * @file slist.h
 *
 * Singly-linked list.
 *
 * A singly-linked list (represented by the @ref SList structure)
 * stores a collection of values.  
 * Each entry in the list (represented by a pointer to a @ref SListEntry
 * structure) contains a link to the next entry.  It is only
 * possible to iterate over entries in a singly linked list in one
 * direction.
 *
 * To create a new singly-linked list, create a variable which is
 * a pointer to a @ref SList, and initialise it to NULL.
 * Then use @ref slist_new function to initialise it.
 *
 * To destroy a singly linked list, use @ref slist_free.
 *
 * To add a new value at the start of a list, use @ref slist_push_front.
 * To add a new value at the end of a list, use @ref slist_push_back.
 *
 * To find the size of a list, use @ref slist_size.
 *
 * To access a value in a list by its index in the list, use
 * @ref slist_value_at.
 *
 *
 * To find a particular entry in a list by its index, use
 * @ref slist_entry_at.
 *
 */

#ifndef SLIST_H
#define SLIST_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <stdbool.h>


/**
 * A _SList struct is used to represent a Singly-linked list.
 * The empty list is represented by a NULL pointer. 
 * To initialise a new singly linked list, 
 * simply create a variable of this type
 * containing a pointer to NULL.
 */
typedef struct _SList SList;


/**
 * Represents an entry in a singly-linked list. 
 */
typedef struct _SListEntry SListEntry;


/**
 * Value stored in a list.
 */
typedef void* SListValue;


/**
 * Callback function used to compare values in a list when sorting.
 *
 * @return   A negative value if value1 should be sorted before value2,
 *           a positive value if value1 should be sorted after value2,
 *           zero if value1 and value2 are equal.
 */
typedef int (*SListCompareFunc)(SListValue value1, SListValue value2);


/**
 * Callback function used to determine of two values in a list are
 * equal.
 *
 * @return   A non-zero value if value1 and value2 are equal, zero if they
 *           are not equal.
 */
typedef int (*SListEqualFunc)(SListValue value1, SListValue value2);


typedef void (*SListValueOperation)(SListValue value);


/**
 * Create a new list.
 *
 * @return            Pointer to the new list (SList*)
 */
SList* slist_new();

/**
 * Free an entire list.
 *
 * @param list           The list to free.
 */
void slist_free(SList *list);


/**
 * Find the length of a list.
 *
 * @param list       The list.
 * @return           The number of entries in the list.
 */
size_t slist_size(SList* list);


bool slist_empty(SList* list);


/**
 * Prepend a value to the start of a list.
 *
 * @param list      Pointer to the list to prepend to.
 * @param data      The value to prepend.
 * @return          The new entry in the list, or NULL if it was not possible
 *                  to allocate a new entry.
 */
bool slist_push_front(SList* list, SListValue data);


/**
 * Append a value to the end of a list.
 *
 * @param list      Pointer to the list to append to.
 * @param data      The value to append.
 * @return          The new entry in the list, or NULL if it was not possible
 *                  to allocate a new entry.
 */
bool slist_push_back(SList* list, SListValue data);


bool slist_insert_at(SList* list, SListValue data, size_t n);


/**
 * Removes a value from the start of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */
bool slist_pop_front(SList *list);


/**
 * Removes a value from the end of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */
bool slist_pop_back(SList *list);


bool slist_remove_at(SList* list, size_t n);


/**
 * Retrieve the value stored at a specified index in the list.
 *
 * @param list       The list.
 * @param n          The index into the list.
 * @return           The value stored at the specified index, or
 *                   @ref SLIST_NULL if unsuccessful.
 */
SListValue slist_value_at(SList* list, size_t n);


void slist_traverse(SList* list,  SListValueOperation operation);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef SLIST_H */