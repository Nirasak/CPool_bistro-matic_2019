/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** strcapitalize
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    if (*str != '\0')
        capitalizer(str, 1);
    return (str);
}

void capitalizer(char *str, int is_new_word)
{
    if (*str == '\0')
        return;
    if (is_new_word == 1) {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        is_new_word = 0;
    } else if (is_new_word == 0 && *str >= 'A' && *str <= 'Z')
        *str += 32;
    is_new_word = 0;
    str++;
    while (check_is_new_word(*str) == 1) {
        str++;
        is_new_word = 1;
    }
    capitalizer(str, is_new_word);
}

int check_is_new_word(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    if ((c >= '0' && c <= '9') || c == '\0')
        return (0);
    return (1);
}
