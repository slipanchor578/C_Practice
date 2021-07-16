#include <stdio.h>

int xx = 200; // ローカル変数と対比のグローバル変数

void dual(int x)
{
    // 仮引数xには、main()関数内の変数xの値をコピーしたものが実は入っている
    x *= 2; // コピーしてきたものを弄っているだけ
    printf("%#lX %d\n", (unsigned long)&x, x); // 200
    printf("%#lX %d\n", (unsigned long)&xx, xx);

}


int main()
{
    // 関数内で作られた変数はローカル変数。生存寿命は関数内だけ
    int x = 100;
    printf("%#lX %d\n", (unsigned long)&x, x);
    dual(x);
    printf("%#lX %d\n", (unsigned long)&x, x); // 100のまま
    // それぞれの変数xは名前は同じだがスコープが違う。dual()関数内の作業は反映されず2倍にならない

    printf("%#lX %d\n", (unsigned long)&xx, xx);
    // グローバル変数はプログラムの開始時から終了時まで存在する。どの関数からも呼び出せる
    // ただしどこからでも操作できて、値の変更結果もあらゆる場所で反映されてしまうので注意
    // どこでもありそうな名前を付けてしまうと干渉すること間違いなし
    return 0;
}