/*
** EPITECH PROJECT, 2019
** my_showstr
** File description:
** showstr
*/
#include "my.h"

int my_showstr(char const *str)
{
    while (*str != '\0') {
        if (*str < 32)
            put_hexa_char(*str);
        else
            my_putchar(*str);
        str++;
    }
    return (0);
}

void put_hexa_char(char c)
{
    my_putchar('\\');
    my_putchar(c / 16 + '0');
    if (c % 16 > 9)
        my_putchar(c % 16 - 10 + 'a');
    else
        my_putchar(c % 16 + '0');
}
