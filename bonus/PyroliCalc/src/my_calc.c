/*
** EPITECH PROJECT, 2019
** my_calc.c
** File description:
** my calc
*/

#include <stddef.h>
#include <stdlib.h>
#include "bonus.h"
#include "my.h"
#include "bistromatic.h"

char *replace_lt(char *str, char c, char z)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            str[i] = z;
    }
    return (str);
}

void display_calc(calc_t *calc)
{
    for (int i = 0; i < 20; i++) {
        sfRenderWindow_drawSprite(calc->wdw, calc->s_case[i], NULL);
        sfRenderWindow_drawText(calc->wdw, calc->t_font[i], NULL);
    }
    sfRenderWindow_drawSprite(calc->wdw, calc->s_actu, NULL);
    sfRenderWindow_drawSprite(calc->wdw, calc->s_click, NULL);
    sfRenderWindow_drawText(calc->wdw, calc->text, NULL);
}

int my_calc(void)
{
    calc_t *calc = malloc(sizeof(calc_t));
    sfEvent event;

    init_struct(calc);
    create_window(calc);
    set_sprites(calc);
    set_font(calc);
    while (sfRenderWindow_isOpen(calc->wdw)) {
        sfRenderWindow_clear(calc->wdw, sfBlack);
        while (sfRenderWindow_pollEvent(calc->wdw, &event))
            events_calc(calc, event);
        display_calc(calc);
        sfRenderWindow_display(calc->wdw);
    }
    free(calc);
    return (0);
}
