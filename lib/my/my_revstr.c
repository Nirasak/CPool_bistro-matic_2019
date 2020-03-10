/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int modifier_index = 0;
    int len_str = my_strlen(str);
    char temp_char;

    while (len_str-- > modifier_index) {
        temp_char = str[modifier_index];
        str[modifier_index++] = str[len_str];
        str[len_str] = temp_char;
    }
    return (str);
}
