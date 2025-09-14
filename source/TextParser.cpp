#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "MyStringFunctions.h"

size_t TextParse(char*** text_ptr, const char* input_file_name) {
    assert(text_ptr != NULL);
    assert(input_file_name != NULL);

    FILE* input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s\n", input_file_name);
        return 0;
    }

    size_t n = 16;
    *text_ptr = (char**)calloc(n, sizeof(*text_ptr[0]));

    size_t m;
    char* line = NULL;

    size_t cnt = 0;
    while (MyGetLine(&line, &m, input_file) != 0 && line != NULL) {
        if (*line != '\0') {
            (*text_ptr)[cnt] = line;
            cnt++;

            line = NULL;
        }

        if (cnt == n) {
            n *= 2;
            *text_ptr = (char**)realloc(*text_ptr, n * sizeof(*text_ptr[0]));
        }
    }

    free(line);

    fclose(input_file);

    return cnt;
}

void MemoryFree(char** text, size_t len) {
    assert(text != NULL);
    assert(len != 0);

    for (size_t i = 0; i < len; i++) {
        assert(text[i] != 0);
        free(text[i]);
    }

    free(text);
}