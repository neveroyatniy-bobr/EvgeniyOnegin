#include "TextParser.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <time.h>

#include "MyStringFunctions.h"
#include "MyVector.h"

// FIXME Узнать как номально сделать
char* text_buffer_start_ptr = NULL;

size_t TextParse(char*** text_ptr, const char* input_file_name) {
    assert(text_ptr != NULL);
    assert(input_file_name != NULL);
    
    size_t file_size = FileSize(input_file_name);

    FILE* input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s\n", input_file_name);
        return 0;
    }

    char* text_buffer = (char*)calloc(file_size + 1, 1);
    text_buffer_start_ptr = text_buffer;
    
    size_t true_file_size = fread(text_buffer, 1, file_size, input_file);
    text_buffer[true_file_size] = '\0';
    
    fclose(input_file);
        
    MyVector text_vec = {};
    MyVectorInit(&text_vec, 16);

    MyVectorAdd(&text_vec, text_buffer);
    for (size_t i = 0; i < true_file_size; i++) {
        if (text_buffer[i] == '\n') {
            text_buffer[i] = '\0';
            MyVectorAdd(&text_vec, text_buffer + (i + 1));
        }
    }

    *text_ptr = text_vec.data;

    return text_vec.size;
}

void MemoryFree(char** text, size_t len) {
    assert(text != NULL);
    assert(len != 0);

    free(text_buffer_start_ptr);

    free(text);
}

size_t FileSize(const char* file_name) {
    struct stat stats = {};

    if (stat(file_name, &stats) != 0) {
        fprintf(stderr, "Не удалось прочитать статистику файла\n");
        return 0;
    }

    return (size_t)stats.st_size;
}