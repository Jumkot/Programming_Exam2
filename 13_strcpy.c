// Копирование строки
#include <stdio.h>

size_t my_strlen(char* str);
char* my_strcpy(char* from, char* to);

int main()
{
    char str1[100] = "abcd";
    char str2[100];
    my_strcpy(str1, str2);
    printf("%s\n", str2);

    return 0;
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j]; j++) {
        count++;
    }
    return count;
}

char* my_strcpy(char* from, char* to)
{
    for (int i = 0; i <= my_strlen(from); i++) {
        to[i] = from[i];
    }
    return to;
}