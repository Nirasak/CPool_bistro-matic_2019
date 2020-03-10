/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** putnbr_base
*/
#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_n = my_strlen(base);
    int index = 1;
    int copy_nbr = nbr;

    if (nbr < 0)
        my_putchar('-');
    if (nbr == 0)
        my_putchar('0');
    while (copy_nbr >= 1 || copy_nbr <= -1) {
        copy_nbr /= base_n;
        index++;
    }
    put_nbr_base(base, index, base_n, nbr);
    return (0);
}

void put_nbr_base(char const *base, int index, int base_n, int nbr)
{
    int temp;
    int temp2;

    while (index > 1) {
        temp = power_n(base_n, --index);
        temp2 = make_even((nbr / temp) % base_n);
        my_putchar(base[temp2]);
        if (temp2 != 0)
            nbr -= temp;
    }
}

int power_n(int base, int n)
{
    int nb = 1;

    while (--n > 0)
        nb *= base;
    return (nb);
}

int make_even(int nb)
{
    if (nb < 0)
        nb *= -1;
    return (nb);
}
