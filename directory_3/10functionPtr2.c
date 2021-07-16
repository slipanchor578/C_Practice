#include <stdio.h>

void add_func(int*, int*);
void sub_func(int*, int*);
void mul_func(int*, int*);
void div_func(int*, int*);

int main()
{
    // *ptrArr[0] ~ [3]までに各関数のアドレスを代入
    void (*ptrArr[])(int*, int*) = {add_func, sub_func, mul_func, div_func};
    int a = 100;
    int b = 200;

    for (int i = 0; i < 4; i++) {
        (*ptrArr[i])(&a, &b); // forループで1回ずつ呼び出し
    }

    return 0;
}

void add_func(int* val1, int* val2)
{
    printf("add = %d\n", (*val1) + (*val2));
}

void sub_func(int* val1, int* val2)
{
    printf("sub = %d\n", (*val1) - (*val2));
}

void mul_func(int* val1, int* val2)
{
    printf("mul = %d\n", (*val1) * (*val2));
}

void div_func(int* val1, int* val2)
{
    printf("div = %d\n", (*val1) / (*val2));
}

/*
    関数ポインタ配列というものも作成できる
    要するに配列の各要素に関数のアドレスが入っていて、添字次第で動的に関数を使い分けるというもの
    変数が持つ値の状態次第で関数を切り替えて使える。
    いちいち関数名を書く必要がない
    
    (*ptrArr[0])() = A関数呼び出し
    (*ptrArr[1])() = B関数呼び出し
    (*ptrArr[2])() = C関数呼び出し

    の様な感じ
*/