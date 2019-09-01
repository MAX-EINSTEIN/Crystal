#include <stdio.h>
#include "../include/list.h"

void print_int(ListValue data){
    printf("%d",*((int*)data));
}

bool equals_int(ListValue data1,ListValue data2){
    return ((int*)data1) == ((int*)data2);
}

int compares_int(ListValue data1, ListValue data2){
    int int1 = *((int*)data1);
    int int2 = *((int*)data2);
    return int1>=int2? (int1==int2?0:1): -1;
}

int main()
{

    printf("\nTESTING List\n");

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    List *list = list_new();
    if (list == NULL)
    {
        return 1;
    }

    if (list_empty(list))
    {
        printf("The list is empty.\n");
    }

    printf("List: ");
    list_print(list,print_int);
    printf("List size : %ld\n", list_size(list));

    printf("\nTESTING list_push_front and list_push_back\n");
    {
        list_push_front(&list, a);
        list_push_front(&list, &a[1]);

        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));

        if (list_empty(list))
        {
            printf("The list is empty.\n");
        }

        list_push_front(&list, &a[2]);
        list_push_front(&list, &a[3]);
        list_push_back(&list, &a[4]);
        list_push_back(&list, &a[5]);
        list_push_front(&list,&a[6]);
        list_push_back(&list,&a[7]);

        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));
    }


    printf("\nTESTING list_pop_front and list_pop_back\n");
    {
        list_pop_front(&list);
        list_pop_back(&list);

        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));
    }

    
    printf("\nTESTING list_sort\n");
    {
        list_sort(&list,compares_int);
        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));
    }


    printf("\nTESTING list_reverse\n");
    {
        list_reverse(&list);
        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));

        printf("Reverse Again.\nList: ");
        list_reverse(&list);
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));
    }


    printf("\nTESTING list_nth_entry and list_nth data\n");
    {
        ListEntry *entry1 = list_nth_entry(list, 1);
        if (entry1 != NULL)
        {
            int data1 = *((int *)list_data(entry1));
            printf("Entry at position 1: %d\n", data1);
        }

        ListEntry *entry2 = list_nth_entry(list, 2);
        if (entry2 != NULL)
        {
            int data2 = *((int *)list_data(entry2));
            printf("Entry at position 2: %d\n", data2);
        }

        ListEntry *entry3 = list_nth_entry(list, 3);
        if (entry3 != NULL)
        {
            int data3 = *((int *)list_data(entry3));
            printf("Entry at position 3: %d\n", data3);
        }

        int data4 = *((int*)list_nth_data(list,4));
        printf("Data at positon 4: %d\n",data4);

        int data5 = *((int*)list_nth_data(list,5));
        printf("Data at positon 5: %d\n",data5);

        int data6 = *((int*)list_nth_data(list,6));
        printf("Data at positon 6: %d\n",data6);
    }

    printf("\nTESTING list_remove_nth entry && list_remove_data\n");
    {
        list_remove_nth_entry(&list,1);        
        list_remove_nth_entry(&list,3);
        list_remove_nth_entry(&list,4);

        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));

        list_remove_data(&list,equals_int,&a[1]);
        list_remove_data(&list,equals_int,&a[2]);
        list_remove_data(&list,equals_int,&a[4]);

        printf("List: ");
        list_print(list,print_int);
        printf("List size : %ld\n", list_size(list));
    }

    list_free(list);

    return 0;
}