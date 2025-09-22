#include <stdio.h>
#include <time.h>

#include "MySort.h"
#include "TextParser.h"
#include "FileOutput.h"
#include "Options.h"
#include "Text.h"
#include "Settings.h"

int main(int argc, char** argv) {
    clock_t start_time = clock();

    Settings settings = {};
    SettingsInit(&settings);
    
    if (SettingsFromCmdOpt(&settings, argc, argv) != 0) {
        return 0;
    }
    
    Text text = {};
    TextParse(&text, settings);
    if (text.size == 0) { return 1; }
    if (!settings.is_speedtest) printf("Parsed!\n");

    MyQSort(text.data, text.size, sizeof(text.data[0]), StrRyphmCmp);
    if (!settings.is_speedtest) printf("Sorted!\n");

    FileOutput(text, settings);
    if (!settings.is_speedtest) printf("Puted!\n");

    MemoryFree(text);
    if (!settings.is_speedtest) printf("Memory free!\n");
    
    clock_t end_time = clock();

    if (settings.is_speedtest) printf("Program running time: %ld ms\n", (end_time - start_time)/1000);

    return 0;
}