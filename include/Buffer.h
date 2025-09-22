#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdlib.h>

struct Buffer {
    size_t capacity;
    size_t size;
    char* data;
};

void BufferInit(Buffer* buffer, size_t capacity);

void BufferAdd(Buffer* buffer, char elem);

void BufferClear(Buffer* buffer);

void BufferMemoryFree(Buffer buffer);

bool BufferIsFull(Buffer buffer);

#endif // BUFFER_H_