#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int filestart = 3; // ファイルを読み込む位置
    FILE* fp = fopen("binarystring", "rb");
    if (fp == NULL) {
        puts("ファイルが開けませんでした");
        exit(1);
    }

    fseek(fp, filestart, SEEK_SET); // 3Byte目から読み出す.先頭は0バイト目.
    printf("ファイルポインタの位置は%ldです\n", ftell(fp)); // ftell()関数で現在のファイルポインタ位置確認
    while (1) {
        int text = fgetc(fp);
        if (!feof(fp)) {
            printf("%c", text); // ずらした場所から出力
        } else {
            break;
        }
    }

    fclose(fp);

    return 0;
}

/*
    ファイルの先頭から順に読み込んでいく方式をシーケンシャルアクセスという
    例えばprintf("%s\n", arr);
    とした場合、printf()関数は、別に配列の途中から読み込むわけでもなく、最初からヌル文字に当たるまで
    配列を読み込む。こうした読み込み方のこと。fopen()関数で開いたテキストファイルなども同じ。
    ファイルの先頭から読み込んでいる。単純にテキスト表示したい場合は便利。
    
    ファイルの特定の場所から読み込んでいく方式をランダムアクセスという。別に「ランダム」だからといって
    メチャクチャなところから読み込むわけではない。例えば10000文字読み込むとして、本当に最後の9999文字目を表示したい場合に
    最初から読み込むのは無駄がある。こうした時に9999文字目の場所から直接読み込めればとても楽になる
    特定の場所だけを読み込んだり、特定のアドレスから書き込むことができる
    
    特定のファイル位置にアクセスするにはfseek()関数を使う
    今回はfseek(fp, filename(3), SEEK_SET);と記述している。
    これはfopen()関数で開いたbinarystringファイルのファイルポインタの位置を先頭から3Byteずらすことをしている
    SEEK_SETはstdio.hで定められた定数。ファイルポインタの先頭を示す。他にもファイルの終端の「SEEK_END」もある
    ftell()関数は、現在のファイルポインタの位置を示す。fseek()関数でずらしたことがこれで理解できる

    この後は普通に表示していくだけ
    binarystringファイルには「バスガス爆発」のutf-8コードが記述してある。
    先頭の「バ」を表示するのに3Byte使われている(fp[0] ~ fp[3]みたいな)
    先頭から3Byteずらしたので、ファイルポインタの位置はfp[4]
    よってここからシーケンシャルアクセスで逐一表示すると「バ」が抜けた「スガス爆発」が表示される
*/