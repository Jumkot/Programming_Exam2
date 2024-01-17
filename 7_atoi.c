// Перевод символов строки в число
#include <stdio.h>
#include <math.h>

int my_atoi(char* str);
int my_isdigit(char ch);
size_t my_strlen(char* str);

int main()
{
    char str[] = "-55";
    printf("%d\n", my_atoi(str));
    return 0;
}

int my_atoi(char* str)
{
    int flag = 0;
    if (str[0] == '-') {
        flag = 1;
    }
    int len = my_strlen(str);
    
    int result = 0;
    for (int i = len - 1; i >= flag; i--) {
        if (my_isdigit(str[i])) {
            result += (str[i] - '0') * pow(10, len - 1 - i);
        } else {
            return 0;
        }
    }

    // if (str[0] == '-') {
    //     result *= -1;
    // }
    // return result;
    return (str[0] == '-') ? (result * -1) : result;
}

int my_isdigit(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    return 0;
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j]; j++) {
        count++;
    }
    return count;
}