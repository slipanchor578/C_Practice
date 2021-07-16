#include <stdio.h>
#include <stdint.h>

int main()
{
    char str[] = "Longchamp";
    char* ptr = NULL;
    char** ptr2 = NULL;

    ptr = str;
    ptr2 = &ptr;
    
    printf("str[0]のアドレス   = %#lX, 内容 = %s\n", (unsigned long)&str[0], str);
    printf("ptrが示すアドレス  = %lX, ptrが格納する値 = %s, ポインタ変数ptrがある場所 = %lX\n", (uintptr_t)ptr, ptr, (uintptr_t)&ptr);
    printf("ptr2が示すアドレス = %lX, ptr2が格納する値 = %s, ポインタ変数ptr2がある場所 = %lX\n", (uintptr_t)ptr2, *ptr2, (uintptr_t)&ptr2);

    int arr[2] = {1,2};
    printf("%#lX %#lX\n", (unsigned long)&arr[0], (unsigned long)&arr[1]);

    int* z = (int*)100;
    printf("%p", &z);
    return 0;
}

/*
    ポインタがあれば、ポインタのポインタも存在する
    ポインタが示すアドレス(格納したアドレス)、ポインタが置かれるアドレスは違う
    ポインタのポインタが格納する値 = ポインタが格納する値 = 元の変数の値
    arr[0]やarr[1]が置かれているアドレス番地は32Bitを超える
    そのため変換指定子「x」に長さ修飾子の「l」を付ける
    アドレスの出力もunsignd longでキャストする
    ポインタ用のフォーマット指定子「p」を使えばいい感じに64Bit用に出力してくれる    
*/