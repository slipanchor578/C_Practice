#include <stdio.h>

typedef struct {
    unsigned int bool: 1; // メンバ変数boolに1Bitだけ割り当てるというもの
} BOOLEAN;

typedef struct {
    const char* name;
    unsigned int super: 4; // 4Bitずつ使う
    unsigned int sub: 4;
} FOUR_B;

int main()
{
    BOOLEAN obj1, obj2, obj3;
    obj1.bool = 0x0; // 0
    obj2.bool = 0x1; // 1
    obj3.bool = 0x2; // 「2」をセットしているが、1Bitしか表現幅がないのでコンパイラに警告される
    printf("obj1のサイズ = %ldByte\n", sizeof(obj1)); // サイズ自体は構造体に含まれる型と個数(+アライメント)で決まる

    if ((obj1.bool || obj2.bool)) { // 0b00000000 || 0b00000001 
        puts("論理和");
    }

    if ((obj1.bool && obj3.bool)) { // 0b00000000 && 0b00000000
        puts("論理積");
    }

    FOUR_B obj4 = {"BITFIELD", 0b1111, 0b1010}; // 0b1111 = 15, 0b1010 = 10
    printf("name = %s, super = %d, sub = %d\n", obj4.name, obj4.super, obj4.sub);
    return 0;

}

/*
    1つの変数のメモリ領域を分けてBit単位で使えるようにするビットフィールドという機能
    通常は変数はByte単位だが(最小 = char = 1Byte)、この機能を使うことで変数に最小1Bitを割り当てて
    使うことができる
    1Bitなら、「0」か「1」しか表現できないので、フラグ管理等に使われることもある
    obj3.bool = 0x2;
    としたが、0x2 = 0b00000010 = 2
    つまり「2」を表現するには最低2Bit必要だがbool変数には1Bitしか割り振っていないため
    最下位ビットの「0」がそのまま入っている

    他のメンバ変数と共存することも可能
    ただし、ビットフィールドを使って1Bitしか表現しない構造体を作ったからといって
    インスタンスのサイズが1Bitになるわけではない。構造体のメンバ変数の一部を使わせてもらっているだけで
    サイズは普通にOOByteとかになる
*/