#ifndef TEXT_PARSER_H_
#define TEXT_PARSER_H_

#include <stdlib.h>

/// @brief Парсит входной файл в массив строк. Обязательно Освободить память выделенную для указателей на элементы и сами элементы
/// @param text Указатель на массив строк
/// @param input_file_name Путь к входному файлу
/// @return Количество строк в входном файле
size_t TextParse(char*** text, const char* input_file_name);

/// @brief Освобождает память, выделенную под массив строк.
/// @param text Массив строк
/// @param len Количество строк
void MemoryFree(char** text, size_t len);

/// @brief Вычисляет размер файла
/// @param file_name Имя файла
/// @return Размер файла в байтах
size_t FileSize(const char* file_name);

#endif // TEXT_PARSER_H_