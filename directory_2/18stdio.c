#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[128];
    int outputs;
    FILE* fp;
    puts("Enter your filename.");
    scanf("%s", filename); // 標準入力から受け取っている
    fp = fopen(filename, "r");
    if (fp == NULL) {
        puts("Do not open file.");
        exit(1);
    }

    while (1) {
        outputs = fgetc(fp);
        if (!feof(fp)) fputc(outputs, stdout); // 標準出力(ディスプレイ)に出力
        else break;
    }

    fclose(fp);

    return 0;
}

/*
    標準入出力というものがある
    標準出力、標準入力のこと
    標準出力 = ディスプレイ
    標準入力 = キーボード
    「標準」であって、出力、入力先は変更することができる
    printf()関数は普通に使うとディスプレイに文字を出力してくれるが、これは標準出力先がディスプレイに決まっているから*/
