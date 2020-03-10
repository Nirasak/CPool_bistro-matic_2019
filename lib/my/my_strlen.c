/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** str_len
*/

int my_strlen(char const *str)
{
    char const *tmp = str;

    while (*tmp)
        tmp++;
    return (tmp - str);
}
