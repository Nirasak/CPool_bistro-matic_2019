/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** strupcase
*/
#include "my.h"

char *my_strupcase(char *str)
{
    int index = -1;

    while (str[++index] != '\0') {
        if (str[index] >= 'a' && str[index] <= 'z')
            str[index] -= 32;
    }
    return (str);
}
