#ifndef TEST_H_ 
#define TEST_H_

#include <stdlib.h>

/// @brief Хранит линию из текста
struct Line
{
    char* data;
    size_t size;
};

/// @brief Хранит текст
struct Text {
    Line* data;
    size_t size;
    char* buffer_start_ptr;
};

#endif // TEST_H_