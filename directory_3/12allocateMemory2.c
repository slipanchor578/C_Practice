#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double* ptr2 = (double*)malloc(sizeof(double) * 361); // double型ポインタを x 361個分用意
    if (ptr2 == NULL) {
        puts("動的メモリを確保できませんでした");
        exit(1);
    }

    double x;
    for (int i = 0; i <= 360; i++) {
        x = i * (M_PI / 180); // 度 -> radへの変換
        ptr2[i] = sin(x); // 各度数に応じたsinの値を代入
    }

    FILE* fp = fopen("sin.csv", "w"); // csvファイル作成
    if (fp == NULL) {
        puts("file can't open.");
        exit(1);
    }

    for (int i = 0; i <= 360; i++) {
        fprintf(fp,"sin%3d°,%7.4lf\n", i,ptr2[i]); // 出力。csvファイルなので「,」で区切る
    }

    fclose(fp);
    free(ptr2);

    return 0;
    // 各度数に応じたsinの値が書かれているcsvファイルが生成されている
}