#ifndef FILE_OUTPUT_H_
#define FILE_OUTPUT_H_

#include <stdlib.h>

/// @brief Выоводит содержимое массива строк в выходной файл
/// @param output_file_name Путь к выходному файлу
/// @param text Массив строк
/// @param len Количество строк
/// @return 1, если не удалось открыть файл, 0 в случае успешного считывания
int FileOutput(const char* output_file_name, char** text, size_t len);

#endif // FILE_OUTPUT_