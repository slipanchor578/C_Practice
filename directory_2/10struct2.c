#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char* name;
    int age;
} PERSON;

struct SUB_INS {
    int x;
    int y;
};

typedef struct { // 構造体は入れ子にすることができる
    const char* name;
    struct SUB_INS s_ins;
} MAIN_INS;

void initPERSON(PERSON* obj, const char* name, int age)
{
    obj->name = name;
    obj->age = age;
}

void println(const PERSON* obj)
{
    printf("%s %d\n", obj->name, obj->age);
}

int main()
{
    PERSON personARR[2]; // 構造体の配列も作成できる
    personARR[0].name = "apple"; // 1つの配列内要素が、構造体定義で決められたメンバ変数をそれぞれ持っている
    personARR[0].age = 10;
    personARR[1].name = "banana";
    personARR[1].age = 20;

    for (int i = 0; i < 2; i++) {
        println(&personARR[i]); // それぞれの要素が持つメンバ変数の値を出力
    }

    printf("\n");

    PERSON obj = {"cocoa", 10};
    PERSON obj2 = obj; // 構造体は同じ型の場合、コピーできる(objの値でobj2を初期化)
    PERSON obj3;
    obj3 = obj; // 代入もできる？
    println(&obj2); // コピーできている
    println(&obj3); // コピーできている

    PERSON* ptr = &obj;
    printf("%s %d\n", ptr->name, ptr->age); // 構造体ポインタを使ってインスタンスの値を操作できる
    printf("\n");

    char arr[][20] = {"北海道", "青森", "岩手", "宮城", "山形"}; // メンバ変数の値となる配列を作る
    int arr2[] = {10, 20, 30, 40, 50};

    printf("personARRのサイズ = %ldByte\n", sizeof(personARR)); // 構造体はかなりメモリ領域を喰う。スタック領域に置くには負担
    printf("\n");

    PERSON* ptr2 = (PERSON*)malloc(sizeof(PERSON) * 5); // ヒープ領域に確保する
    for (int i = 0; i < 5; i++) {
        initPERSON((ptr2 + i), arr[i], arr2[i]); // それぞれのインスタンスを初期化
    }

    for (int i = 0; i < 5; i++) {
        println((ptr2 + i)); // 構造体配列を使えば、大量のデータを扱える
    }

    free(ptr2); // 解放

    MAIN_INS ins;
    ins.name = "apple";
    ins.s_ins.x = 100; // .演算子でネストした構造体の変数にアクセス
    ins.s_ins.y = 200;

    printf("name = %s, x = %d, y = %d\n", ins.name, ins.s_ins.x, ins.s_ins.y);

    return 0;
}