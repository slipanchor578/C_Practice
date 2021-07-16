#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[128];
    int getf;
    FILE *fp;

    puts("開くファイル名を入力してください");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // 読み込みモードで開く
    if (fp == NULL) {
        puts("ファイルが存在しません");
        exit(1);
    }

    while (1) { // 読み込むまで無限ループ
        getf = fgetc(fp); // 1文字読み込む
        if (!feof(fp)) // ファイルストリーム内のポインタの位置がファイルの最後になるまでループ
            printf("%c", getf); // 出力
        else
            break; // ここで抜ける
    }

    fclose(fp);

    return 0;
}