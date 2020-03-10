/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** str_isprintable
*/
#include "my.h"

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (*str > 31)
            str++;
        else
            return (0);
    }
    return (1);
}
