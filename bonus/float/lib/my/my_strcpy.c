/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** strcpy
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return (dest);
}
