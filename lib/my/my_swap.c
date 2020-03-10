/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap
*/
#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
