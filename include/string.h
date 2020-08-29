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
 * @file string.h
 *
 * @brief String.
 * 
 * String is an overflow-safe impelementaion of strings for C 
 * programming language. It is represented by @ref String structure.
 * 
 * To create a new String use @ref string_new.
 * 
 * To free a String use @ref string_free.
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A _String struct is used to represent a string.
 * The empty string is represented by a NULL pointer. 
 * To initialise a new string use @ref string_new
 */
typedef struct _String String;

/**
 * Callback function used to compare two strings lexologically when sorting.
 *
 * @param value1      The first value to compare.
 * @param value2      The second value to compare.
 * @return            A negative value if value1 should be sorted before
 *                    value2, a positive value if value1 should be sorted
 *                    after value2, zero if value1 and value2 are equal.
 */
typedef int (*StringCompareFunc)(const String* value1,const String* value2);


/**
 * Callback function used to determine of two values in a list are
 * equal.
 *
 * @param value1      The first value to compare.
 * @param value2      The second value to compare.
 * @return            True if value1 and value2 are equal, false
 *                    if they are not equal.
 */
typedef bool (*StringEqualFunc)(const String* value1, const String* value2);

/**
 * Creates a new string.
 *
 * @param c_str       Char * Pointer (char *)
 * @return            Pointer to the new string (String*)
 */
String* string_new(char * c_str);


/**
 * Frees a string.
 *
 * @param string         The string to free.
 */
void string_free(String *s);


const char* string_c_str(String *s);

#ifdef __cplusplus
}
#endif

#endif // LIST_H ends