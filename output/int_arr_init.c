#include "int_arr_init.h"

// 要素は0始まりとする
void arr_init(int count, int* arr)
{
    for (int i = 0; i < count; i++) {
        arr[i] = i;
    }
}