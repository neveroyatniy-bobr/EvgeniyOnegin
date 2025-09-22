#ifndef TEXT_GENERATOR_H_
#define TEXT_GENERATOR_H_

#include <stdio.h>

#include "Buffer.h"
#include "Settings.h"

static const size_t LINE_SIZE = 36;
static const size_t AVALIABLE_MEMORY_SIZE = 4 * 1024;

int GenerateText(Settings settings);

void SymbolToFile(char symbol, FILE* file, Buffer* buffer);

#endif // TEXT_GENERATOR_H_