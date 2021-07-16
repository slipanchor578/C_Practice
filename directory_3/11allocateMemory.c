#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // ヌル文字込で223Byteある文字列
    //char arr[] = "Lorem, ipsum dolor sit amet consectetur adipisicing elit. Repellendus vel illum eaque minima, aliquid consequatur qui nemo voluptatem maxime, recusandae rerum beatae consequuntur! Illum sed in, aspernatur aliquam eum quam.";
    
    char* ptr = (char*)malloc(sizeof(char) * 223); // 動的にメモリ確保
    if (ptr == NULL) { // nullならクリアして終了
        puts("動的メモリを確保できませんでした");
        exit(1);
    }

    // 文字列コピー
    strcpy(ptr, "Lorem, ipsum dolor sit amet consectetur adipisicing elit. Repellendus vel illum eaque minima, aliquid consequatur qui nemo voluptatem maxime, recusandae rerum beatae consequuntur! Illum sed in, aspernatur aliquam eum quam.");

    // コピーされているか確認
    if (ptr[222] != '\0') { // コピーできていたら配列の最後にヌル文字があるはず
        free(ptr);
        exit(1);
    }

    FILE* fp = fopen("sample.txt", "w"); // 書き込みたいファイルを開く
    if (fp == NULL) {
        puts("ファイルを作成できませんでした");
        exit(1);
    }

    fprintf(fp, "%s\n", ptr); // ファイルポインタに、動的に確保したポインタが示す先の文字列を書き込む

    fclose(fp); // FILE型はfclose()関数で解放
    free(ptr); // 動的ポインタ型はfree()関数で解放

    return 0;
    // cat sample.txt すれば、コピーされているのが分かる
}

/*
    通常配列の容量などはプログラムの実行前には決まっている
    動的なメモリ割り当てを行うとプログラム実行中に必要に応じたメモリ領域を確保することができる
    また、実行環境によってスタック領域を使いすぎるとオーバーフローする恐れがある
    大量に配列を確保したり、構造体を使ったりする場合は動的にメモリ確保し、ヒープ領域へ逃がすことも必要になってくる

    malloc()関数、calloc()関数を使う
    malloc()関数は動的にメモリを割り当て、確保したメモリ領域の初めのアドレスを返す。
    アドレスの先々には何が入っているか分からない。不定
    calloc()関数も同様にメモリを割り当てるが、確保したメモリ領域の値を0セットする
    void*型でポインタが返ってくるので、必要に応じてキャストする

    確保したメモリ領域はfree()関数を使って解放する
    決して普通に使っている変数をfree(&a);
    のようにしたりしてはいけない。動的に確保したポインタ変数だけをfree()関数で解放する

    char* ptr = (char*)malloc(sizeof(char) * 10);
    -> char型10個分のポインタ
    */