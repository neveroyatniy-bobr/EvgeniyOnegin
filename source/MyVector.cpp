#include "MyVector.h"

#include <assert.h>

void MyVectorInit(MyVector* vector, size_t capacity) {
    assert(vector != NULL);
    assert(capacity != 0);

    vector->capacity = capacity >= MIN_CAPACITY ? capacity : MIN_CAPACITY;

    vector->size = 0;

    char** data = (char**)calloc(capacity, sizeof(char*));
    vector->data = data;
}

void MyVectorRealloc(MyVector* vector) {
    assert(vector != NULL);

    vector->data = (char**)realloc(vector->data, vector->capacity * GROW_FACTOR * sizeof(*(vector->data)));
    vector->capacity *= GROW_FACTOR;
}

void MyVectorFree(MyVector* vector) {
    assert(vector != NULL);

    free(vector->data);
    
    vector->capacity = 0;
    vector->size = 0;
    vector->data = NULL;
}

void MyVectorAdd(MyVector* vector, char* elem) {
    assert(vector != NULL);
    assert(elem != NULL);

    if (vector->size == vector->capacity) {
        MyVectorRealloc(vector);
    }

    vector->data[vector->size] = elem;
    vector->size++;
}