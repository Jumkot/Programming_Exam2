// Подсчет суммы четных/нечетных чисел
#include <stdio.h>
#include <math.h>

int my_atoi(char* str);
int my_isdigit(char ch);
int sum_of_nums(char* str, int split);

int main()
{
    char str[] = "why12nums-32not43digits23";
    int split;
    printf("Введите 0 для поиска чётных чисел и 1 для нечётных\n");
    scanf("%d", &split);
    if (split) {
        printf("Сумма нечётных чисел равна %d\n", sum_of_nums(str, split));
    } else {
        printf("Сумма чётных чисел равна %d\n", sum_of_nums(str, split));
    }
    
    return 0;
}

int sum_of_nums(char* str, int split)
{
    int sum = 0;
    while (*str != '\0') {
        if ((*str == '-') || (my_isdigit(*str))) {
            char num[20] = {'\0'};
            int j = 0;
            num[j] = *str;
            str += 1;
            j++;
            while (my_isdigit(*str)) {
                num[j] = *str;
                str += 1;
                j++;
            }
            sum += ((my_atoi(num) % 2 == split) ? my_atoi(num) : 0);
        }
        str += 1;
    }
    return sum;
}

int my_atoi(char* str)
{
    int len = 0;
    int i = 0;
    if (str[0] == '-') {
        i++;
        len++;
    }
    for (; str[i] != '\0'; i++) {
        if ((my_isdigit(str[i]))) {
            len++;
            continue;
        }
        return 0;
    }
    
    int result = 0;
    for (i = len - 1; i >= 0; i--) {
        if (my_isdigit(str[i])) {
            result += (str[i] - '0') * pow(10, len - 1 - i);
        }
    }

    if (str[0] == '-') {
        result *= -1;
    }
    return result;
}

int my_isdigit(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    return 0;
}