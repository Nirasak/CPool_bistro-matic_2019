/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** str_isalpha
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    while (*str != '\0') {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
            str++;
        else
            return (0);
    }
    return (1);
}
