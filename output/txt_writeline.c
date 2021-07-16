#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[128]; // ファイルパス用 
    char writetxt[128]; // 書き込み用
    puts("ファイル名を入力してください");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "a"); // 追加モードで開く。ファイル名が存在しなければ作成する
    if (fp == NULL) {
        puts("ファイルが開けません");
        exit(1);
    }

    puts("1行入力してください");
    getchar(); // これがないと、バッファリングに残っている改行コードがscanf()関数に入ってしまう?
    scanf("%[^\n]", writetxt); // 標準入力から改行コード以外の文字を読み取り
    fprintf(fp, "%s\n", writetxt); // これに改行を付けてファイルに書き込み

    fclose(fp); // 1度切り離す

    puts("\n---書き込み内容---");

    int fget;
    FILE* fpr = fopen(filename, "r"); // 読み込みモードで開く
    if (fp == NULL) {
        puts("ファイルが開けません");
        exit(1);
    }

    while (1) {
        fget = fgetc(fpr);
        if (!feof(fp)) printf("%c", fget); // 1文字ずつ出力
        else break;
    }

    fclose(fpr); // 切り離す
    
    return 0;
}