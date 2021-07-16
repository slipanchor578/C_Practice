#include <stdio.h>

int main()
{
    int val1 = 100;
    float val2 = 200.123;
    printf("%g\n", val1 + val2); // 型の表現が大きい方に合わせてくれる

    float val3 = 300.123;
    int val4 = val3; // float -> int型に代入
    printf("%d\n", val4); // 300. 小数点以下部のデータが欠損してしまう

    printf("%f\n", val3);
    printf("%d\n", (int)val3); // 変数の型を変えるキャストを使う
    printf("%f\n", val3 - (int)val4); // キャストを使い、小数点以下部を出力

    return 0;
}