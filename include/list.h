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
 * @file list.h
 *
 * @brief Doubly-linked list.
 *
 * A doubly-linked list stores a collection of values.  Each entry in
 * the list (represented by a pointer a @ref ListEntry structure)
 * contains a link to the next entry and the previous entry.
 * It is therefore possible to iterate over entries in the list in either
 * direction.
 *
 * To create an empty list, create a new variable which is a pointer to
 * a @ref List structure, and initialise it to NULL.
 * To destroy an entire list, use @ref list_free.
 *
 * To add a value to a list, use @ref list_push_back or @ref list_push_front.
 *
 * To remove a value from a list, use @ref list_remove_entry or
 * @ref list_remove_data.
 *
 * To access an entry in the list by index, use @ref list_nth_entry or
 * @ref list_nth_data.
 *
 * To modify data in the list use @ref list_set_data.
 *
 * To sort a list, use @ref list_sort.
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Represents an entry in a doubly-linked list.  
 */
typedef struct _ListEntry ListEntry;


/**
 * A _List struct is used to represent a Doubly-linked list.
 * The empty list is represented by a NULL pointer. 
 * To initialise a new doubly linked list, 
 * simply create a variable of this type
 * containing a pointer to NULL.
 */
typedef struct _List List;


/**
 * A value stored in a list.
 */
typedef void *ListValue;


/**
 * Callback function used to compare values in a list when sorting.
 *
 * @param value1      The first value to compare.
 * @param value2      The second value to compare.
 * @return            A negative value if value1 should be sorted before
 *                    value2, a positive value if value1 should be sorted
 *                    after value2, zero if value1 and value2 are equal.
 */
typedef int (*ListCompareFunc)(ListValue value1, ListValue value2);


/**
 * Callback function used to determine of two values in a list are
 * equal.
 *
 * @param value1      The first value to compare.
 * @param value2      The second value to compare.
 * @return            True if value1 and value2 are equal, false
 *                    if they are not equal.
 */
typedef bool (*ListEqualFunc)(ListValue value1, ListValue value2);


/**
 * Callback function used to print the data in the list.
 *
 * @param data        Data to print
 */
typedef void (*ListPrintData)(ListValue data);


/**
 * Create a new list.
 *
 * @return            Pointer to the new list (List*)
 */
List* list_new();


/**
 * Free an entire list.
 *
 * @param list         The list to free.
 */
void list_free(List *list);


/**
 * Prepend a value to the start of a list.
 *
 * @param list         Pointer to the list to prepend to.
 * @param data         The value to prepend.
 * @return             True if value is appended, otherwise false
 */
bool list_push_front(List **list, ListValue data);


/**
 * Append a value to the end of a list.
 *
 * @param list         Pointer to the list to append to.
 * @param data         The value to append.
 * @return             True if value is appended, otherwise false
 */
bool list_push_back(List **list, ListValue data);


/**
 * Removes a value from the start of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */

bool list_pop_front(List **list);


/**
 * Removes a value from the end of a list.
 *
 * @param list         Pointer to the list to remove from.
 * @return             True if value is removed successfully, otherwise false
 */
bool list_pop_back(List **list);


/**
 * Retrieve the entry at a specified index in a list.
 *
 * @param list       The list.
 * @param n          The index into the list .
 * @return           The entry at the specified index, or NULL if out of range.
 */
ListEntry *list_nth_entry(List *list, unsigned int n);


/**
 * Retrieve the value at a specified entry in the list.
 *
 * @param entry      The entry to retrieve data from
 * @return           The pointer to data/value, or NULL    
 */
ListValue list_data(ListEntry* entry);



/**
 * Retrieve the value at a specified index in the list.
 *
 * @param list       The list.
 * @param n          The index into the list.
 * @return           The value at the specified index, or @ref LIST_NULL if
 *                   unsuccessful.
 */
ListValue list_nth_data(List *list, unsigned int n);


/**
 * Returns the size of a list.
 *
 * @param list       The list.
 * @return           The number of entries in the list.
 */
size_t list_size(List *list);


/**
 * Returns true if the list is empty, false otherwise
 *
 * @param list       The list.
 * @return           True if list is empty, false otherwise .
 */
bool list_empty(List *list);


/**
 * Reverses the contents of a list.
 *
 * @param list       The list.
 */
void list_reverse(List ** list);


/**
 * Prints the contents of a list.
 *
 * @param list       The list.
 * @param print_data A function to print a particular data       
 * @return           void
 */
void list_print(List *list, ListPrintData print);


/**
 * Remove all occurrences of a particular value from a list.
 *
 * @param list       Pointer to the list.
 * @param callback   Function to invoke to compare values in the list
 *                   with the value to be removed.
 * @param data       The value to remove from the list.
 * @return           The number of entries removed from the list.
 */
bool list_remove_data(List **list, ListEqualFunc callback, ListValue data);


/**
 * Remove nth entry from a list.
 *
 * @param list       Pointer to the list.
 * @param n          The position of entry to remove
 * @return           If the entry is not found in the list, returns false,
 *                   else returns true.
 */
bool list_remove_nth_entry(List** list, size_t n);


/**
 * Sort a list.
 *
 * @param list          Pointer to the list to sort.
 * @param compare_func  Function used to compare values in the list.
 */
void list_sort(List **list, ListCompareFunc compare_func);


#ifdef __cplusplus
}
#endif

#endif // LIST_H ends