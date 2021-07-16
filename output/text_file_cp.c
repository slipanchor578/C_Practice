#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int output;
    char filename[128];
    puts("ファイルパスを入力してください");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r"); // コピー元のファイル読み込み
    if (fp == NULL) {
        puts("ファイルを読み込めません");
        exit(1);
    }

    strcat(filename, "_copy.txt"); // コピー先ファイルのパスを作る
    FILE* fp2 = fopen(filename, "w"); // コピー先のファイル読み込み
    if (fp2 == NULL) {
        puts("ファイルを作成できません");
        exit(1);
    }

    while (1) {
        output = fgetc(fp); // コピー元ファイルから1文字ずつ読み込む
        if (!feof(fp)) { // コピー元ファイルがEOFになるまで
            fputc(output, fp2); // コピー先ファイルに書き込む
        }
        else {
            break;
        }
    }

    fclose(fp); // 後処理
    fclose(fp2);

    return 0;
}