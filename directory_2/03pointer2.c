#include <stdio.h>

int main()
{
   int arr[10];
   int* ptr = &arr[0];
   
   for (int i = 0; i < 10; i++) {
       (*ptr) = i; // arr[0] = 0;
       ptr++; // ポインタのアドレスをずらす -> arr[0] -> arr[1]
   }
   
   for (int i = 0; i < 10; i++) {
       printf("arr[%d] = %d\n", i, arr[i]); // 0 ~ 9まで格納されている
   }

    ptr = &arr[0]; // ポインタにはarr[9]より先の何が置かれているか分からないアドレス先を参照しているので、元に戻す

   for (int i = 0; i < 10; i++) {
       printf("arr[%d] address = %p , ptr address = %p\n", i, &arr[i], ptr);
       ptr++; // int型なので4Byteずつずれる
   }
   
    int arr2[][2] = {
        {1,2},
        {3,4}
    };

    int (*ptr2)[2] = arr2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("ptr[%d][%d] = %d\n", i, j, ptr2[i][j]); // やや複雑だが2次元配列もポインタを介して参照できる
        }
    }

   return 0;
}