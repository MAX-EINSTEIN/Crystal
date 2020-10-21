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
 * @file clist.h
 *
 * Circularly-linked list.
 *
 * A circularly-linked list (represented by the @ref CList structure)
 * stores a collection of values.  
 * Each entry in the list (represented by a pointer to a @ref CListEntry
 * structure) contains a link to the next entry.  It is only
 * possible to iterate over entries in a singly linked list in one
 * direction.
 *
 * To create a new list, create a variable which is
 * a pointer to a @ref CList, and initialise it to NULL.
 * Then use @ref clist_new function to initialise it.
 *
 * To free a list, use @ref clist_free.
 *
 * To add a new value at the start of a list, use @ref clist_push_front.
 * To add a new value at the end of a list, use @ref clist_push_back.
 *
 * To find the size of a list, use @ref clist_size.
 *
 * To access a value in a list by its index in the list, use
 * @ref clist_value_at.
 *
 *
 * To find a particular entry in a list by its index, use
 * @ref clist_entry_at.
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
typedef struct _CList CList;


/**
 * Represents an entry in a singly-linked list. 
 */
typedef struct _CListEntry CListEntry;


/**
 * Value stored in a list.
 */
typedef void* CListValue;


typedef void (*CListValueOperation)(CListValue value);


/**
 * Create a new list.
 *
 * @return            Pointer to the new list (CList*)
 */
CList* clist_new();

/**
 * Free an entire list.
 *
 * @param list           The list to free.
 */
void clist_free(CList *list);


/**
 * Find the length of a list.
 *
 * @param list       The list.
 * @return           The number of entries in the list.
 */
size_t clist_size(CList* list);


bool clist_empty(CList* list);


/**
 * Prepend a value to the start of a list.
 *
 * @param list      Pointer to the list to prepend to.
 * @param data      The value to prepend.
 * @return          The new entry in the list, or NULL if it was not possible
 *                  to allocate a new entry.
 */
bool clist_push_front(CList* list, CListValue data);


/**
 * Append a value to the end of a list.
 *
 * @param list      Pointer to the list to append to.
 * @param data      The value to append.
 * @return          The new entry in the list, or NULL if it was not possible
 *                  to allocate a new entry.
 */
bool clist_push_back(CList* list, CListValue data);


/**
 * Removes a value from the start of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */
bool clist_pop_front(CList *list);


/**
 * Removes a value from the end of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */
bool clist_pop_back(CList *list);

void clist_traverse(CList* list, CListValueOperation operation);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef SLIST_H */