#include <stdio.h>

int main()
{
    char a = 'a';
    unsigned char b = 255; // 符号なしなので最上位ビットまで使える
    int c = 100;
    float d = 1.0;
    double e = 0.12345;

    printf("%c\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%f\n", d);
    printf("%lf\n", e); // 変数の型に応じて書式フォーマットを変える

    int f = 1 + 2 * 3 - 4; // 1 + (6 - 4) = 3
    int g = (1 + 2) * (3 - 4); // 3 * -1 = -3

    printf("%d\n", f);
    printf("%d\n", g); // 求める答えが出るようにカッコで括る

    int h = 0;
    printf("%d\n", h++); // 0
    printf("%d\n", h); // 後置インクリメントは行った後で値が増加する

    int i = 0;
    printf("%d\n", ++i); // 1
    // 前置インクリメントは値を加算してから変数を評価する

    return 0;
}