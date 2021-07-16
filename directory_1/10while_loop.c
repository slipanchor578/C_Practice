#include <stdio.h>

// whileループ

int main()
{
    #if 0
    while (1) { // ずっと真のままなのでプログラムを終了しない限り抜けない
        puts("無限ループ");
    }
    #endif

    int count = 0;
    while (count <= 30) { // countの値が30以下の時にループ
        printf("%d ", count);
        count++;
    }

    printf("\n"); // 改行

    count = 0;
    while (count <= 10) {
        printf("%d ", count);
        count++;
        if (count == 9) break; // countの値が9の時、ループから抜ける
    }

    printf("\n");

    count = 0;

    do {
        puts("1回は絶対にやります");
    } while (count < 0); // 条件は破綻しているが1回は必ずdoステートメントの内容を行う

    return 0;
}