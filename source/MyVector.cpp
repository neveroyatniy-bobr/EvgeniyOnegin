#include "MyVector.h"

void MyVectorInit(MyVector* vector, size_t capacity) {
    vector->capacity = capacity >= MIN_CAPACITY ? capacity : MIN_CAPACITY;

    vector->size = 0;

    char** data = (char**)calloc(capacity, sizeof(char*));
    vector->data = data;
}

void MyVectorRealloc(MyVector* vector) {
    vector->data = (char**)realloc(vector->data, vector->capacity * GROW_FACTOR * sizeof(*(vector->data)));
    vector->capacity *= GROW_FACTOR;
}

void MyVectorFree(MyVector* vector) {
    free(vector->data);
    
    vector->capacity = 0;
    vector->size = 0;
    vector->data = NULL;
}

void MyVectorAdd(MyVector* vector, char* elem) {
    if (vector->size == vector->capacity) {
        MyVectorRealloc(vector);
    }

    vector->data[vector->size] = elem;
    vector->size++;
}