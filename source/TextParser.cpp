#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "MyStringFunctions.h"
#include "MyVector.h"
#include "Text.h"

// FIXME Узнать как номально сделать
char* text_buffer_start_ptr = NULL;

void TextParse(Text* text, const char* input_file_name) {
    assert(text != NULL);
    assert(input_file_name != NULL);

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

    FILE* input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s. ", input_file_name);
        perror(NULL);
        return;
    }

    
    size_t file_size = FileSize(input_file);
    char* text_buffer = (char*)calloc(file_size + 1, 1);
    text_buffer_start_ptr = text_buffer;
    
    size_t true_file_size = fread(text_buffer, 1, file_size, input_file);
    text_buffer[true_file_size] = '\0';
    
    fclose(input_file);
        
    MyVector text_vec = {};
    MyVectorInit(&text_vec, 16);

    // FIXME Использовать strchr()

    char* current_line_ptr = text_buffer;
    MyVectorAdd(&text_vec, current_line_ptr);

    while (true) {
        current_line_ptr = strchr(current_line_ptr + 1, '\n');
        // printf("\n\n%p\n\n", current_line_ptr);
        if (current_line_ptr != NULL) {
            MyVectorAdd(&text_vec, current_line_ptr + 1);
            *current_line_ptr = '\0';
        }
        else {
            // printf("break\n");
            break;
        }
    } 

    /*
    for (size_t i = 0; i < true_file_size; i++) {
        if (text_buffer[i] == '\n') {
            text_buffer[i] = '\0';
            MyVectorAdd(&text_vec, text_buffer + (i + 1));
        }
    }
    */

    text->data = text_vec.data;

    text->size = text_vec.size;
}

void MemoryFree(Text text) {
    assert(text.data != NULL);
    assert(text.size != 0);

    free(text_buffer_start_ptr);

    free(text.data);
}

size_t FileSize(FILE* file) {
    struct stat stats = {};

    if (fstat(fileno(file), &stats) != 0) {
        fprintf(stderr, "Не удалось прочитать статистику файла\n");
        return 0;
    }

    return (size_t)stats.st_size;
}