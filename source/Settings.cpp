#include "Settings.h"

#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "Options.h"

void SettingsInit(Settings* settings) {
    settings->input_file_name = "./data/EngEvgeniyOnegin.txt";
    settings->output_file_name = "./out/output.txt";
    settings->is_speedtest = false;
    settings->is_generate_text = false;
    settings->generate_text_size = 0;
}

int SettingsFromCmdOpt(Settings* settings, int argc, char** argv) {
    int opt = 0;
    while ((opt = getopt_long(argc, argv, "f:sg:h", long_options, NULL)) != -1) {
        switch (opt)
        {
            case 'f':
                settings->input_file_name = optarg;
                break;
            
            case 'h':
                printf("--help(-h) - Выводит список опций\n");
                printf("--file(-f) - Позволяет заменить входной файл, требует аргумент с путем к файлу\n");
                return 1;
                break;

            case 's':
                settings->is_speedtest = true;
                break;

            case 'g':
                settings->is_generate_text = true;
                settings->generate_text_size = (size_t)atol(optarg);
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

    return 0;
}