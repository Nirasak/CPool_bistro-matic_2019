/*
** EPITECH PROJECT, 2019
** events_calc.c
** File description:
** events calc
*/

#include <stddef.h>
#include "bonus.h"
#include "bistromatic.h"
#include "my.h"

void events_released3(calc_t *calc, nb_t *result)
{
    if (result == NULL)
        my_strcpy(calc->str, "ERROR");
    else if (result->nb[0] == '\0') {
        calc->str[0] = '0';
        calc->str[1] = '\0';
    } else {
        if (result->sign == -1)
            calc->str[0] = '-';
        my_strcpy(calc->str + (result->sign == -1), result->nb);
    }
    replace_lt(calc->str, '0', 'O');
    calc->p_text.x = 520 - (my_strlen(calc->str) - 1) * 59;
}

void events_released2(calc_t *calc, int i)
{
    if (i == 1 && sfText_getString(calc->t_font[i])[0] != 'O') {
        calc->str[my_strlen(calc->str) - 1] = '\0';
        calc->p_text.x += 59;
        if (my_strlen(calc->str) == 0) {
            calc->str[0] = 'O';
            calc->str[1] = '\0';
            calc->p_text.x = 520;
        }
    }
    if (i == 19) {
        events_released3(
            calc, eval_expr(
                "0123456789",
                "()+-*/%", replace_lt(calc->str, 'O', '0')
            )
        );
    }
}

void events_released(calc_t *calc, int i)
{
    if ((my_strcmp(calc->str, "O") == 0
        || my_strcmp(calc->str, "ERROR") == 0) && i > 1 && i != 19) {
        my_strcpy(calc->str, sfText_getString(calc->t_font[i]));
        calc->p_text.x = 520;
    } else if (i > 1 && i != 19) {
        my_strcat(calc->str, sfText_getString(calc->t_font[i]));
        calc->p_text.x -= 59;
    }
    if (i == 0) {
        calc->str[0] = 'O';
        calc->str[1] = '\0';
        calc->p_text.x = 520;
        sfText_setPosition(calc->text, calc->p_text);
    }
    events_released2(calc, i);
    sfText_setPosition(calc->text, calc->p_text);
    sfText_setString(calc->text, calc->str);
}

void events_calc_2(calc_t *calc, sfEvent event, int i)
{
    sfIntRect rect = {0, 0, 0, 0};

    calc->p_actu.x = calc->p_case[i].x;
    calc->p_actu.y = calc->p_case[i].y;
    calc->p_click.x = calc->p_case[i].x;
    calc->p_click.y = calc->p_case[i].y;
    if (event.type == sfEvtMouseButtonPressed) {
        sfSprite_setTextureRect(calc->s_click, calc->r_case);
    } else if (event.type == sfEvtMouseButtonReleased) {
        sfSprite_setTextureRect(calc->s_click, rect);
        events_released(calc, i);
    }
}

void events_calc(calc_t *calc, sfEvent event)
{
    sfVector2i p_mouse = sfMouse_getPositionRenderWindow(calc->wdw);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(calc->wdw);
    calc->p_actu.x = -500;
    calc->p_actu.y = -500;
    for (int i = 0; i < 20; i++) {
        if ((p_mouse.x >= calc->p_case[i].x)
            && (p_mouse.x <= calc->p_case[i].x + calc->r_case.width)
            && (p_mouse.y >= calc->p_case[i].y)
            && (p_mouse.y <= calc->p_case[i].y + calc->r_case.height))
            events_calc_2(calc, event, i);
    }
    sfSprite_setPosition(calc->s_actu, calc->p_actu);
    sfSprite_setPosition(calc->s_click, calc->p_click);
}
