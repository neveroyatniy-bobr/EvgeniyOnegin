#include "MySort.h"

#include <memory.h>
#include <stdio.h>

void* VoidPtrMove(void* ptr, size_t n, size_t size) {
    return (void*)((size_t)ptr + n * size);
}

void MyQSort(void* array, size_t len, size_t size, Comparator comp) {
    if (len == 1) {
        return;
    }
    else {
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
}