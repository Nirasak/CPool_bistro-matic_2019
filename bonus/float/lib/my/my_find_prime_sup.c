/*
** EPITECH PROJECT, 2019
** my_find_prime_suo
** File description:
** find_prime_sup
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        nb = 2;
    if (my_is_prime(nb) == 0)
        nb = my_find_prime_sup(nb + 1);
    return (nb);
}
