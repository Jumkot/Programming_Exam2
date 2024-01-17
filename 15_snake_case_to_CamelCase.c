// Преобразование snake_case в CamelCase
#include <stdio.h>

void snake_to_camel(char* str);
size_t my_strlen(char* str);
char my_toupper(char ch);

int main()
{
    char str[100] = "snake_case_is_it";
    snake_to_camel(str);
    printf("%s\n", str);

    return 0;
}

void snake_to_camel(char* str)
{
    // int len = my_strlen(str);
    str[0] = my_toupper(str[0]);
    for (int i = 1; i < my_strlen(str); i++) {
        if (str[i] == '_') {
            str[i++] = my_toupper(str[i + 1]);
            // i++;
            for (int j = i; j < my_strlen(str); j++) {
                str[j] = str[j + 1];
            }
            // len--;
        }
    }
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
}

char my_toupper(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return ch;
    }
    return ch - ('a' - 'A');
}