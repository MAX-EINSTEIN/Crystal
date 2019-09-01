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
#include <stdio.h>
#include <string.h>

#include "../include/list.h"


/* Entry of a Doubly Linked List */
struct _ListEntry {
	ListValue data;
	ListEntry *prev;
	ListEntry *next;
};


/* Doubly Linked List */
struct _List
{
    ListEntry * head;
    ListEntry * tail;
    size_t size;
};


List* list_new(){
    List * new_list = (List*) malloc(sizeof(List));
    if(new_list == NULL){
        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}


void list_free(List *list){
    ListEntry* iterator = list->head;
    while(iterator!=NULL){
        ListEntry* next = iterator->next;
        free(iterator);
        iterator = NULL;
        iterator = next;
    } 
    free(list);
}


bool list_push_front(List **list, ListValue data){
    if(list == NULL){
        return false;
    }
    ListEntry * newEntry = (ListEntry*) malloc(sizeof(ListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;

    if((*list)->head != NULL){
        (*list)->head->prev = newEntry;
    }

    newEntry->prev = NULL;
    newEntry->next = (*list)->head;
    (*list)->head = newEntry;

    if((*list)->tail == NULL){
        (*list)->tail = newEntry;
    }

    (*list)->size++;
    return true;
}


bool list_push_back(List **list, ListValue data){
    if(list == NULL){
        return false;
    }
    ListEntry * newEntry = (ListEntry*) malloc(sizeof(ListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;
    newEntry->next = NULL;

    if((*list)->tail!=NULL){
        (*list)->tail->next = newEntry;
    }

    newEntry->prev = (*list)->tail;
    (*list)->tail = newEntry;

    if((*list)->head == NULL){
        (*list)->head = newEntry;
    }

    (*list)->size++;
    return true;
}


bool list_pop_front(List **list){
    if(list == NULL){
        return false;
    }

    ListEntry* head = (*list)->head;
    ListEntry* newHead = head->next;
    newHead->prev = NULL;
    (*list)->head = newHead;
    free(head);
    (*list)->size--;

    return true;
}


bool list_pop_back(List **list){
    if(list == NULL){
        return false;
    }

    ListEntry* tail = (*list)->tail;
    ListEntry* newTail = tail->prev;
    newTail->next = NULL;
    (*list)->tail = newTail;
    free(tail);
    (*list)->size--;

    return true;
}


ListEntry *list_nth_entry(List *list, unsigned int n){
    if(list==NULL || n > list_size(list)){
        return NULL;
    }

    size_t i=1;
    ListEntry* itr = list->head;
    while (itr!=NULL)
    {
        if(i==n){
            break;
        }
        itr = itr->next;
        i++;
    }
    
    return itr;
}


ListValue list_data(ListEntry* entry){
    if(entry == NULL || entry->data == NULL){
        return NULL;
    }
    return entry->data;
}


ListValue list_nth_data(List *list, unsigned int n){
    return list ? list_data(list_nth_entry(list,n)) : NULL;
}


size_t list_size(List *list){
    return list ? list->size : 0;
}


bool list_empty(List *list){
    return list->size == 0;
}


void list_reverse(List ** list){
    List* newList = list_new();

    ListEntry* itr = (*list)->head;
    for(size_t i=0;i<list_size(*list);i++){
        list_push_front(&newList,itr->data);
        itr = itr->next;
    }
    list_free(*list);

    (*list) = newList;
}


void list_print(List *list, ListPrintData print){
    printf("{ ");
    ListEntry* itr = list->head;
    for(size_t i=0;i<list_size(list);i++){
        char * str;
        if(i==list_size(list)-1){
            str = " ";
        }
        else{
            str = ", ";
        }
        print(itr->data);
        printf("%s",str);
        itr = itr->next;
    }
    printf("}\n");
}


bool list_remove_data(List **list, ListEqualFunc callback,ListValue data){
    if(list==NULL){
        return false;
    }
     
    ListEntry* entry = (*list)->head;

    for(size_t i=0; i<list_size(*list); i++){
        if(callback(entry->data,data)){
            if(i==0){
                (*list)->head = entry->next;
                free(entry);
                (*list)->size--;
                return true; 
            }

            ListEntry* prev = entry->prev;
            ListEntry* next = entry->next;

            if(prev!=NULL){
                prev->next = next;
            }
            if(next!=NULL){
                next->prev = prev;
            }
            
            free(entry);
            (*list)->size--;
            break;
        }
        entry = entry->next;
    }
    return true;
}


bool list_remove_nth_entry(List** list, size_t n){
    if(list == NULL){
        return false;
    }
    ListEntry* entry = list_nth_entry(*list,n);

    if(entry == NULL){
        return false;
    }

    if(entry->prev == NULL){
        (*list)->head = entry->next;
        free(entry);
        (*list)->size--;
        return true; 
    }

    ListEntry* prev = entry->prev;
    ListEntry* next = entry->next;

    if(prev!=NULL){
        prev->next = next;
    }
    if(next!=NULL){
        next->prev = prev;
    }
    
    free(entry);
    (*list)->size--;
    return true;
}


/* Function used internally for sorting.  Returns the last entry in the
 * new sorted list */

static ListEntry *list_sort_internal(ListEntry **list, ListCompareFunc compare_func)
{
	ListEntry *pivot;
	ListEntry *rover;
	ListEntry *less_list, *more_list;
	ListEntry *less_list_end, *more_list_end;

	if (list == NULL || compare_func == NULL) {
		return NULL;
	}

	/* If there are less than two entries in this list, it is
	 * already sorted */

	if (*list == NULL || (*list)->next == NULL) {
		return *list;
	}

	/* The first entry is the pivot */

	pivot = *list;

	/* Iterate over the list, starting from the second entry.  Sort
	 * all entries into the less and more lists based on comparisons
	 * with the pivot */

	less_list = NULL;
	more_list = NULL;
	rover = (*list)->next;

	while (rover != NULL) {
		ListEntry *next = rover->next;

		if (compare_func(rover->data, pivot->data) < 0) {

			/* Place this in the less list */

			rover->prev = NULL;
			rover->next = less_list;
			if (less_list != NULL) {
				less_list->prev = rover;
			}
			less_list = rover;

		} else {

			/* Place this in the more list */

			rover->prev = NULL;
			rover->next = more_list;
			if (more_list != NULL) {
				more_list->prev = rover;
			}
			more_list = rover;
		}

		rover = next;
	}

	/* Sort the sublists recursively */

	less_list_end = list_sort_internal(&less_list, compare_func);
	more_list_end = list_sort_internal(&more_list, compare_func);

	/* Create the new list starting from the less list */

	*list = less_list;

	/* Append the pivot to the end of the less list.  If the less list
	 * was empty, start from the pivot */

	if (less_list == NULL) {
		pivot->prev = NULL;
		*list = pivot;
	} else {
		pivot->prev = less_list_end;
		less_list_end->next = pivot;
	}

	/* Append the more list after the pivot */

	pivot->next = more_list;
	if (more_list != NULL) {
		more_list->prev = pivot;
	}

	/* Work out what the last entry in the list is.  If the more list was
	 * empty, the pivot was the last entry.  Otherwise, the end of the
	 * more list is the end of the total list. */

	if (more_list == NULL) {
		return pivot;
	} else {
		return more_list_end;
	}
}


void list_sort(List **list, ListCompareFunc compare_func){
    ListEntry* tail = list_sort_internal(&((*list)->head),compare_func);
    (*list)->tail = tail;
    ListEntry* rev_itr = tail;
    while(rev_itr->prev!=NULL){
        rev_itr = rev_itr->prev;
    }
    (*list)->head = rev_itr;
}