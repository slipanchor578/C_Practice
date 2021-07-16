#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("コマンドライン引数の数 = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}

/*
    powershellやBashからプログラム実行する場合、コマンドライン引数をプログラムに渡すことができる
    変数argcには、コマンドラインから受け取った引数の数、ポインタ変数argvには、コマンドライン引数で渡された文字列が入る
    0 ~ 渡された引数の数でforループを回してる。ポインタ変数に添え字でアクセスしている
    例えば「./a.out apple banana cocoa」と入力した場合

    コマンドライン引数の数 = 4
    argv[0] = ./a.out
    argv[1] = apple
    argv[2] = banana
    argv[3] = cocoa

    となる。argvの先頭にはコマンドライン引数ではなく、プログラム名が入る
    実際には引数は3つ
*/