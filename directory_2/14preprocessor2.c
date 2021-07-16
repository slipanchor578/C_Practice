#include <stdio.h>

#define DEBUG
#define printSTR(str) printf("%s\n", #str) // #演算子. 引数を文字列化してくれる
#define concats(a) (ver ## a) // ##演算子. 左辺、右辺を結合する

int main()
{
    #if defined DEBUG // マクロ名さえ定義しておけばいい
        puts("デバッグ中...");
    #else
        puts("リリース版...");
    #endif

    # ifndef RELEASE // RELEASEマクロは定義されていないので、#ifndefブロックに入る
        puts("RELEASE マクロは定義されていません");
    #endif

    // #error ERROR // error命令を出すと、メッセージとともにエラーが出る

    printSTR(library); // -> printf("%s\n", "library");
    
    int ver1 = 100;
    printf("%d\n", concats(1)); // -> printf("%d\n", ver1);

    return 0;
}