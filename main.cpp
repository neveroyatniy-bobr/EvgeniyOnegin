#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#include "MySort.h"
#include "TextParser.h"
#include "MyStringFunctions.h"
#include "FileOutput.h"

int main() {
    char** text = NULL;
    const char* inoutput_file_name = "./data/EngEvgeniyOnegin.txt";
    const char* output_file_name = "./out/output.txt";

    size_t len = TextParse(&text, inoutput_file_name);
    if (len == 0) { return 1; }

    qsort(text, len, sizeof(text[0]), str_comp);
    printf("Sorted!\n");

    FileOutput(output_file_name, text, len);

    MemoryFree(text, len);

    return 0;
}