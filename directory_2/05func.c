#include <stdio.h>

void func(void) // 関数を宣言、定義する
{
    puts("Hello World!");
}

#if 0
// コンパイラは上から下にプログラムを読み込んでいく。func2()関数の定義時にはfunc3()関数がないので警告してくれる
void func2(void)
{
    func3();
}

void func3(void)
{
    puts("Hello C11");
}
#endif

void func4(void); // プロトタイプ宣言さえしておけば、実装は後ろでも良い
int sum(int val1, int val2); // 仮引数、戻り値を記述したプロトタイプ宣言
int main()
{
    func(); // main()関数からfunc()関数の呼び出し
    //func2(); // なんだかんだ呼び出してくれるが良くない
    func4();
    int a, val1, val2;
    val1 = 1;
    val2 = 2;
    a = sum(val1, val2); // 変数も渡せる
    printf("合計値 = %d\n", a);
    printf("合計値 = %d\n", sum(1, 2)); // 数字リテラルも渡せる

    /* main()関数で最後に「0」を返しているのは
     呼び出したシステム側に「安全にmain()関数が終了した」ことを伝えるため
    */
   
    return 0;
}


void func4(void)
{
    puts("プロトタイプ宣言で呼び出し順を把握しながら関数定義せずに済む");
}

int sum(int val1, int val2) //仮引数名は定義した関数内で使われるので、main関数内の変数と名前がかぶっても問題ない(ただし分かりづらいので良くない)
{
    return (val1 + val2);
    // 戻り値として何かを必ず「return」を付ける
}