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
#include <stdbool.h>

#include "../include/list.h"

/* Entry of a Doubly Linked List */
struct _ListEntry {
	ListValue data;
	ListEntry *prev;
	ListEntry *next;
};

/* Iterator of a Double Linked List */
struct _ListIterator{
    ListEntry * entry;
    bool has_next;
};

/* Reverse Iterator of a Doubly linked list */
struct _ListReverseIterator{
    ListEntry * entry;
    bool has_prev;
};

/* Internal Represnatation of a list */
struct _ListInternal{
    ListEntry * head;
    ListEntry * tail;
    size_t size;
};

/* Doubly Linked List */
struct _List
{
    struct _ListInternal* _impl; 
};


List* list_new(){
    List * new_list = (List*) malloc(sizeof(List));
    if(new_list == NULL){
        return NULL;
    }
    new_list->_impl = (struct _ListInternal*) malloc(sizeof(struct _ListInternal));
    if(new_list->_impl == NULL){
        return NULL;
    }
    new_list->_impl->head = NULL;
    new_list->_impl->tail = NULL;
    new_list->_impl->size = 0;
    return new_list;
}


void list_free(List *list){
    if(list == NULL){
        return;
    }
    ListEntry* iterator = list->_impl->head;
    while(iterator!=NULL){
        ListEntry* next = iterator->next;
        free(iterator);
        iterator = NULL;
        iterator = next;
    } 
    if(list->_impl == NULL){
        return;
    }
    free(list->_impl);
    if(list == NULL){
        return;
    }
    free(list);
}


