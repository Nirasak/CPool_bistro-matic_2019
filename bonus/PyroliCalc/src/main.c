/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "bonus.h"

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return (84);
    if (ac != 1 && av[1] != NULL)
        return (84);
    my_calc();
    return (0);
}
