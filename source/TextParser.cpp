#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "MyVector.h"
#include "Text.h"
#include "Settings.h"

void TextParse(Text* text, Settings settings) {
    assert(text != NULL);
    assert(settings.input_file_name != NULL);

    // FIXME Использовать read() а не fread()

    /*
    int fd = open(input_file_name, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Не удалось открыть файл: %s. ", input_file_name);
        perror(NULL);
        return;
    }

    char* text_buffer = (char*)calloc(file_size + 1, 1);
    text_buffer_start_ptr = text_buffer;
    
    ssize_t true_file_size = read(fd, text_buffer, file_size);
    text_buffer[true_file_size] = '\0';

    close(fd);
    */

    FILE* input_file = fopen(settings.input_file_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s. %s\n", settings.input_file_name, strerror(errno));
        return;
    }

    
    size_t file_size = FileSize(input_file);
    char* text_buffer = (char*)calloc(file_size + 1, 1);
    text->buffer_start_ptr = text_buffer;
    
    size_t true_file_size = fread(text_buffer, 1, file_size, input_file);
    text_buffer[true_file_size] = '\0';
    
    fclose(input_file);
        
    MyVector text_vec = {};
    MyVectorInit(&text_vec, 16);
    
    char* current_line_ptr = text_buffer;
    char* next_line_ptr = text_buffer;

    while (next_line_ptr != 0 && *(next_line_ptr) != '\0') {
        current_line_ptr = next_line_ptr;
        next_line_ptr = strchr(current_line_ptr, '\n') + 1;

        if (current_line_ptr != text_buffer) {
            *(next_line_ptr - 1) = '\0';
        }

        Line current_line = { .data = current_line_ptr, .size = (size_t)(next_line_ptr - current_line_ptr - 1) };
        
        if (current_line.size > 0) {
            MyVectorAdd(&text_vec, current_line);
        }
    }

    text->data = text_vec.data;

    text->size = text_vec.size;


}

void MemoryFree(Text text) {
    assert(text.data != NULL);
    assert(text.size != 0);

    free(text.buffer_start_ptr);

    free(text.data);
}

size_t FileSize(FILE* file) {
    struct stat stats = {};

    if (fstat(fileno(file), &stats) != 0) {
        fprintf(stderr, "Не удалось прочитать статистику файла. %s\n", strerror(errno));
        return 0;
    }

    return (size_t)stats.st_size;
}