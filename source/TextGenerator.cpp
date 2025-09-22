#include "TextGenerator.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include "Settings.h"
#include "Buffer.h"

int GenerateText(Settings settings) {
    srand((unsigned int)time(NULL));

    FILE* generated_file = fopen("data/generated_text.txt", "w");
    if (generated_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s. %s\n", settings.output_file_name, strerror(errno));
        return 0;
    }

    Buffer buffer = {};
    BufferInit(&buffer, AVALIABLE_MEMORY_SIZE);

    for (size_t line_count = 0; line_count < settings.generate_text_size; line_count++) {
        for (size_t i = 0; i < LINE_SIZE; i++) {
            char symbol = (char)('A' + rand() % ('z' - 'A' + 1));
            
            SymbolToFile(symbol, generated_file, &buffer);
        }
        SymbolToFile('\n', generated_file, &buffer);
    }

    fwrite(buffer.data, 1, buffer.size, generated_file);

    BufferMemoryFree(buffer);

    fclose(generated_file);

    return 0;
}

void SymbolToFile(char symbol, FILE* file, Buffer* buffer) {
    BufferAdd(buffer, symbol);

    if (BufferIsFull(*buffer)) {
        fwrite(buffer->data, 1, buffer->size, file);

        BufferClear(buffer);
    }
} 