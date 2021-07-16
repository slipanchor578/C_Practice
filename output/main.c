#include <stdio.h>
#include "int_arr_init.h"

int main()
{
    int arr[100];
    arr_init(100, arr); // いちいち値を入れる作業からの解放
    int result = 0;

    for (int i = 0; i < 100; i++) {
        result += arr[i];
    }

    printf("合計 = %d\n", result);

    return 0;
}