#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#include "MySort.h"
#include "TextParser.h"
#include "MyStringFunctions.h"

int main() {
    setlocale(LC_ALL, "Russian");

    char** text = NULL;

    size_t len = TextParse(&text, "./data/EngEvgeniyOnegin.txt");
    //size_t len = TextParse(&text, "./data/test.txt");

    if (len == 0) { return 1; }

    printf("Parsed!\n");

    printf("len = %lld\n", len);

    qsort(text, len, sizeof(text[0]), str_comp);

    printf("Sorted!\n");

    
    const char* output_file_name = "./out/output.txt";
    FILE* output_file = fopen(output_file_name, "w");

    for (size_t i = 0; i < len; i++) {
        if (text[i] != NULL) {
            fprintf(output_file, "%s\n", text[i]);
        }
    }

    fclose(output_file);

    printf("Puted!\n");

    for (int i = 0; i < len; i++) {
        free(text[i]);
    }

    free(text);

    printf("Memory free!\nc");
    return 0;
}