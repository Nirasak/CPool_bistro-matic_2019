/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** str_isupper
*/
#include "my.h"

int my_str_isupper(char const *str)
{
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z')
            str++;
        else
            return (0);
    }
    return (1);
}
