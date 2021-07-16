#include <stdio.h>

int main()
{
    char arr[3][10] = {"apple", "banana", "cocoa"}; // 文字列自体が配列なので2次元配列になる。2つ目のインデックスはヌル文字を含む最大文字数
    for (int i = 0; i < 3; i++) {
        printf("%s\n", arr[i]);
    }

    char arr2[][2][10] = { // 文字列の二次元配列も作成できる(正確？には3次元)
        {"alpha", "bravo"},
        {"charlie", "delta"}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%s ", arr2[i][j]);
        }
    }

    return 0;
}