bool list_push_front(List *list, ListValue data){
    if(list == NULL){
        return false;
    }
    ListEntry * newEntry = (ListEntry*) malloc(sizeof(ListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;

    if(list->_impl->head != NULL){
        list->_impl->head->prev = newEntry;
    }

    newEntry->prev = NULL;
    newEntry->next = list->_impl->head;
    list->_impl->head = newEntry;

    if(list->_impl->tail == NULL){
        list->_impl->tail = newEntry;
    }

    list->_impl->size++;
    return true;
}


bool list_push_back(List *list, ListValue data){
    if(list == NULL){
        return false;
    }
    ListEntry * newEntry = (ListEntry*) malloc(sizeof(ListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;
    newEntry->next = NULL;

    if(list->_impl->tail!=NULL){
        list->_impl->tail->next = newEntry;
    }

    newEntry->prev = list->_impl->tail;
    list->_impl->tail = newEntry;

    if(list->_impl->head == NULL){
        list->_impl->head = newEntry;
    }

    list->_impl->size++;
    return true;
}


bool list_pop_front(List *list){
    if(list == NULL){
        return false;
    }

    ListEntry* head = list->_impl->head;
    ListEntry* newHead = head->next;
    newHead->prev = NULL;
    list->_impl->head = newHead;
    free(head);
    list->_impl->size--;

    return true;
}


bool list_pop_back(List *list){
    if(list == NULL){
        return false;
    }

    ListEntry* tail = list->_impl->tail;
    ListEntry* newTail = tail->prev;
    newTail->next = NULL;
    list->_impl->tail = newTail;
    free(tail);
    list->_impl->size--;

    return true;
}


ListEntry *list_nth_entry(List *list, unsigned int n){
    if(list==NULL || n > list_size(list)){
        return NULL;
    }

    size_t i=1;
    ListEntry* itr = list->_impl->head;
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
    return list ? list->_impl->size : 0;
}


bool list_empty(List *list){
    return list->_impl->size == 0;
}


void list_print(List *list, ListPrintData print){
    printf("{ ");
    ListEntry* itr = list->_impl->head;
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


bool list_remove_data(List *list, ListEqualFunc callback,ListValue data){
    if(list==NULL){
        return false;
    }
     
    ListEntry* entry = list->_impl->head;

    for(size_t i=0; i<list_size(list); i++){
        if(callback(entry->data,data)){
            if(i==0){
                list->_impl->head = entry->next;
                free(entry);
                list->_impl->size--;
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
            list->_impl->size--;
            break;
        }
        entry = entry->next;
    }
    return true;
}


bool list_remove_nth_entry(List* list, size_t n){
    if(list == NULL){
        return false;
    }
    ListEntry* entry = list_nth_entry(list,n);

    if(entry == NULL){
        return false;
    }

    if(entry->prev == NULL){
        list->_impl->head = entry->next;
        free(entry);
        list->_impl->size--;
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
    list->_impl->size--;
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

	if (*list == NULL || (*list)->next == NULL) {
		return *list;
	}

	pivot = *list;

	less_list = NULL;
	more_list = NULL;
	rover = (*list)->next;

	while (rover != NULL) {
		ListEntry *next = rover->next;

		if (compare_func(rover->data, pivot->data) < 0) {

			rover->prev = NULL;
			rover->next = less_list;
			if (less_list != NULL) {
				less_list->prev = rover;
			}
			less_list = rover;

		} else {

			rover->prev = NULL;
			rover->next = more_list;
			if (more_list != NULL) {
				more_list->prev = rover;
			}
			more_list = rover;
		}

		rover = next;
	}

	less_list_end = list_sort_internal(&less_list, compare_func);
	more_list_end = list_sort_internal(&more_list, compare_func);

	*list = less_list;

	if (less_list == NULL) {
		pivot->prev = NULL;
		*list = pivot;
	} else {
		pivot->prev = less_list_end;
		less_list_end->next = pivot;
	}

	pivot->next = more_list;
	if (more_list != NULL) {
		more_list->prev = pivot;
	}

	if (more_list == NULL) {
		return pivot;
	} else {
		return more_list_end;
	}
}


void list_sort(List *list, ListCompareFunc compare_func){
    ListEntry* tail = list_sort_internal(&(list->_impl->head),compare_func);
    list->_impl->tail = tail;
    ListEntry* rev_itr = tail;
    while(rev_itr->prev!=NULL){
        rev_itr = rev_itr->prev;
    }
    list->_impl->head = rev_itr;
}


ListIterator*  list_begin(List *list){
    if(list == NULL) return NULL;

    ListIterator*  begin = (ListIterator*) malloc(sizeof(ListIterator));
    begin->entry = list->_impl->head;
    begin->has_next = (list->_impl->head->next!=NULL)?true:false;
    return begin;
}


ListIterator*  list_end(List *list){
    if(list == NULL) return NULL;

    ListIterator* end = (ListIterator*) malloc(sizeof(ListIterator));
    end->entry = list->_impl->tail;
    end->has_next = NULL;
    return end;
}


ListReverseIterator*  list_rbegin(List *list){
    if(list == NULL) return NULL;

    ListReverseIterator* rbegin = (ListReverseIterator*) malloc(sizeof(ListReverseIterator));
    rbegin->entry = list->_impl->tail;
    rbegin->has_prev = (list->_impl->tail->prev == NULL)?false:true;
    return rbegin;
}


ListReverseIterator*  list_rend(List *list){
    if(list == NULL) return NULL;

    ListReverseIterator* rend = (ListReverseIterator*) malloc(sizeof(ListReverseIterator));
    rend->entry = list->_impl->head;
    rend->has_prev = false;
    return rend;
}


ListIterator * list_iter_new(ListEntry * entry){
    if(entry == NULL) return NULL;

    ListIterator * new_iter = (ListIterator*) malloc(sizeof(ListIterator));
    new_iter->entry = entry;
    new_iter->has_next = (entry->next != NULL)?true:false;
    return new_iter;
}


void list_iter_free(ListIterator * itr){
    free(itr);
}


ListIterator*  list_iter_next(ListIterator * itr){
    if(itr == NULL) return NULL;
    return list_iter_new(itr->entry->next);
}


ListReverseIterator * list_rev_iter_new(ListEntry * entry){
    if(entry == NULL) return NULL;

    ListReverseIterator * new_rev_iter = (ListReverseIterator*) malloc(sizeof(ListReverseIterator));
    new_rev_iter->entry = entry;
    new_rev_iter->has_prev = (entry->prev != NULL)?true:false;
    return new_rev_iter;
}


void list_rev_iter_free(ListReverseIterator * itr){
    free(itr);
}


ListReverseIterator * list_rev_iter_prev(ListIterator * itr){
    if(itr == NULL) return NULL;
    return list_rev_iter_new(itr->entry->prev);
}