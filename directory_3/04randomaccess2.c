#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int distance = 1024;
    unsigned char arr[] = "隣の客はよく柿食う客だ"; // 書き込む文字列を用意
    FILE* fp = fopen("binarystring2", "wb");
    if (fp == NULL) {
        puts("ファイルを開けませんでした");
        exit(1);
    }
    fseek(fp, distance, SEEK_SET); // 先頭から1キロバイトずらす
    printf("%ld\n", ftell(fp));
    fwrite(arr, sizeof(arr), 1, fp); // 1024Byte先から配列の内容を書き込む
    fclose(fp);

    FILE* fp2 = fopen("binarystring2", "rb");
    fseek(fp2, 1024, SEEK_SET); // 1キロバイト先まで飛ぶ
    printf("ファイル位置は%ldです\n", ftell(fp2));
    unsigned char a;
    while(1) {
        a = fgetc(fp2);
        if(!feof(fp2)) {
            printf("%c", a);
        } else {
            break;
        }
    }

    fclose(fp2);
    return 0;
}

/*
    実際にfseek()関数を使って書き込みたいファイルを1024Byte先までずらしてから書き込む
    hexdump等でバイナリファイルを読んでみると、何も記述していないので確かに1キロバイト先まで「0」の羅列が並んでいる
    今度はそのバイナリファイルを読み込みモードで読み込み、再びfseek()関数で書き込んだ場所までずらす
    そこから一つずつ読み込み出力する。
    fseek()関数を使わずとも、最初から読み込んで出力することもできるが(何も記述していないので、表示はされないが
    ひたすら無を出力している感じ?)かなり無駄なことをしているので、fseek()関数で目的の場所まで飛んで表示したほうが良い
*/