#ifndef FILE_OUTPUT_H_
#define FILE_OUTPUT_H_

#include <stdlib.h>

#include "Text.h"

/// @brief Выоводит содержимое Текста в выходной файл
/// @param output_file_name Путь к выходному файлу
/// @param text Текст
/// @return 1, если не удалось открыть файл, 0 в случае успешного считывания
int FileOutput(const char* output_file_name, Text text);

#endif // FILE_OUTPUT_