/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** putnbr
*/
#include "my.h"

int set_base(int nb)
{
    int base = 1;

    if (nb < 0) {
        my_putchar('-');
        while (base * -1 >= nb / 10)
            base *= 10;
    } else {
        while (base <= nb / 10)
            base *= 10;
    }
    return (base);
}

int my_put_nbr(int nb)
{
    int base;
    char char_to_print;

    base = set_base(nb);
    while (base >= 1) {
        char_to_print = nb / base % 10;
        if (char_to_print < 0)
            char_to_print *= -1;
        base /= 10;
        my_putchar(char_to_print + '0');
    }
    return (0);
}
