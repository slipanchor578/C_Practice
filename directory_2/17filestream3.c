#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[128];
    const char* str = "wモードでファイルに書き込みできます";
    FILE *fp;

    puts("作成したいファイル名を入力してください");
    scanf("%s", filename);

    fp = fopen(filename, "w"); // 書き込みモードでファイル作成。このモードで開くと既にファイルが存在する場合最初から上書きして書き込むことになる
    if (fp == NULL) {
        puts("ファイル作成できません");
        exit(1);
    }

    fprintf(fp, "%s\n", str); // ファイルポインタに変数strの内容を改行込みで書き込む

    fclose(fp);

    return 0;
}

// 上書きでなく追記で書き込みたい場合は「a」追記モードを選択する