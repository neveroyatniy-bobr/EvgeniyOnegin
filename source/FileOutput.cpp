#include "FileOutput.h"

#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "Text.h"

int FileOutput(const char* output_file_name, Text text) {
    assert(output_file_name != NULL);
    assert(text.data != NULL);
    assert(text.size != 0);

    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s. ", output_file_name);
        perror(NULL);
        return 0;
    }

    for (size_t i = 0; i < text.size; i++) {
        if (text.data[i] != NULL) {
            fprintf(output_file, "%s\n", text.data[i]);
        }
    }

    fclose(output_file);

    return 0;
}