/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** compute_square_root
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int ans = 1;

    while (ans * ans < nb)
        ans++;
    if (ans * ans != nb)
        ans = 0;
    return (ans);
}
