#include <stdio.h>

int main()
{
    int a = 10;
    printf("%p, %d\n", &a, a); // 変数はどこかのアドレスに紐付けられ、値もそのアドレスにある
    char arr[] = "apple";
    
    printf("arr[0] = %p, arr[1] = %p\n", &arr[0], &arr[1]); // char型は1Byte。よって---1, ---2のようにメモリ領域は1つずつずれていく

    int* ptr = NULL; // ポインタ変数を作る
    int b = 100;
    ptr = &b; // 変数bのアドレスを格納
    printf("b address = %p, ptr address = %p\n", &b, ptr); // 同じメモリ領域を示す

    *ptr = 101; // ポインタ変数を介して変数bの値を変える
    printf("b value = %d, ptr value = %d\n", b, *ptr); // 値が変わっている
    // ポインタ変数が示すアドレス先の要素にアクセスするには、変数の先に「*」間接演算子

    int arr3[] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr2 = &arr3[0];

    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(ptr2));
        ptr2++; // ptr2が示すアドレスを1つずつインクリメント
    }

    int c = 100;
    int* ptr3 = &c;
    (*ptr3)++; // ptr3が示すアドレス先の値をインクリメント
    printf("%d\n", *ptr3);
    
    return 0;
}