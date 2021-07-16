#include <stdio.h>

void call_value(int val)
{
    val *= 2;
}

int return_value(int val)
{
    // 値を操作できるのは良いが、わざわざ仮引数にコピーして再代入しているだけ
    return val * 2;
}

void call_reference(int* val)
{
    printf("%#lX\n", (unsigned long)val); // 参照渡しなのでmain()関数内の変数val3と同じアドレスを示す
    *val *= 2; // 直接アドレス先の値をいじるので、関数内の変数寿命や仮引数へのコピーは関係ない
}

int main()
{
    int val = 100;
    printf("値渡し前 val = %d\n", val);
    call_value(val);
    printf("値渡し後 val = %d\n", val); // 100のまま。main()関数内の変数valには影響を及ばさない

    int val2 = 200;
    printf("return前 val2 = %d\n", val2);
    val2 = return_value(val2); // 最初からval2 = val2 * 2; とすればいい
    printf("return後 val2 = %d\n", val2); // 2倍にはなっているが...

    int val3 = 300;
    printf("参照渡し前 val3 = %d アドレス = %#lX\n", val3, (unsigned long)&val3);
    call_reference(&val3); // アドレスを引数に入れる
    printf("参照渡し後 val3 = %d\n", val3); // 同じものを扱っているので、値が2倍になっている

    return 0;
}