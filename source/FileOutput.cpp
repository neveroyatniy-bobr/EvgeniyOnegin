#include "FileOutput.h"

#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "Text.h"
#include "Settings.h"

int FileOutput(Text text, Settings settings) {
    assert(settings.output_file_name != NULL);
    assert(text.data != NULL);
    assert(text.size != 0);

    FILE* output_file = fopen(settings.output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s. %s\n", settings.output_file_name, strerror(errno));
        return 0;
    }

    for (size_t i = 0; i < text.size; i++) {
        if (text.data[i].data != NULL) {
            fprintf(output_file, "%s\n", text.data[i].data);
        }
    }

    fclose(output_file);

    return 0;
}