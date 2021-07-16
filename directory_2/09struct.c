#include <stdio.h>

struct PERSON { // struct OOO でOOO型の構造体を宣言する
    const char* name; // メンバ変数
    int age;
};

typedef struct { // typedefを使ってPERSON2型を宣言する
    const char* name;
    int age;
} PERSON2;

void printPERSONOLD(struct PERSON obj) // 値渡し
{
    printf("%p\n%s %d\n",&obj, obj.name, obj.age); // 毎回関数側の変数にコピーされてしまう
}

void printPERSONNEW(PERSON2* obj) // 参照渡し
{
    printf("%p\n%s %d\n", obj, obj->name, obj->age); // 同じアドレス先の値をいじるので省エネ
}

int main()
{
    struct PERSON p1; // PERSON型のインスタンスp1を宣言
    p1.name = "Michael"; // 「.」演算子でメンバ変数の値にアクセス
    p1.age = 20;
    struct PERSON p2 = {"Dave", 30}; // 一括で初期化もできる
    PERSON2 p3 = {"花子", 10}; // typedefは 「OOにXXという別名を付ける」という使い方ができるので、いちいち「struct」を書かなくて良くなる

    printf("構造体の容量 = %ldByte\n", sizeof(p1)); // 構造体は色々な型をメンバ変数として使えるのでサイズが大きくなる
    printPERSONOLD(p2); // そのため、値渡しで関数処理していると時間も負担もかかる
    printPERSONNEW(&p3); // 参照渡しで操作する

    return 0;
}