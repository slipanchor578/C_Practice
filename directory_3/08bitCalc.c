#include <stdio.h>

int main()
{
    unsigned char a = 0xff;
    printf("論理積: %X\n", a & 0x0f); // 11111111 & 00001111 = 0b1111 = 0xF

    unsigned char b = 100; // 01100100

    if (b & 0x40) { // 01100100 & 01000000 ビットフラグの確認に使える
        puts("7Bit目はonになっています");
    }

    printf("論理和: %d\n", 0x0f | 0xf0); // 00001111 | 11110000 = 11111111 = 255

    char c = 127; // 最大値
    printf("排他的論理和: %d\n", c ^ 0xff); // 01111111 ^ 11111111 = 10000000 = 128 ビット反転

    printf("ビット反転 + 1 = 2の補数表現: %d\n", (~c) + 1); // ~c = 10000000 + 1 = 10000001 = -127

    unsigned char d = 0x1; // value = 1
    for (int i = 0; i < 8; i++) {
        printf("%d回目左ビットシフト: %d\n", i, d << i); // 左ビットシフトは値を2倍する
    }

    printf("20の左1ビットシフト: %d\n", 20 << 1); // 40になる

    unsigned short int e = 0x100; // value = 255
    for (int i = 0; i < 8; i++) {
        printf("%d回目右ビットシフト: %d\n", i, e >> i); // 右ビットシフトは値を1/2倍する
    }

    printf("20の右1ビットシフト: %d\n", 20 >> 1); // 10になる

    char f = 0xff; // -1
    printf("左1ビットシフト = %d %x\n", f << 1, f << 1); // -2, 0xfffffffe = charは1Byteなので0b11111110.空いた分は0で埋められる
    printf("右1ビットシフト = %d %x\n", f >> 1, f >> 1); // -1, 0xffffffff. ひたすら1で埋められる

    return 0;
}

/*
    ビット処理するための演算子を使ってビット演算できる
    「&」演算子を使うことで論理積演算ができる
    左オペランド、右オペランドの各ビット同士が「1」であればそのまま「1」になる。どちらか
    「0」であればそのまま「0」になる
    0xf0 & 0x0f
    11110000
    00001111
    00000000 = 0になる

    「|」演算子を使うことで論理和演算ができる
    左オペランド、右オペランドの各ビット同士が「0」の時以外、つまりどちらか1つでも「１」であれば
    そのまま「1」にする
    0xf0 | 0x0f
    11110000
    00001111
    11111111 = 255になる

    「^」演算子を使うことで排他的論理和演算ができる。
    お互いのビット同士が「1」の時も「0」にするようになった論理和演算。
    つまりそれぞれのビット同士が「1」「0」、「0」「1」以外0になってしまう
    0xff ^ 0xff
    11111111
    11111111
    00000000 = 0になる

    「~」演算子を使うとビット反転できる
    ~(01111111) = 10000000
    ビット反転したものに「1」を足すと2の補数表現ができる
    10000000 + 1 = 10000001 = -127
    char型の変数で、値が127を超えると、2の補数表現を使って負数に切り替わっている。
    char型だけでなく、符号付きの型は2の補数表現を使って、最上位ビットを用いて負の値を表現している

    ビットシフトすると、左ビットシフトの場合は値を2倍、右ビットシフトすると値を1/2倍する
    00000001 << 1 = 00000010 = 2
    10000000 >> 1 = 01000000 = 64

    ずれることで空いたり埋まったりする部分は0で埋められる
    負数の場合は1で埋められる
    型に合わない場合は切り捨てられる
    例えばchar型は1Byte = 8Bitなので、左ビットシフトして、9Bit目に移動したビットは無視される
*/