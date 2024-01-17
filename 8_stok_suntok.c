// Разбиение строки на поля и ее восстановление после разбиения
#include <stdio.h>

int my_stok(char* str, char symbol, char** ptr);
int my_suntok(char* str, char symbol, char** ptr, int num);

int main()
{
    char str1[] = "/Users/USER/where_i_must/to_go.png";
    char str2[] = "124.34.90.12";
    char* ptr1[100];
    char* ptr2[100];

    int num1 = my_stok(str1, '/', ptr1);
    for (int i = 0; i < num1; i++) {
        printf("%s\n", ptr1[i]);
    }
    printf("\n");

    int num2 = my_stok(str2, '.', ptr2);
    for (int i = 0; i < num2; i++) {
        printf("%s\n", ptr2[i]);
    }
    printf("\n");

    my_suntok(str1, '/', ptr1, num1);
    printf("%s\n\n", str1);

    my_suntok(str2, '.', ptr2, num2);
    printf("%s\n", str2);

    return 0;
}

int my_stok(char* str, char symbol, char** ptr)
{
    if (str[0] != symbol) {
        ptr[0] = str;
    } else {
        ptr[0] = str + 1;
    } 
    str += 1;
    int num = 1;

    while (*str != '\0') {
        if (*str == symbol) {
            *str = '\0';
            num++;
            ptr[num - 1] = str + 1;
        }
        str += 1;
    }
    return num;
}

int my_suntok(char* str, char symbol, char** ptr, int num)
{
    for (int i = 1; i < num; i++) {
        *(ptr[i] - 1) = symbol;
    }
    return 0;
}