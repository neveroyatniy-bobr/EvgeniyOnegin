#ifndef MY_STRING_FUNCTIONS_H_
#define MY_STRING_FUNCTIONS_H_

#include <stdio.h>

/// @brief Находит ближайшее к n число в диапазоне
/// @param n n
/// @param n_min Начало диапазона 
/// @param n_max Конец диапазона
/// @return Ближайшее к n число в диапазоне
int MyClamp(int n, int n_min, int n_max);

/// @brief Проверяет, является ли символ цифрой
/// @param symbol символ
/// @return true, если является цифрой, иначе false
bool MyIsDigit(const char symbol);

/// @brief Проверяет, является ли символ знаком
/// @param symbol символ
/// @return true, если является знаком, иначе false
bool MyIsSign(const char symbol);

/// @brief Проверяет, является ли символ пробелом
/// @param symbol символ
/// @return true, если является пробелом, иначе false
bool MyIsSpace(const char symbol);

/// @brief Возводит x в степень 
/// @param x x
/// @param n n
/// @return x^n
int MyPow(int x, int n);

/// @brief Ищет первое появление символа в строке
/// @param str Строка
/// @param ch Символ
/// @return Указатель на символ в строке
char* MyStrChr(const char* str, int ch);

/// @brief Ищет последнее появление символа в строке
/// @param str Строка
/// @param ch Символ
/// @return Указатель на символ в строке
char* MyStrRChr(const char* str, int ch);

/// @brief Ищет длину строки без нуль-терминатора
/// @param str Строка
/// @return Длину строки
size_t MyStrLen(const char* str);

/// @brief Переводит строку в int
/// @param nptr Строка
/// @return Число
int MyAToI(const char *nptr);

/// @brief Копирует строку из источника в назначение
/// @param destination Назначение
/// @param source Источник
/// @return Назначение
char* MyStrCpy(char* destination, const char* source);

/// @brief Копирует не более n символов из источника в назначение
/// @param destination Назначение
/// @param source Источник
/// @param n n
/// @return Назначение
char* MyStrNCpy(char* destination, const char* source, size_t n);

/// @brief Объединяет 2 строчки копируя источник в конец назначения
/// @param destination Назначение
/// @param source Источник
/// @return Назначение, в конец которого скопирован источник
char* MyStrCat(char *destination, const char *source);

/// @brief Копирует в конец назначения не более n символов из источника
/// @param destination Назначение
/// @param source Источник 
/// @param n n
/// @return Назначение, в конец которого скопировано не более n символов из источник
char* MyStrNCat(char *destination, const char *source, size_t n);

/// @brief Сравнивает 2 строки
/// @param str1 Строка 1
/// @param str2  Строка 2
/// @return Если строки равны возвращает 0, если числовое значение первого несовпавшего символа меньше в строке 1б то -1, иначе 1
int MyStrCmp(const char *str1, const char *str2);

/// @brief Сравнивает первые n символов из 2х строк
/// @param str1 Строка 1
/// @param str2  Строка 2
/// @param n  n
/// @return Если первые n символов строки равны возвращает 0, если числовое значение первого несовпавшего символа меньше в строке 1б то -1, иначе 1
int MyStrNCmp(const char *str1, const char *str2, size_t n);

/// @brief Дубилирует строку в свобоное место в памяти
/// @param str Строка
/// @return Указатель на начало дубликата, если места нет возвращает NULL 
char* MyStrDup(const char *str);

/// @brief Выводит все символы строки в поток, но вместо \\0 выводит \\n
/// @param str Строка
/// @param stream Поток
/// @return -1 при ошибке вывода, иначе количество выведенных символов
int MyFPutS(const char *str, FILE *stream);

/// @brief Выводит все символы строки в консоль, но вместо \\0 выводит \\n
/// @param s Строка
/// @return -1 при ошибке вывода, иначе количество выведенных символов
int MyPutS(const char *s);

/// @brief Записывает в строку из потока не более n символов до \\n или EOF
/// @param str Строка
/// @param n n
/// @param stream Поток
/// @return Строку, а в случае ошибки NULL
char* MyFGetS(char *str, int n, FILE *stream);

/// @brief Записывает из потока в буффер. Если буффер переполненб может удваивает его размер. Если буффера нетб Создает буффер на 1 символ.
/// @param lineptr Буффер
/// @param n Размер буффера
/// @param stream Поток
/// @return Количество считанных символовй
size_t MyGetLine(char** lineptr, size_t* n, FILE* stream);

/// @brief Ищет подстроку в строке
/// @param haystack строка
/// @param needle подстрока
/// @return указатель на первое упоминание строки
char* MyStrStr(const char *haystack, const char *needle);

/// @brief Ищет подстроку в строке
/// @param haystack строка
/// @param needle подстрока
/// @return указатель на первое упоминание строки
char* MyFastStrStr(const char* haystack, const char* needle);



#endif // MY_STRING_FUNCTIONS_H_