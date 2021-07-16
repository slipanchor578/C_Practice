#include <stdio.h>
#include <stdint.h>

typedef union {
    uint64_t a;
    uint32_t b;
    unsigned char c;
    char d;
} UNIONS;

int main()
{
    UNIONS ins;
    ins.a = UINT64_MAX;
    printf("ins size = %dByte\n", sizeof(ins)); // 8Byte
    printf("a = %lu, b = %u, c = %d, d = %d\n", ins.a, ins.b, ins.c, ins.d);

    return 0;
}

/*
    1つのメモリ領域を複数の変数で共有するという、共用体が存在する
    型に定義した中で最大のサイズの変数の型を持って共用体のインスタンスを生成する
    
    ここでは8Byteの符号なし整数変数a、4Byteの符号なし整数変数b、1Byteの符号なしuchar変数c、
    1Byteの符号ありchar変数dを持つ共用体を宣言している

    変数aに「FFFFFFFFFFFFFFFF」の値を代入している。この値を、それぞれの型のサイズで表現可能な限り表現するのが共用体
    変数a = 「FFFFFFFFFFFFFFFF」= 18,446,744,073,709,551,615
    変数b = 「FFFFFFFF」= 4,294,967,295
    変数c = 「FF」= 0b11111111. 符号なしなので255
    変数d = 「FF」= 0b11111111. 符号ありなので、-1となる
*/