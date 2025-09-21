#ifndef MY_SORT_H_
#define MY_SORT_H_

#include <stdlib.h>

/// @brief Указатель на компаратор(-, если val1 < val2, 0, если val1 == val2, иначе +)
typedef int (*Comparator)(const void* val1, const void* val2);

/// @brief Передвигает указатель без типа на n элементов вперед
/// @param ptr Указатель на указатель
/// @param n n
/// @param size Размер одного элемента в байтах
/// @return Сдвинутый указатель
void* VoidPtrMove(void* ptr, size_t n, size_t size);

/// @brief Сортирует массив используя компаратор
/// @param array Массив
/// @param len Количество элементов массива
/// @param size Размер одного элемента массива в байтах
/// @param comp Компаратор
void MyQSort(void* array, size_t len, size_t size, Comparator comp);

/// @brief Компаратор для интов
/// @param val1 val1
/// @param val2 val2
/// @return -, если val1 < val2, 0, если val1 == val2, иначе +
int IntCmp(const void* val1, const void* val2);

/// @brief Компаратор для строк по рифмам
/// @param val1 val1
/// @param val2 val2
/// @return -, если val1 < val2, 0, если val1 == val2, иначе +
int StrRyphmCmp(const void* val1, const void* val2);

/// @brief Компаратор для строк обратный
/// @param val1 val1
/// @param val2 val2
/// @return -, если val1 < val2, 0, если val1 == val2, иначе +
int StrReverceCmp(const void* val1, const void* val2);

/// @brief Компаратор для строк обратный
/// @param val1 val1
/// @param val2 val2
/// @return -, если val1.size < val2.size, 0, если val1.size == val2.size, иначе +
int TestCmp(const void* val1, const void* val2);

#endif // MY_SORT_H_