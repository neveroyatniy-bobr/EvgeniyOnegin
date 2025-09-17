#ifndef TEXT_PARSER_H_
#define TEXT_PARSER_H_

#include <stdlib.h>
#include <stdio.h>

#include "Text.h"

/// @brief Парсит входной файл в массив строк. Обязательно Освободить память выделенную для указателей на элементы и сами элементы
/// @param text Указатель на структуру Text с текстом
/// @param input_file_name Путь к входному файлу
void TextParse(Text* text, const char* input_file_name);

/// @brief Освобождает память, выделенную под текст.
/// @param text Текст
void MemoryFree(Text text);

/// @brief Вычисляет размер файла
/// @param file Указатель на файл
/// @return Размер файла в байтах
size_t FileSize(FILE* file);

#endif // TEXT_PARSER_H_