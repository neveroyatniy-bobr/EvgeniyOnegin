#include "MySort.h"

#include <memory.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "MyStringFunctions.h"

void* VoidPtrMove(void* ptr, size_t n, size_t size) {
    assert(size != 0);

    return (void*)((size_t)ptr + n * size);
}

void MyQSort(void* array, size_t len, size_t size, Comparator comp) {
    assert(array != NULL);
    assert(len != 0);
    assert(size != 0);

    if (len == 1) {
        return;
    }

    size_t first_half_len = len / 2;
    size_t second_half_len = len - first_half_len;

    void* first_half = array;
    void* second_half = VoidPtrMove(array, first_half_len, size);

    void* first_half_end = VoidPtrMove(first_half, first_half_len, size);
    void* second_half_end = VoidPtrMove(second_half, second_half_len, size);

    MyQSort(first_half, first_half_len, size, comp);
    MyQSort(second_half, second_half_len, size, comp);

    void* merge_array = calloc(len, size);
    void* const start_merge_array = merge_array;

    while (first_half != first_half_end || second_half != second_half_end) {
        if (first_half == first_half_end) {
            memcpy(merge_array, second_half, size);
            merge_array =  VoidPtrMove(merge_array, 1, size);
            second_half = VoidPtrMove(second_half, 1, size);
        }
        else if (second_half == second_half_end) {
            memcpy(merge_array, first_half, size);
            merge_array =  VoidPtrMove(merge_array, 1, size);
            first_half = VoidPtrMove(first_half, 1, size);
        }
        else {
            if (comp(first_half, second_half) <= 0) {
                memcpy(merge_array, first_half, size);
                merge_array =  VoidPtrMove(merge_array, 1, size);
                first_half = VoidPtrMove(first_half, 1, size);
            }
            else {
                memcpy(merge_array, second_half, size);
                merge_array =  VoidPtrMove(merge_array, 1, size);
                second_half = VoidPtrMove(second_half, 1, size);
            }
        }
    }

    memcpy(array, start_merge_array, len * size);

    
    free(start_merge_array);
}

int IntCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    return *((const int*)val1) - *((const int*)val2);
}

int StrRyphmCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    const char* str1 = *(const_cast<char**>((const char* const*)val1));
    const char* str2 = *(const_cast<char**>((const char* const*)val2));

    int len1 = (int)MyStrLen(str1);
    int len2 = (int)MyStrLen(str2);

    const char* str1_start = str1;
    const char* str2_start = str2;

    str1 = str1 + len1;
    str2 = str2 + len2;

    while (!isalpha(*str1) && str1 != str1_start) {
        str1--;
    }
    while (!isalpha(*str2) && str2 != str2_start) {
        str2--;
    }

    while (*str1 == *str2 && str1 != str1_start  && str2 != str2_start) {
        str1--;
        str2--;
    }

    if ((str1 == str1_start) ^ (str2 == str2_start)) {
        if (str1 == str1_start) {
            return -1;
        }
        else {
            return 1;
        }
    }
    
    int signed_ans = *str1 - *str2;
    int sign = (signed_ans == 0) 
                    ? 0 
                    : signed_ans / abs(signed_ans);
    
    return sign;
}

int StrReverceCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    const char* str1 = *(const char* const*)val1;
    const char* str2 = *(const char* const*)val2;

    int len1 = (int)MyStrLen(str1);
    int len2 = (int)MyStrLen(str2);

    const char* str1_start = str1;
    const char* str2_start = str2;

    str1 = str1 + len1;
    str2 = str2 + len2;

    while (*str1 == *str2 && str1 != str1_start  && str2 != str2_start) {
        str1--;
        str2--;
    }

    if ((str1 == str1_start) ^ (str2 == str2_start)) {
        if (str1 == str1_start) {
            return -1;
        }
        else {
            return 1;
        }
    }
    
    int signed_ans = *str1 - *str2;
    int sign = (signed_ans == 0) 
                    ? 0 
                    : signed_ans / abs(signed_ans);
    
    return sign;
}