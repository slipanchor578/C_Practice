#include <stdio.h>

int main(int argc, char* argv[])
{
    fprintf(stdout, "%s\n", argv[1]); // そのまま実行すると、コマンドライン引数[1]がディスプレイに表示される

    return 0;
}

/*
    まずこのプログラムを普通に実行する
    ./stdio2 hello
    -> ディスプレイに「hello」が表示される
    /stdio2 hello" "world!(コマンドライン引数は空白を読み飛ばすので" "で覆う)
    -> ディスプレイに「hello world!」が表示される
    
    今度は「.stdio2 hello >> test.txt」として実行してみる
    そうするとディスプレイには何も表示されない。しかし、test.txtファイルが作られている
    test.txtファイルを開くと「hello(改行有り)」と入力されているのが分かる
    
    これは「リダイレクト」と呼ばれる技術で標準出力先がtest.txtに変わったから
    つまりfprintf(fp, "%s\n", argv[1]); と切り替わったようなもの(fp = test.txtとする)
*/