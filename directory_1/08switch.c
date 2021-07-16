#include <stdio.h>

int main()
{
    int var;
    puts("1~3から数字を入力してください");
    scanf("%d", &var);

    switch (var) {
        case 1:
            puts("1を入力しました");
            break;
        case 2:
            puts("2を入力しました");
            break;
        case 3:
            puts("3を入力しました");
            break;
        default:
            puts("1~3以外の数字を入力しました");
            break;
        
        return 0;
    }

    /*
        例えば1を押すとcase 1:ブロックの処理が行われ、breakで処理から抜ける
        仮にbreakを記述していない場合「1を入力しました」「2を入力しました」と続き
        最後の「1~3以外の数字を入力しました」まで処理が発生することになる
     */
}