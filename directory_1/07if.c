#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    
    if (a > 100) { // 真の場合
        puts("bigger than 100.");
    } else { // 偽の場合
        puts("less than 100.");
    }

    int b = 51;

    if (b > 60) {
        puts("b is bigger than 60.");
    } else if (b > 50) { // else ifを使って更に条件式を追加できる
        puts("b is bigger than 50.");
    }


    int d = 99;
    printf("%s\n", d > 100? "Yes" : "No"); // 三項演算子。条件が成立する場合Yes、そうでない場合Noを表示する

    return 0;
}