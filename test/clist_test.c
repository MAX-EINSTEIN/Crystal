#include <stdio.h>
#include "../include/clist.h"

void print_int(CListValue data){
    printf("%d ",*((int*)data));
}


int main(){
    printf("\nTESTING List\n");

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    CList *list = clist_new();
    if (list == NULL){
        return 1;
    }

    if (clist_empty(list)){
        printf("The list is empty.\n");
    }else{
        printf("List: ");
        clist_traverse(list, print_int); printf("\n");
        printf("List size : %ld\n", clist_size(list)-1);
    }

    printf("\nTESTING list_push_front and list_push_back\n");
    {
        clist_push_front(list, &a[0]); 
        clist_push_front(list, &a[1]); 

        if (clist_empty(list)){
            printf("The list is empty.\n");
        }else{
            printf("List: ");
            clist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", clist_size(list)-1);
        }

        clist_push_front(list, &a[2]); 
        clist_push_front(list, &a[3]); 
        clist_push_back(list, &a[4]);  
        clist_push_back(list, &a[5]);  
        clist_push_front(list,&a[6]);  
        clist_push_back(list,&a[7]);   

        if (clist_empty(list)){
            printf("The list is empty.\n");
        }else{
            printf("List: ");
            clist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", clist_size(list)-1);
        }
    }


    printf("\nTESTING list_pop_front and list_pop_back\n");
    {
        clist_pop_front(list);  
        clist_pop_back(list);   
        clist_pop_front(list);
        clist_pop_back(list);  

        if (clist_empty(list)){
            printf("The list is empty.\n");
        }else{
            printf("List: ");
            clist_traverse(list, print_int); printf("\n");
            printf("List size : %ld\n", clist_size(list)-1);
        }
    }


    clist_free(list);

    return 0;
}