#include <stdio.h>

int main()
{
    char str[6]; // C言語には文字列がない。文字配列ならある
    str[0] = 'a';
    str[1] = 'p';
    str[2] = 'p';
    str[3] = 'l';
    str[4] = 'e';
    str[5] = 0; // 文字列の終わりを示す「0」を代入。ヌル文字

    for(int i = 0; i < 6; i++) printf("%c", str[i]); // 1文字ずつ出力して文字列っぽくする
    printf("\n");

    printf("%s\n", str); // %s書式を使い、ヌル文字までの文字列を出力

    char str2[5] = {'s', 't', 'a', 'r', 0}; // 文字を逐一入れていく場合、自分でヌル文字を入れないといけない
    char str3[] = "banana"; // char型配列でも添え字なしの場合領域を確保してくれる(ヌル文字の分まで)
    printf("%s\n", str2);

    return 0;
}