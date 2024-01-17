// Проверка строк на совпадение без учета регистра
#include <stdio.h>

int is_twins_reg(char* str1, char* str2);
char my_tolower(char ch);
size_t my_strlen(char* str);

int main()
{
    char str1[] = "Are you here?";
    char str2[] = "are you here?";
    char str3[] = "Are you here?";
    char str4[] = "Are you here";
    printf("1, 2: %d\n", is_twins_reg(str1, str2));
    printf("1, 3: %d\n", is_twins_reg(str1, str3));
    printf("2, 3: %d\n", is_twins_reg(str2, str3));
    printf("1, 4: %d\n", is_twins_reg(str1, str4));

    return 0;
}

int is_twins_reg(char* str1, char* str2)
{
    if (my_strlen(str1) != my_strlen(str2)) {
        return 0;
    }
    while (*str1 && *str2) {
        if (my_tolower(*str1) == my_tolower(*str2)) {
            str1 += 1;
            str2 += 1;
        } else {
            return 0;
        }
    }
    return 1;
}

char my_tolower(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    return ch + ('a' - 'A');
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
}