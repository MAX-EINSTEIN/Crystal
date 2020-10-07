#include <stdio.h>
#include "../include/slist.h"

void print_int(SListValue data){
    printf("%d ",*((int*)data));
}


int main(){
    printf("\nTESTING List\n");

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SList *list = slist_new();
    if (list == NULL){
        return 1;
    }

    if (slist_empty(list)){
        printf("The list is empty.\n");
    }else{
        printf("List: ");
        slist_traverse(list, print_int); printf("\n");
        printf("List size : %ld\n", slist_size(list));
    }

    printf("\nTESTING list_push_front and list_push_back\n");
    {
        slist_push_front(list, &a[0]); // 1
        slist_push_front(list, &a[1]); // 2 1

        if (slist_empty(list)){
        printf("The list is empty.\n");
        }else{
            printf("List: ");
            slist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", slist_size(list));
        }

        slist_push_front(list, &a[2]); // 3 2 1
        slist_push_front(list, &a[3]); // 4 3 2 1
        slist_push_back(list, &a[4]);  // 4 3 2 1 5
        slist_push_back(list, &a[5]);  // 4 3 2 1 5 6
        slist_push_front(list,&a[6]);  // 7 4 3 2 1 5 6
        slist_push_back(list,&a[7]);   // 7 4 3 2 1 5 6 8

        if (slist_empty(list)){
        printf("The list is empty.\n");
        }else{
            printf("List: ");
            slist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", slist_size(list));
        }
    }


    printf("\nTESTING list_pop_front and list_pop_back\n");
    {
        slist_pop_front(list);  // 4 3 2 1 5 6 8
        slist_pop_back(list);   // 4 3 2 1 5 6
        slist_pop_front(list);  // 3 2 1 5 6 
        slist_pop_back(list);   // 3 2 1 5 

        if (slist_empty(list)){
        printf("The list is empty.\n");
        }else{
            printf("List: ");
            slist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", slist_size(list));
        }
    }


    printf("\nTESTING slist_insert_at & slist_remove_at\n");
    {
        slist_insert_at(list, &a[9], 0); // 10 3 2 1 5
        slist_insert_at(list, &a[9], 3); // 10 3 2 1 5 10
        slist_insert_at(list, &a[9], slist_size(list)); // 10 3 2 10 1 5 10

        if (slist_empty(list)){
        printf("The list is empty.\n");
        }else{
            printf("List: ");
            slist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", slist_size(list));
        }

        slist_remove_at(list, 0);
        slist_remove_at(list, 3);
        slist_remove_at(list, slist_size(list)-1);

        printf("List: ");
        slist_traverse(list, print_int);  printf("\n");
        printf("List size : %ld\n", slist_size(list));
    }

    slist_free(list);

    return 0;
}