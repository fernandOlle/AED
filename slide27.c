#include <stdlib.h>

void *replace_realloc(void *pont, size_t newsize){
    void *new_ptr;

    new_ptr = (void*) malloc(sizeof(void)*newsize);
    new_ptr=  memcpy(new_ptr,pont,newsize);

    pont = new_ptr;
    return pont;
}

