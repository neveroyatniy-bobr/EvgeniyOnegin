#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>

#include "Text.h"

static const size_t MIN_CAPACITY = 16;
static const size_t GROW_FACTOR = 2;

struct MyVector {
    size_t capacity;
    size_t size;
    Line* data;
};

void MyVectorInit(MyVector* vector, size_t capacity);

void MyVectorRealloc(MyVector* vector);

void MyVectorFree(MyVector* vector);

void MyVectorAdd(MyVector* vector, Line elem);

#endif // VECTOR_H_