#include <stdio.h>

#include "MySort.h"

int int_comp(const void* val1, const void* val2) {
    return *((int*)val1) - *((int*)val2);
}

int main() {
    int array[10] = {0, 3, 4, 2, 1, 8, 6, 9, 7, 5};

    MyQSort(array, 10, sizeof(array[0]), int_comp);

    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}