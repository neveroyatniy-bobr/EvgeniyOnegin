#include "MySort.h"

#include <memory.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "MyStringFunctions.h"
#include "Text.h"

void* VoidPtrMove(void* ptr, ssize_t n, size_t size) {
    assert(size != 0);

    return (void*)((ssize_t)ptr + n * (ssize_t)size);
}

void MySwap(void* a, void* b, size_t size) {
    assert(a != NULL);
    assert(b != NULL);
    assert(size != 0);

    char temp = 0;
    
    for (size_t byte_count = 0; byte_count < size; byte_count++) {
        memcpy(&temp, VoidPtrMove(b, (ssize_t)byte_count, 1), 1);
        memcpy(VoidPtrMove(b, (ssize_t)byte_count, 1), VoidPtrMove(a, (ssize_t)byte_count, 1), 1);
        memcpy(VoidPtrMove(a, (ssize_t)byte_count, 1), &temp, 1);
    }
}

void MyMergeSort(void* array, size_t len, size_t size, Comparator comp) {
    assert(array != NULL);
    assert(len != 0);
    assert(size != 0);

    if (len == 1) {
        return;
    }

    size_t first_half_len = len / 2;
    size_t second_half_len = len - first_half_len;

    void* first_half = array;
    void* second_half = VoidPtrMove(array, (ssize_t)first_half_len, size);

    void* first_half_end = VoidPtrMove(first_half, (ssize_t)first_half_len, size);
    void* second_half_end = VoidPtrMove(second_half, (ssize_t)second_half_len, size);

    MyMergeSort(first_half, first_half_len, size, comp);
    MyMergeSort(second_half, second_half_len, size, comp);

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

void MyQSort(void* array, size_t len, size_t size, Comparator comp) {
    assert(array != NULL);
    assert(len != 0);
    assert(size != 0);

    if (len == 0) { return; }
    else if (len == 1) { return; }
    else if (len == 2) {
        void* temp = calloc(1, size);

        if (comp((const void*)array, (const void*)(VoidPtrMove(array, 1, size))) > 0) {
            MySwap(array, VoidPtrMove(array, 1, size), size);
        }

        free(temp);

        return;
    }

    void* sep = VoidPtrMove(array, (ssize_t)len / 2, size);
    void* start_ptr = array;
    void* end_ptr = VoidPtrMove(array, (ssize_t)len - 1, size);

    while (start_ptr != end_ptr) {
        while (comp(start_ptr, sep) < 0 && start_ptr != end_ptr) {
            start_ptr = VoidPtrMove(start_ptr, 1, size);
        }
        while (comp(end_ptr, sep) >= 0 && start_ptr != end_ptr) {
            end_ptr = VoidPtrMove(end_ptr, -1, size);
        }

        MySwap(start_ptr, end_ptr, size);

        if (start_ptr == sep) {
            sep = end_ptr;
        }
        else if (end_ptr == sep) {
            sep = start_ptr;
        }
    }

    size_t first_half_len = (size_t)((char*)sep - (char*)array) / size;
    size_t second_half_len = len - first_half_len;

    void* first_half = array;
    void* second_half = sep;

    MyQSort(first_half, first_half_len, size, comp);
    MyQSort(second_half, second_half_len, size, comp);
}

int IntCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    return *((const int*)val1) - *((const int*)val2);
}


int StrRyphmCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    const char* str1 = (*(const Line*)val1).data;
    const char* str2 = (*(const Line*)val2).data;

    int len1 = (int)((*(const Line*)val1).size);
    int len2 = (int)((*(const Line*)val2).size);

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

    while (str1 != str1_start  && str2 != str2_start && *str1 == *str2) {
        str1--;
        str2--;
    }

    if ((str1 == str1_start) ^ (str2 == str2_start)) {
        return str1 == str1_start ? -1 : 1;
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

    const char* str1 = (*(const Line*)val1).data;
    const char* str2 = (*(const Line*)val2).data;

    int len1 = (int)((*(const Line*)val1).size);
    int len2 = (int)((*(const Line*)val2).size);

    const char* str1_start = str1;
    const char* str2_start = str2;

    str1 = str1 + len1;
    str2 = str2 + len2;

    while (str1 != str1_start  && str2 != str2_start && *str1 == *str2) {
        str1--;
        str2--;
    }

    if ((str1 == str1_start) ^ (str2 == str2_start)) {
        return str1 == str1_start ? -1 : 1;
    }
    
    int signed_ans = *str1 - *str2;
    int sign = (signed_ans == 0) 
                    ? 0 
                    : signed_ans / abs(signed_ans);

    return sign;
}

int TestCmp(const void* val1, const void* val2) {
    assert(val1 != 0);
    assert(val2 != 0);

    int len1 = (int)((const Line*)val1)->size;
    int len2 = (int)((const Line*)val2)->size;

    return len1 - len2;
}