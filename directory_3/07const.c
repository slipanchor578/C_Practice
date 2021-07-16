#include <stdio.h>

int main()
{
    const int i = 100; // 初期値100のconst int
    // i = 200; // 式は変更可能な左辺値である必要があります = 値の再代入阻止
    #if 0
    int* ptr = &i; // ポインタを使えば値を書き換えられるが、警告もでるし普通しない
    *ptr = 200;
    #endif

    const char arr[] = "See you!";
    // arr[0] = 'A'; // 再代入不可
    const char* str = "Hello World!"; // char型配列でなく、文字列リテラル
    // *str = 'A'; // セクションが違うので書き換え不可
    str = "Hello C11!"; // ただしアドレスの付け替えはできる(.rodata内に文字列Hello World!は残ったままなので容量が無駄になる)

    printf("%s\n", str);

    int a = 100;
    const int* ptr2 = &a;
    // *ptr2 = 1000; // 値の再代入はできない
    int b = 200;
    ptr2 = &b; // ただし、アドレスの再代入はできる
    printf("%d\n", *ptr2);

    int c = 300;
    int* const ptr3 = &c;
    *ptr3 = 400; // 値の再代入はできる
    printf("%d\n", c);
    int d = 500;
    // ptr3 = &d; // アドレスの付替えはできない

    return 0;
}

/*
    const型修飾子をつけると変数へのアクセス方法を厳格にする
    基本的には初期値以降の値の再代入を変更する
    よって定数のような扱い方ができる
    
    ただしconstの置く位置や、変数の型によって「再変更禁止」するものが変わることに注意
    ポインタに使うと、constの位置によってポインタ先の値変更禁止やポインタが示すアドレスの付け替え禁止が
    変わる
*/