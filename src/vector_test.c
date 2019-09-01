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
    
    vector_free(myvector);
    return 0;
}