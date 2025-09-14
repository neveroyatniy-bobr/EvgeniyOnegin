#include "FileOutput.h"

#include <stdio.h>
#include <assert.h>

int FileOutput(const char* output_file_name, char** text, size_t len) {
    assert(output_file_name != NULL);
    assert(text != NULL);
    assert(len != 0);

    FILE* output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Не удалось открыть файл: %s\n", output_file_name);
        return 0;
    }

    for (size_t i = 0; i < len; i++) {
        if (text[i] != NULL) {
            fprintf(output_file, "%s\n", text[i]);
        }
    }

    fclose(output_file);

    return 0;
}