#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 成績を格納する構造体を定義
    char name[8];
    unsigned char kokugo; // 0 ~ 100を表現できればいいのでunsigned char型でもいいはず
    unsigned char sugaku;
    unsigned char English;
} Grades;

int main()
{
    char title[][13] = {"出席番号", "名前", "国語", "数学", "英語"}; // タイトル
    char names[][10] = {"Aさん", "Bさん", "Cさん", "Dさん"}; // 名前や成績
    unsigned char kokugo_Arr[] = {41, 59, 78, 90};
    unsigned char sugaku_Arr[] = {77, 54, 62, 83};
    unsigned char English_Arr[] = {79, 65, 81, 73};

    Grades* Grade_Arr = (Grades*)malloc(sizeof(Grades) * 4); // ヒープ領域にメモリ確保
    if (Grade_Arr == NULL) {
        puts("動的メモリを確保できませんでした");
        exit(1);
    }

    for (int i = 0; i < 4; i++) { // 構造体配列に必要なデータを入れる
        strcpy(Grade_Arr[i].name, names[i]);
        Grade_Arr[i].kokugo = kokugo_Arr[i];
        Grade_Arr[i].sugaku = sugaku_Arr[i];
        Grade_Arr[i].English = English_Arr[i];
    }

    FILE* fp = fopen("grade_table.csv", "w"); // 書き込むファイルを作成
    if (fp == NULL) {
        puts("ファイルを作成できませんでした");
        exit(1);
    }

    fprintf(fp, "%s,%s,%s,%s,%s\n", title[0], title[1], title[2], title[3], title[4]); // 
    for (int i = 0; i < 4; i++) {
        // ファイルへ書き込み
        fprintf(fp, "%04d,%s,%3d,%3d,%3d\n", (i + 1),
         Grade_Arr[i].name, Grade_Arr[i].kokugo, Grade_Arr[i].sugaku, Grade_Arr[i].English);
    }

    fclose(fp); // 閉じる
    free(Grade_Arr);

    return 0;
}