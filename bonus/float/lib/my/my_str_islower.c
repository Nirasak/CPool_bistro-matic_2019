/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z')
            str++;
        else
            return (0);
    }
    return (1);
}
