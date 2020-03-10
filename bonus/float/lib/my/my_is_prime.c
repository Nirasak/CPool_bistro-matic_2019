/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** is_prime
*/
#include "my.h"

int my_is_prime(int nb)
{
    int index = 2;

    if (nb < 2)
        return (0);
    if (nb == 2)
        return (1);
    while (index <= nb / index) {
        if (nb % index++ == 0)
            return (0);
    }
    return (1);
}
