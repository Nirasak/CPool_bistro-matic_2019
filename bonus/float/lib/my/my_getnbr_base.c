/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** getnbr_base
*/
#include "my.h"

int my_getnbr_base(char const *str, char const *base)
{
    int neg = 1;

    while (char_in_base(*str, base) == -1) {
        if (*str != '-' && *str != '+')
            return (0);
        if (*str == '-')
            neg *= -1;
        str++;
    }
    return (calc_number_base(str, base, neg, neg));
}

int calc_number_base(char const *str, char const *base, int nb, int neg)
{
    int isneg = 0;
    int base_n = my_strlen(base);

    if (neg == -1)
        isneg = 1;
    nb *= char_in_base(*str++, base);
    while (char_in_base(*str, base) > -1 && *str != '\0') {
        if (neg * nb >= 214748264 && char_in_base(*str, base) > (7 + isneg)) {
            nb = 0;
            break;
        }
        nb = nb * base_n + neg * char_in_base(*str++, base);
    }
    return (nb);
}

int char_in_base(char c, char const *base)
{
    int index = -1;

    while (base[++index] != '\0') {
        if (c == base[index])
            return (index);
    }
    return (-1);
}
