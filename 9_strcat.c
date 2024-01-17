// Конкатенация строк
#include <stdio.h>

char* my_strcat(char* dest, char* copy);

int main()
{
    char str1[100];
    scanf("%s", str1);
    char str2[100];
    scanf("%s", str2);
    printf("%s\n", my_strcat(str1, str2));
    
    return 0;
}

char* my_strcat(char* dest, char* copy)
{
    int i = 0;
    int j = 0;
    while (dest[i]) {
        i++;
    }
    while (copy[j]) {
        dest[i] = copy[j];
        i++;
        j++;
    }
    dest[i] = '\0';

    return dest;
}