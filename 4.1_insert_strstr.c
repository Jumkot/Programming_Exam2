// Вставка фрагмента строки
#include <stdio.h>

void put_strstr(char* str, char* put, int index);
size_t my_strlen(char* str);

int main()
{
    char str[100] = "do you  me?";
    printf("Введите строку для вставки\n");
    char put[100];
    scanf("%s", put);
    printf("Введите номер элемента, после которого она будет вставлена\n");
    int index;
    scanf("%d", &index);
    put_strstr(str, put, index - 1);
    printf("%s\n", str);
    
    return 0;
}

void put_strstr(char* str, char* put, int index)
{
    for (int j = 0; j < my_strlen(put); j++) {
        int len = my_strlen(str);
        for (int i = 0; (len - i) > index; i++) {
            str[len - i] = str[len - i - 1];
        }
    }
    int j = 0;
    for (int i = index + 1; j < my_strlen(put); i++) {
        str[i] = put[j];
        j++;
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