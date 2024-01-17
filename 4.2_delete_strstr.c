// Удаление подстроки
#include <stdio.h>

void del_strstr(char* str, char* search);
size_t my_strlen(char* str);

int main()
{
    char str[] = "fuck i love you";
    del_strstr(str, "i love ");
    printf("%s\n", str);
    
    return 0;
}

void del_strstr(char* str, char* del) {
    int i = 0;
    while (str[i]) {
        int j = 0;
        while (str[i] && del[j] && (str[i] == del[j])) {
            i++;
            j++;
        }
        if (!del[j]) {
            for (; i <= my_strlen(str); i++) {
                str[i - j] = str[i];
            }
        }
        i++;
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