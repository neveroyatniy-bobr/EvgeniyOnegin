#include "MyVector.h"

#include <assert.h>
#include <stdio.h>

void MyVectorInit(MyVector* vector, size_t capacity) {
    assert(vector != NULL);

    vector->capacity = capacity >= MIN_CAPACITY ? capacity : MIN_CAPACITY;

    vector->size = 0;

    vector->data = (Line*)calloc(capacity, sizeof(Line));
}

void MyVectorRealloc(MyVector* vector) {
    assert(vector != NULL);

    Line* data = (Line*)realloc(vector->data, vector->capacity * GROW_FACTOR * sizeof(*(vector->data)));
    if (data != NULL) {
        vector->data = data;
    }

    vector->capacity *= GROW_FACTOR;
}

void MyVectorFree(MyVector* vector) {
    assert(vector != NULL);

    free(vector->data);
    
    vector->capacity = 0;
    vector->size = 0;
    vector->data = NULL;
}

void MyVectorAdd(MyVector* vector, Line elem) {
    assert(vector != NULL);

    if (vector->size == vector->capacity) {
        MyVectorRealloc(vector);
    }

    vector->data[vector->size] = elem;
    vector->size++;
}