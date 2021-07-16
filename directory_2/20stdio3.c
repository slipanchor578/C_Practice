#include <stdio.h>

int main()
{
    char arr[] = "Hello stdout!\n";
    char arr2[] = "Hello stderr!\n";

    fprintf(stdout, "%s", arr);
    fprintf(stderr, "%s", arr2);
    return 0;
}

/*
    標準出力があれば、標準エラー出力も存在する
    何かエラーが起こった時に出力する文字等の出力先のこと(標準ではディスプレイ)
    これをテキストファイルにリダイレクト(>> 2つ重ねることで追記モードになる)しておけば、エラーログ等取れるということ

    ./stdio3
    -> 変数arr, arr2両方ともディスプレイ表示される
    
    ./stdio3 1> /dev/nul
    -> arrは捨てられる. エラー出力のみディスプレイ表示される

    ./stdio3 2> /dev/nul
    -> arr2は捨てられる. 標準出力のみディスプレイ表示される

    ./stdio3 > test.txt
    -> test.txtに出力、エラー出力両方とも書き込まれる。書き込みモード(w)

    ./stdio3 >> test.txt
    -> test.txtに出力、エラー出力両方とも書き込まれる。追記モード(a)で先に何か入力されていても消さない

    ./stdio3 1> /dev/nul 2> test.txt
    -> 標準出力を破棄。標準エラー出力をtest.txtに書き出す(w)

    ./stdio3 1>> test.txt 2> /dev/nul
    -> 標準出力をtest.txtに書き出す(a)。標準エラー出力を破棄する

    このようにプログラム実行結果の出力元は様々あり、出力先も選べるということ
*/