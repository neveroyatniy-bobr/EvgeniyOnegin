#ifndef TEST_H_ 
#define TEST_H_

#include <stdlib.h>

struct Line
{
    char* data;
    size_t size;
};

struct Text {
    Line* data;
    size_t size;
};

#endif // TEST_H_