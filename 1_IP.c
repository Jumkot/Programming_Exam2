// Задача проверки корректности IP адреса узла
#include <stdio.h>
#include <math.h>

int ip_check(char* ip);
int my_atoi(char* str);
int my_isdigit(char ch);
int my_stok(char* str, char symbol, char** ptr);
size_t my_strlen(char* str);

int main()
{
    char ip1[] = "192.168.1.1";
    char ip2[] = "93.158.134.3";
    char ip3[] = "173.194.47.164";
    char ip4[] = "91.0.245.216";
    char ip5[] = "124.34.90.12";
    char ip6[] = "300.84.0.173";
    char ip7[] = "10.-2.111.204";
    char ip8[] = "10.111.204";
    char ip9[] = "1.203.17.";
    char ip10[] = ".84.0.173";
    char ip11[] = "10...1";

    printf("%d\n", ip_check(ip1));
    printf("%d\n", ip_check(ip2));
    printf("%d\n", ip_check(ip3));
    printf("%d\n", ip_check(ip4));
    printf("%d\n", ip_check(ip5));
    printf("%d\n", ip_check(ip6));
    printf("%d\n", ip_check(ip7));
    printf("%d\n", ip_check(ip8));
    printf("%d\n", ip_check(ip9));
    printf("%d\n", ip_check(ip10));
    printf("%d\n", ip_check(ip11));

    return 0;
}

int ip_check(char* str)
{
    char* ptr[100];
    int num = my_stok(str, '.', ptr);
    if (num != 4) {
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (*(ptr[i]) == '\0') {
            return 0;
        }
        int digit = my_atoi(ptr[i]);
        if ((digit < 0) || (digit > 255)) {
            return 0;
        }
    }
    return 1;
}

int my_stok(char* str, char symbol, char** ptr)
{
    if (str[0] != symbol) {
        ptr[0] = str;
    } else {
        ptr[0] = str + 1;
    } 
    str += 1;
    int num = 1;

    while (*str != '\0') {
        if (*str == symbol) {
            *str = '\0';
            num++;
            ptr[num - 1] = str + 1;
        }
        str += 1;
    }
    return num;
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

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
}