// Определение префикса строки, состоящего только из допустимых символов
#include <stdio.h>

int my_spn(char* str, char* set);
size_t my_strlen(char* str);

int main()
{
    char str1[] = "hello world";
    char set1[] = "dloherw";
    int result1 = my_spn(str1, set1);
    printf("%d: %s\n", result1, str1);
    char str2[] = "klown";
    char set2[] = "okl";
    int result2 = my_spn(str2, set2);
    printf("%d: %s\n", result2, str2);
    char str3[] = "checking";
    char set3[] = "W\n";
    int result3 = my_spn(str3, set3);
    printf("%d: %s\n", result3, str3);

    return 0;
}

int my_spn(char* str, char* set)
{
    int i, j;
    for (i = 0; i < my_strlen(str); i++){
        int flag = 0;
        for (j = 0; j < my_strlen(set); j++) {
            if (str[i] == set[j]) {
                flag++;
            }
        }
        if (!flag) {
            str[i] = '\0';
            return i;
        }
    }
    str[i] = '\0';
    return i;
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
}