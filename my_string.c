#include <stdio.h>

int my_isdigit(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return 1;
    }
    return 0;
}

int my_islower(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return 1;
    }
    return 0;
}

int my_isupper(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return 1;
    }
    return 0;
}

char my_tolower(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    return ch + ('a' - 'A');
}

char my_toupper(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return ch;
    }
    return ch - ('a' - 'A');
}

size_t my_strlen(char* str)
{
    size_t count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    return count;
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

char* my_strcpy(char* from, char* to)
{
    // int i;
    for (int i = 0; i <= my_strlen(from); i++) {
        to[i] = from[i];
    }
    // to[i] = '\0';
    return to;
}

int my_strcmp(char* str1, char* str2) {
    while (*str1 == *str2) {
        if ((*str1 == '\0') && (*str2 == '\0')) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 < *str2 ? -1: 1;
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

int my_suntok(char* str, char symbol, char** ptr, int num)
{
    for (int i = 1; i < num; i++) {
        *(ptr[i] - 1) = symbol;
    }
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

int my_cspn(char* str, char* set)
{
    int i, j;
    for (i = 0; i < my_strlen(str); i++){
        for (j = 0; j < my_strlen(set); j++) {
            if (str[i] == set[j]) {
                return i + 1;
            }
        }
    }
    return 0;
}