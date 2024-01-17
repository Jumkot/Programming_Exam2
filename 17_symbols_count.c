// Подсчет количества вхождений в строку символов из набора
#include <stdio.h>

int is_here(char* str, char* set);

int main()
{
    char str[100];    
    char set[] = "AaEeIiOoUuYy";
    scanf("%s", str);
    printf("%d\n", is_here(str, set));
    
    return 0;
}

int is_here(char* str, char* set)
{
    int count = 0;
    for (int i = 0; str[i]; i++){
        for (int j = 0; set[j]; j++) {
            if (str[i] == set[j]) {
                count++;
            }
        }
    }
    return count;
}