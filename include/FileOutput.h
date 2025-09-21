#ifndef FILE_OUTPUT_H_
#define FILE_OUTPUT_H_

#include <stdlib.h>

#include "Text.h"
#include "Settings.h"

/// @brief Выоводит содержимое Текста в выходной файл
/// @param settings Настройки прораммы
/// @param text Текст
/// @return 1, если не удалось открыть файл, 0 в случае успешного считывания
int FileOutput(Text text, Settings settings);

#endif // FILE_OUTPUT_