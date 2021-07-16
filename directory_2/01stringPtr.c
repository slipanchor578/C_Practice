#include <stdio.h>

int main()
{
    char arr[] = "Hello C11";
    char* ptr = &arr[0];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%c ", *(ptr + i));
    }
    *(ptr + 1) = 'H';
    printf("%s\n", ptr); // ポインタを介して変更できる

    const char* arr2 = "Hello World!";
    printf("%s\n", arr2);
    // *(arr2 + 1) = 'z'; constが付いているのでreadonly

    return 0;
}