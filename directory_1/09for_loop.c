#include <stdio.h>
#include <string.h>

int main()
{
    int result = 0;
    int i;

    for (i = 0; i <= 10; i++) { // 0 ~ 10までループ
        result += i;
    }
    printf("%d\n", result); // 変数iの合計値

    for (int i = 0; i < 10; i++) { // ステートメント内でも宣言、初期化できる
        printf("%d ", i);
    }

    char arr[] = "password";
    char arr2[10];
    do {
        puts("passwordと入力してください");
        scanf("%s", arr2);
        if (strcmp(arr, arr2) == 0) { // チェック
            puts("正しく入力されています");
            break; // 入力されていたら処理を抜ける
        } else {
            puts("入力されていません");
            continue; // もう一回puts()関数からやり直し
        }
    } while (1);

    return 0;
}