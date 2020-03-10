/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** putstr
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int length = my_strlen(str);

    write(1, str, length);
    return (0);
}
