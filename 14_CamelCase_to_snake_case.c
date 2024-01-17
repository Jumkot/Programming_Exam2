// Преобразование CamelCase в snake_case
#include <stdio.h>

void camel_to_snake(char* str);
size_t my_strlen(char* str);
int my_isupper(char ch);
char my_tolower(char ch);

int main()
{
    char str[100] = "CamelCase";
    camel_to_snake(str);
    printf("%s\n", str);

    return 0;
}

void camel_to_snake(char* str)
{
    int len = my_strlen(str);
    str[0] = my_tolower(str[0]);
    for (int i = 1; i < len; i++) {
        if (my_isupper(str[i])) {
            for (int j = 0; j < len - i; j++) {
                str[len - j] = str[len - j - 1];
            }
            str[i] = '_';
            str[i + 1] = my_tolower(str[i + 1]);
            len++;
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

int my_isupper(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    return 0;
}

char my_tolower(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    return ch + ('a' - 'A');
}