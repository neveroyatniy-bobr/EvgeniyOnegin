#include "Buffer.h"

#include <stdlib.h>
#include <assert.h>

void BufferInit(Buffer* buffer, size_t capacity) {
    assert(buffer != NULL);
    assert(capacity != 0);

    buffer->capacity = capacity;
    buffer->data = (char*)calloc(capacity, 1);
    buffer->size = 0;
}

void BufferAdd(Buffer* buffer, char elem) {
    assert(buffer != NULL);

    buffer->data[buffer->size] = elem;
    buffer->size++;
}

void BufferClear(Buffer* buffer) {
    assert(buffer != NULL);

    buffer->size = 0;
}

void BufferMemoryFree(Buffer buffer) {
    free(buffer.data);
}

bool BufferIsFull(Buffer buffer) {
    return buffer.size == buffer.capacity;
}