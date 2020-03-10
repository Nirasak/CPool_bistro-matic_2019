/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** str_isnum
*/
#include "my.h"

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9')
            str++;
        else
            return (0);
    }
    return (1);
}
