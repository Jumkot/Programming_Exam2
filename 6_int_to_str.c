// Перевод числа в строковое представление
#include <stdio.h>

int my_itoa(int num, char* str);

int main()
{
    char str[100];
    int num = 10;
    my_itoa(num, str);
    printf("%s\n", str);

    return 0;
}

int my_itoa(int num, char* str)
{
    int i = 0;
    int flag = 0;
    if (num < 0) {
        str[i] = '-';
        i++;
        num *= -1;
        flag = 1;
    } else if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return 0;
    }

    while (num > 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i++;
    }
    int len = i + flag;
    str[i] = '\0';

    for (i = flag; i < (len/2); i++) {
        int temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return 0;
}