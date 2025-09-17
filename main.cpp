#include <stdio.h>
#include <getopt.h>

#include "MySort.h"
#include "TextParser.h"
#include "MyStringFunctions.h"
#include "FileOutput.h"
#include "Options.h"
#include "Text.h"

int main(int argc, char** argv) {
    const char* input_file_name = "./data/EngEvgeniyOnegin.txt";
    const char* output_file_name = "./out/output.txt";
    
    int opt = 0;
    while ((opt = getopt_long(argc, argv, "f:h", long_options, NULL)) != -1) {
        switch (opt)
        {
            case 'f':
            input_file_name = optarg;
            break;
            
            case 'h':
            printf("--help(-h) - Выводит список опций\n");
            printf("--file(-f) - Позволяет заменить входной файл, требует аргумент с путем к файлу\n");
            return 0;
            break;
            
            case '?':
            fprintf(stderr, "Неизвестная опция или пропущен аргумент\n");
            return 1;
            break;
            
            default:
            fprintf(stderr, "Не обработанный случай аргументов командной строки\n");
            return 1;
            break;
        }
    }
    
    Text text = {};
    TextParse(&text, input_file_name);
    if (text.size == 0) { return 1; }
    printf("Parsed!\n");

    MyQSort(text.data, text.size, sizeof(text.data[0]), StrRyphmCmp);
    printf("Sorted!\n");

    FileOutput(output_file_name, text);
    printf("Puted!\n");

    MemoryFree(text);
    printf("Memory free!\n");

    return 0;
}