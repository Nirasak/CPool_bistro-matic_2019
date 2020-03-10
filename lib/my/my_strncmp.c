/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** strncmp
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n < 1)
        return (0);
    while (--n > 0 && *s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
