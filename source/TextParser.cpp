#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>

#include "MyStringFunctions.h"

size_t TextParse(char*** text, const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Не удалось открыть файл: %s\n", filename);
        return 0;
    }

    size_t n = 16;
    *text = (char**)calloc(n, sizeof(*text[0]));

    size_t m;
    char* line = NULL;

    size_t cnt = 0;
    while (MyGetLine(&line, &m, file) != 0 && line != NULL) {
        if (*line != '\0') {
            (*text)[cnt] = line;
            cnt++;

            line = NULL;
        }

        if (cnt == n) {
            n *= 2;
            *text = (char**)realloc(*text, n * sizeof(*text[0]));
        }
    }

    free(line);

    fclose(file);

    return cnt;
}