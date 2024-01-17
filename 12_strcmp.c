// Сравнение строк по алфавиту
#include <stdio.h>

int my_strcmp(char* str1, char* str2);

int main()
{
    char str1[] = "abc";
    char str2[] = "abe";
    char str3[] = "ab";
    printf("%d\n", my_strcmp(str1, str1));
    printf("%d\n", my_strcmp(str1, str2));
    printf("%d\n", my_strcmp(str2, str1));
    printf("%d\n", my_strcmp(str1, str3));

    return 0;
}

int my_strcmp(char* str1, char* str2)
{
    while (*str1 == *str2) {
        if (!(*str1) && !(*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    
    return *str1 < *str2 ? -1: 1;
}