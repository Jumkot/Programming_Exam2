// Определение префикса строки, не содержащего недопустимых символов
#include <stdio.h>

int my_cspn(char* str, char* set);
size_t my_strlen(char* str);

int main()
{
    char str1[] = "hello world";
    char set1[] = " ";
    int result1 = my_cspn(str1, set1);
    printf("%d: %s\n", result1, str1 + result1);
    char str2[] = "klown";
    char set2[] = "l";
    int result2 = my_cspn(str2, set2);
    printf("%d: %s\n", result2, str2 + result2);
    char str3[] = "checking";
    char set3[] = "W\n";
    int result3 = my_cspn(str3, set3);
    printf("%d: %s\n", result3, str3 + result3);

    return 0;
}

int my_cspn(char* str, char* set)
{
    int i, j;
    for (i = 0; i < my_strlen(str); i++){
        for (j = 0; j < my_strlen(set); j++) {
            if (str[i] == set[j]) {
                return i + 1;
            }
        }
    }
    return 0;
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
}