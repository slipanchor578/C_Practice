#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("binarystring", "rb"); // バイナリファイル読み込み
    if (fp == NULL) {
        puts("ファイルが存在しません");
        exit(1);
    }
    
    unsigned char arr[19]; // 受け取る配列
    fread(arr, sizeof(unsigned char), 19, fp); // バイナリデータを読み込む
    printf("%s\n", arr); // 文字コードから文字列へ

    fclose(fp);

    return 0;
}