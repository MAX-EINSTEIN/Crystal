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

#include <stdlib.h>
#include "../include/slist.h"


/* A singly-linked list entry*/
struct _SListEntry {
	SListValue data;
	SListEntry *next;
};


struct _SListInternal{
    SListEntry * head;
    size_t size;
};


struct _SList{
    struct _SListInternal* _impl;
};


SList* slist_new(){
    SList* list = (SList*) malloc(sizeof(SList));

    if(list == NULL){
        return NULL;
    }

    list->_impl = (struct _SListInternal *) malloc(sizeof(struct _SListInternal));
    list->_impl->head = NULL;
    list->_impl->size = 0;

    return list;
}


void slist_free(SList *list){
    if(list == NULL) return;
    if(list->_impl == NULL) return;

    SListEntry* iterator = list->_impl->head;
    while(iterator!=NULL){
        SListEntry* next = iterator->next;
        free(iterator);
        iterator = next;
    } 

    free(list->_impl);
    free(list);
}


size_t slist_size(SList* list){
    return list->_impl->size;
}


bool slist_empty(SList* list){
    return slist_size(list) == 0;
}


bool slist_push_front(SList* list, SListValue data){
    if(list == NULL){
        return false;
    }

    SListEntry * newEntry = (SListEntry*) malloc(sizeof(SListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;
    newEntry->next = list->_impl->head;

    if(list->_impl->head != NULL){
        list->_impl->head = newEntry;
    }

    list->_impl->size++;
    return true;
}


bool slist_push_back(SList* list, SListValue data){
    if(list == NULL){
        return false;
    }
    SListEntry * newEntry = (SListEntry*) malloc(sizeof(SListEntry));
    if(newEntry == NULL){
        return false;
    }

    newEntry->data = data;
    newEntry->next = NULL;

    if(list->_impl->head == NULL){
        list->_impl->head = newEntry;
    }else{
        SListEntry* iterator = list->_impl->head;
        while (iterator->next != NULL){
            iterator = iterator->next;
        }
        iterator->next = newEntry;
    }

    list->_impl->size++;
    return true;
}


bool slist_insert_at(SList* list, SListValue data, size_t n){
    if(n > slist_size(list)) return false;

    SListEntry * newEntry = (SListEntry*) malloc(sizeof(SListEntry));
    if(newEntry == NULL){
        return false;
    }
    newEntry->data = data;

    int pos = 0;
    SListEntry* iterator = list->_impl->head;
    while(pos < n-1){
        iterator = iterator->next;
        ++pos;
    } 
    SListEntry* next_to_nth_node = iterator->next;
    iterator->next = newEntry;
    newEntry->next = next_to_nth_node;

    list->_impl->size++;
    return true;
}


bool slist_pop_front(SList *list){
    if(list == NULL || list->_impl->head == NULL){
        return false;
    }

    SListEntry * ptr = list->_impl->head;
    list->_impl->head = ptr->next;
    free(ptr);

    list->_impl->size--;
    return true;
}


bool slist_pop_back(SList *list){
    if(list == NULL){
        return false;
    }else if(list->_impl->head->next == NULL){
        slist_pop_front(list);
        return true;
    }

    SListEntry* iterator = list->_impl->head;
    while(iterator->next->next != NULL){
        iterator = iterator->next;
    }

    SListEntry* tail = iterator->next;
    iterator->next = NULL;
    free(tail);

    list->_impl->size--;
    return true;
}


bool slist_remove_at(SList* list, size_t n){
    if(n > slist_size(list)) return false;

    int pos = 0;
    SListEntry* iterator = list->_impl->head;
    while(pos < n-1){
        iterator = iterator->next;
        ++pos;
    } 
    SListEntry* nth_node = iterator->next;
    iterator->next = NULL;
    free(nth_node);

    list->_impl->size--;
    return true;
}


SListValue slist_value_at(SList* list, size_t n){
    if(n > slist_size(list)) return false;

    int pos = 0;
    SListEntry* iterator = list->_impl->head;
    while(pos < n-1){
        iterator = iterator->next;
        ++pos;
    } 

    return iterator->data;
}


void slist_traverse(SList* list, SListValueOperation operation){
    SListEntry* iterator = list->_impl->head;
    while (iterator != NULL){
        operation(iterator->data);
        iterator = iterator->next;
    }
}