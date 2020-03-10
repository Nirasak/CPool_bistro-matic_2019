/*
** EPITECH PROJECT, 2019
** create_my_window.c
** File description:
** create window
*/

#include "bonus.h"

void create_window(calc_t *calc)
{
    sfVideoMode vm = {calc->width, calc->height, 32};

    calc->wdw = sfRenderWindow_create(vm, "my_calc", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(calc->wdw, 60);
    sfRenderWindow_setVerticalSyncEnabled(calc->wdw, sfTrue);
}
