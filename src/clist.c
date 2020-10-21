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

#include "../include/clist.h"
#include <stdlib.h>


struct _CListEntry{
    CListValue data;
    CListEntry *next;
};


struct _CListInternal{
    CListEntry *head, *tail;
    size_t size;
};


struct _CList{
    struct _CListInternal* _impl;
};


CList* clist_new(){
    CList* list = (CList*) malloc(sizeof(CList));
    if(list == NULL) return NULL;

    list->_impl = (struct _CListInternal*) malloc(sizeof(struct _CListInternal));
    if(list->_impl == NULL){
        free(list);
        return NULL;
    } 

    list->_impl->head = list->_impl->tail = NULL;
    list->_impl->size = 0;

    return list;
}


void clist_free(CList* list){
    if(list == NULL) return;
    if(list->_impl == NULL) return;
    
    CListEntry* iterator = list->_impl->head;
    while(iterator->next != list->_impl->head){
        CListEntry* temp = iterator;
        iterator = iterator->next;
        free(temp);
    }
    if(iterator) free(iterator);
    free(list->_impl);
    free(list);
}


size_t clist_size(CList *list){
    return (list->_impl->size); 
}


bool clist_empty(CList * list){
    return clist_size(list) == 0;
}


bool clist_push_front(CList *list, CListValue data){
    if(list == NULL || list->_impl == NULL){
        return false;
    }

    CListEntry * newEntry = (CListEntry*) malloc(sizeof(CListEntry));
    if(newEntry == NULL){
        return false;
    }
    newEntry->data = data;
    newEntry->next = list->_impl->head;
    list->_impl->head = newEntry;

    if(list->_impl->head->next == NULL) list->_impl->tail = list->_impl->head;
    list->_impl->tail->next = list->_impl->head;

    list->_impl->size += 1;
    return true;  
}


bool clist_push_back(CList *list, CListValue data){
    if(list == NULL || list->_impl == NULL){
        return false;
    }
    
    if(list->_impl->head == NULL){
        clist_push_front(list, data);
        return true;
    }

    CListEntry * newEntry = (CListEntry*) malloc(sizeof(CListEntry));
    if(newEntry == NULL){
        return false;
    }
    newEntry->data = data;
    newEntry->next = list->_impl->head;
    list->_impl->tail->next = newEntry;
    list->_impl->tail = newEntry;

    list->_impl->size += 1;

    return true;
}


bool clist_pop_front(CList* list){
    if(list == NULL || list->_impl == NULL){
        return false;
    }

    CListEntry* head = list->_impl->head;
    if(head == NULL){
        list->_impl->tail = NULL;
        return false;
    }

    if(head == list->_impl->tail){
        list->_impl->head = list->_impl->tail = NULL;
    }else{
        list->_impl->tail->next = head->next;
        list->_impl->head = head->next;
    }

    list->_impl->size -= 1;

    if(head != NULL) free(head);

    return true;
}


bool clist_pop_back(CList* list){
    if(list == NULL || list->_impl == NULL){
        return false;
    }

    CListEntry* iterator = list->_impl->head;
    if(iterator == NULL){
        list->_impl->tail = NULL;
        return false;
    }

    while(iterator->next != list->_impl->tail) iterator = iterator->next;
    free(iterator->next);
    iterator->next = list->_impl->head;
    list->_impl->tail = iterator;

    list->_impl->size -= 1;

    return true;
}


void clist_traverse(CList* list, CListValueOperation operation){
    if(list == NULL || list->_impl == NULL) return;

    CListEntry* iterator = list->_impl->head;
    while (iterator->next != list->_impl->head){
        operation(iterator->data);
        iterator = iterator->next;
    }
}