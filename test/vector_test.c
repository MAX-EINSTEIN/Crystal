#include "../include/vector.h"
#include <stdio.h>

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Vector* myvector = vector_new(16);
    printf("TESTING vector_size and vector_capacity\n");
    {
        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector));
    }

    printf("TESTING vector_push_back and vector_push_front\n");
    {
        vector_push_front(myvector, &a[0]);
        vector_push_front(myvector, &a[1]);
        vector_push_front(myvector, &a[2]);
        vector_push_front(myvector, &a[3]);

        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector));

        vector_push_back(myvector, &a[4]);
        vector_push_back(myvector, &a[5]);
        vector_push_back(myvector, &a[6]);
        vector_push_back(myvector, &a[7]);
        vector_push_back(myvector, &a[4]);
        vector_push_back(myvector, &a[5]);
        vector_push_back(myvector, &a[6]);
        vector_push_back(myvector, &a[7]);
        vector_push_back(myvector, &a[4]);
        vector_push_back(myvector, &a[5]);
        vector_push_back(myvector, &a[6]);
        vector_push_back(myvector, &a[7]);
        vector_push_back(myvector, &a[4]);
        vector_push_back(myvector, &a[5]);
        vector_push_back(myvector, &a[6]);
        vector_push_back(myvector, &a[7]);

        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector));
    }

    printf("TESTING vector_at, vector_insert and vector_erase\n");
    {
        vector_insert(myvector,&a[8],2);
        int a = *((int*)vector_at(myvector,2));
        printf("Value at index 2 : %d\n",a);
        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector));
        vector_erase(myvector,2);
        a = *((int*)vector_at(myvector,2));
        printf("Value at index 2 : %d\n",a);
        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector));        
    }

    printf("TESTING vector_pop_back, vector_pop_front, vector_front and vector_back\n");
    {
        vector_pop_front(myvector);
        int a = *((int*)vector_front(myvector));
        printf("Value at front : %d\n", a);
        vector_pop_back(myvector);
        a = *((int*)vector_back(myvector));
        printf("Value at back : %d\n", a);

        printf("Vector size = %ld\n", vector_size(myvector));
        printf("Vector capacity = %ld\n", vector_capacity(myvector)); 
    }

    printf("Testing iteration over a vector\n");
    {
        printf("Vector: { ");
        for(int i=0; i<vector_size(myvector); i++){
            int a = static_cast(int,vector_at(myvector,i));
            if(i!=vector_size(myvector)-1)
                printf("%d, ", a);
            else 
                printf("%d ", a);
        }
        printf("}\n");
    }
    
    vector_free(myvector);
    return 0;
}