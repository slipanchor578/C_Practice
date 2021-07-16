#include <stdio.h>
#include <stdarg.h>

void dynamicArg(int, ...);

int main()
{
    dynamicArg(10, 1,2,3,4,5,6,7,8,9,10);

    return 0;
}

void dynamicArg(int arg_num, ...)
{
    va_list args; // 可変引数を受け取る変数
    int value;
    int count;
    int result = 0;

    if (arg_num < 1) { // 可変引数の個数を確認
        return;
    }

    va_start(args, arg_num); // 可変引数を受け取る用意

    for (count = 0; count < arg_num; count++) {
        value = va_arg(args, int); // 1つずつ引数を受け取る。型はint型
        result += value;
    }

    printf("合計 = %d\n", result);

    va_end(args); // 解放しておく
}


/*
    例えばprintf()関数は、プログラム側からすれば何個の引数を与えてくるか最初からは分からない
    printf("%d\n", a); のように1個かもしれないし
    printf("%d %d %d", a, b, c); のように3個かもしれない
    
    このように引数の個数が不定である引数のことを可変引数という
    そして、可変引数を取る関数を自分で作ることもできる
    
    まずstdarg.hをインクルードする
    次に関数のプロトタイプ宣言をする

    void dynamicArg(int, ...);
    第1引数は何でも良いが、必ず固定の引数でないといけない。可変引数は第2引数以降
    可変引数は「...」で表す。これでプログラム側は可変引数を取る関数であると認識する

    これで可変引数を受け取れるようになったが、今度はこれを自分で裁かないといけない
    stdarg.hを利用して可変引数に随時アクセスする

    va_list args;
    va_list型はstdarg.hで決められている型。この変数に可変引数が入る

    va_start(args, arg_num);

    va_start()マクロを使うことで可変引数へのアクセスを開始する。
    第1引数にさきほど作ったva_list型変数、第2引数に可変引数の手前の固定引数を入れる
    これをすることで、固定引数、可変引数のスタック(位置関係)を組む感じ？

    ここからはva_args()マクロを使って、随時可変引数の値を取り出していく。
    va_args(args, int);
    第1引数にva_list型変数、第2引数に可変引数の型を明示する。
    というのも関数側は可変引数を取ることは分かっているが、引数の型に関してはチェックを行っていないので
    自分でする必要がある。可変引数をとる関数は万能ではない
    
    今回は第1引数に可変引数の個数を記入している。これを利用しforループして、
    随時va_arg()マクロを使って変数valueに可変引数を代入、それを変数resultに足し続ける
    ように動いている

    可変引数が1個しか無いのにva_args()を2回使ったりしたり、受け取る値と明示した型が違う場合には
    エラーが起こるので注意。
    受け取る可変引数の個数を予め受け取ったり、可変引数を渡す際に最後にわざと「NULL」を
    与えてwhileループでNULLにぶち当たるまで可変引数を受け取るようにするなど対策する

    全ての引数を受け取ったらva_end()でva_list型変数を解放する
    va_end(args);
*/