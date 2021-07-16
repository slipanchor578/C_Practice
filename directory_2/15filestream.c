#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[128];
    FILE *fp;

    puts("開きたいファイル名を入力してください");
    scanf("%s", filename); // ファイル名取得

    fp = fopen(filename, "r"); // リードモードなので、ファイルが存在しなければNULL
    if (fp == NULL) {
        puts("ファイルは存在しません");
        exit(1);
    }
    puts("ファイルを開きました");

    fclose(fp); // ファイルポインタはfclose()関数で閉める

    return 0;
}

/*
    ファイルへの入出力は「ストリーム」と呼ばれるインターフェイスを通して行う。
    ファイル操作を行い易くするために使われる抽象的なもの
    
    まずFILE構造体を使ってインスタンスを作る
    FILE* fp; -> これを通してファイルの入出力を行う。
    fp = fopen("開きたいファイル名", "モード名");
    ファイルを開くことができれば、ファイルへのポインタがfpに返される。ファイルへのアドレスが入ったようなもの
    読み込みモードとして開くなら「r」、書き込みモードとして開くなら「w」、既存ファイルに追加する場合なら「a」モードなどある
    
    ファイルを作成できない・開くことができなかった場合は放っておくのではなくそれ用の処理をしないといけない
    exit()関数を使ってバッファをクリアしておく必要がある
    if (fp == NULL) exit(1);

    通常プログラム実行時になにか書き込んだりする時は逐一ファイル等に書き込んでいるわけではない。
    そんなことをしていると手間がかかるので(書き込み命令、メモリを見に行く、他のプログラムに使われていないか確認等)
    バッファという確保しているメモリ群にまず書き込みに行く。バッファが溜まれば、それをディスク(RAM, HDD, SSD)等に書き込みに行く

    ファイル入出力作業を終えたら、今度はファイルポインタを適切に終了しないといけない。でなければ書き込みが正しく終わっていなかったり
    最悪他のプログラムにも影響を与えてしまう
    fclose()関数を使って、終了作業を行ってもらう。ここで書き込みや読み込みに使ったバッファのフラッシュも行ってくれる
    fclose(fp);

    ファイル操作を行うためにストリーム情報を司るファイルポインタを作成して実在のファイルと結びつける
    作業を行う
    安全にストリームとファイルを切り離せるように終了作業を行う
    これらが基本となっている

    FILE* fp;
    fp = fopen(~~.txt等, "r等");
    fclose(fp);

    */