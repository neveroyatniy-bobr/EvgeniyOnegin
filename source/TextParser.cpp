#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "MyStringFunctions.h"
#include "MyVector.h"

size_t TextParse(char*** text_ptr, const char* input_file_name) {
    assert(text_ptr != NULL);
    assert(input_file_name != NULL);

    FILE* input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s\n", input_file_name);
        return 0;
    }

    MyVector text_vec = {};
    MyVectorInit(&text_vec, 16);

    size_t m;
    char* line = NULL;

    while (MyGetLine(&line, &m, input_file) != 0 && line != NULL) {
        if (*line != '\0') {
            MyVectorAdd(&text_vec, line);
            line = NULL;
        }
    }

    *text_ptr = text_vec.data;

    free(line);

    fclose(input_file);

    return text_vec.size;
}

void MemoryFree(char** text, size_t len) {
    assert(text != NULL);
    assert(len != 0);

    for (size_t i = 0; i < len; i++) {
        free(text[i]);
    }

    free(text);
}