/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** strncpy
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    int index = -1;

    while (++index < n && *src != '\0')
        dest[index] = src[index];
    if (n > len)
        dest[index] = '\0';
    return (dest);
}
