/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** strlowcase
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int index = -1;

    while (str[++index] != '\0') {
        if (str[index] >= 'A' && str[index] <= 'Z')
            str[index] += 32;
    }
    return (str);
}
