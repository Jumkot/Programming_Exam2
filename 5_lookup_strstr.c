// Поиск подстроки в строке
#include <stdio.h>

char* my_strstr(char* str, char* search); // 1 - где ищем, 2 - что ищем

int main()
{
    char* result = my_strstr("gangagadrioula", "gadr");
    if (result) {
        printf("%s\n", result);
    } else {
        printf("NULL\n");
    }
    
    return 0;
}

char* my_strstr(char* str, char* search) {
    while (*str != '\0') {
        char* start = str;
        int j = 0;
        while (*str && search[j] && (*str == search[j])) {
            str += 1;
            j++;
        }
        if (search[j] == '\0') {
            return start;
        }
        str = start + 1;
    }    
    return NULL;
}
