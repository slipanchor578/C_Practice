#include <stdio.h>
#include <stdbool.h>

void is_this_a_xor(bool var1, bool var2);

int main()
{
    int a = 99;

    if ((a > 100) && (a > 200)) {
        puts("Yes");
    } else {
        puts("論理積は「かつ」なので左辺式が偽の時点でアウト");
    }

    int b = 10;

    if ((b > 9) || (b > 20)) {
        puts("論理和は「もしくは」なので左辺が真の時点でOK");
    }

    bool Y1 = true;
    bool Y2 = true;
    bool N = false;

    is_this_a_xor(Y1, Y2); // どちらもtrue
    is_this_a_xor(Y1, N); // 片方true

    return 0;
}

void is_this_a_xor(bool var1, bool var2)
{
    if ((var1 || var2) && !(var1 && var2)) {
        puts("排他的論理和はどちらか片方だけが真の時に成立する");
    } else {
        puts("not xor.");
    }
}