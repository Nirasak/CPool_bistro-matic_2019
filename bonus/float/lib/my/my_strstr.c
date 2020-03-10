/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** strstr
*/
#include <stdlib.h>
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    if (*to_find == '\0')
        return (str);
    while (*str != '\0') {
        if (*str == *to_find && is_same(str, to_find))
            break;
        str++;
    }
    if (*str == '\0')
        return (NULL);
    return (str);
}

int is_same(char *str, char const *to_find)
{
    while (*str == *to_find && *to_find != '\0') {
        str++;
        to_find++;
    }
    return (*to_find == '\0');
}
