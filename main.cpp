#include <stdio.h>

#include "MySort.h"
#include "TextParser.h"
#include "FileOutput.h"
#include "Options.h"
#include "Text.h"
#include "Settings.h"

int main(int argc, char** argv) {
    // FIXME Добавить структуру settings, Сделать стандартный конструктор который будет устанавливать настройки по умолчанию, Сделать Функции На основе аргументов командной строки
    
    Settings settings = {};
    SettingsInit(&settings);
    
    if (SettingsFromCmdOpt(&settings, argc, argv) != 0) {
        return 0;
    }
    
    Text text = {};
    TextParse(&text, settings);
    if (text.size == 0) { return 1; }
    printf("Parsed!\n");

    MyQSort(text.data, text.size, sizeof(text.data[0]), StrRyphmCmp);
    printf("Sorted!\n");

    FileOutput(text, settings);
    printf("Puted!\n");

    MemoryFree(text);
    printf("Memory free!\n");

    return 0;
}