#include <stdio.h>

enum Weeks { // 特に値を指定しない場合、最初に0が振られ、そこから1ずつ増えていく
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

#if DEBUG
enum alphabet { // 値を指定することも可能
    Sunday = 100,
    Monday = 200,
    Tuesday // この場合値は201になる
};
#endif

int main()
{
    enum Weeks a = Wednesday; // enum型変数を宣言
    printf("%d\n", a); // 実態は整数値
    int b = 3;
    if (a == 3) {
        puts("Yes"); // 整数値リテラルとの比較はできる
    }

    #if DEBUG
    if (b == a) {
        puts("Yes"); // int型変数とenum型変数で比較をすることはできない(ただしコンパイルできる)
    }
    #endif

    int c = (enum Weeks)Friday; // キャストしたら代入できる
    int d = Saturday; // というか、しなくてもint型にenum型の値を代入できてしまう
    enum Weeks e = 99; // 更にenum型変数に整数代入できてしまうし、リストにない値も代入できちゃう
    printf("c = %d, d = %d, e = %d\n", c, d, e);
    enum Weeks f = Sunday;
    printf("%ldByte\n", sizeof(f)); // この処理系ではint型でなく、long unsigned int型


    switch (a) {
        case Sunday:
            puts("日曜日");
            break;
        case Monday:
            puts("月曜日");
            break;
        case Tuesday:
            puts("火曜日");
            break;
        case Wednesday:
            puts("水曜日");
            break;
        case Thursday:
            puts("木曜日");
            break;
        case Friday:
            puts("金曜日");
            break;
        case Saturday:
            puts("土曜日");
            break;
        default:
            puts("何曜日でもない");
            break;
    }

    return 0;
}


/*
    列挙型という型がある
    定数のリストを作ることができる
    単なる数字としての使い方だけではなく、表現したい情報を定数として管理することもできる(値が重要ではなく、値の持つ意味として)
    本当に定数がほしいならconst宣言も使える
    マクロとの違いはいちいち#define Sunday 0 みたいに記述する必要がない
    マクロと違って置き換えられることはないので、変数として扱うこともできる

    ただし問題もある
    スコープが存在しないので、enum Weeksの持つSundayと、enum alphabetの持つSundayは衝突する
    他にも実態は整数値なので、int型にenum型の値を代入できるし、その逆も可能である
    キャストすれば代入できるが、何ならキャストしなくても代入できてしまう
    加えてリストにない整数値も代入できてしまう
    また列挙型変数の型は処理系依存
    普通のint型だと思ったら、unsigned int型だったりする
*/