#include <stdio.h>

void func(void); // 戻り値なし、引数なしの関数宣言

int func2(int*); // int型戻り値、引数intポインタの関数宣言

int main()
{
    void (*fptr)(void) = func; // 戻り値なし、引数なしで関数ポインタ宣言し、func()関数のアドレスを入れる
    (*fptr)(); // 関数ポインタから呼び出し
    func(); // 普通に関数呼び出し
    // fptr(); -> 見にくいのでやっぱりカッコを付けたほうが良い

    printf("func()関数のある場所: %p\n", func); // 関数もアドレス上に配置されていることが分かる
    printf("関数ポインタfptrが示す場所: %p\n", fptr); // 関数ポインタはfunc()関数のあるアドレスを指している
    printf("関数ポインタfptr自体が置かれている場所: %p\n", &fptr); // ただし関数ポインタ自体は別のアドレスに置かれている。参照先がfunc()関数なだけ

    int (*fptr2)(int*) = func2; // 戻り値int型、引数int型ポインタの関数ポインタ宣言し、func2()関数のアドレスを入れる
    int a = 100;
    int b = (*fptr2)(&a); // 関数ポインタを使って関数呼び出し
    printf("%d\n", b);

    return 0;
}

void func(void)
{
    puts("function pointer");
}

int func2(int* val) // 2倍した値を返す関数
{
    return (*val) * 2;
}

/*
    ポインタには関数も渡せる
    関数自体がアドレスを持っているので、それを参照するポインタを作れば
    関数を間接参照できる。
    戻り値や引数があれば、それに応じて関数ポインタの書き方を変える
    int (*ptr)(int);　等...
*/