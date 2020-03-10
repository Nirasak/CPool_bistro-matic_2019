/*
** EPITECH PROJECT, 2019
** set_text.c
** File description:
** set text
*/

#include "bonus.h"

void set_string_in_text(sfText *txt, char *str, sfColor color, int size)
{
    sfText_setColor(txt, color);
    sfText_setString(txt, str);
    sfText_setCharacterSize(txt, size);
}

void set_font2(calc_t *calc)
{
    set_string_in_text(calc->t_font[0], "C", sfWhite, 55);
    set_string_in_text(calc->t_font[1], "<-", sfWhite, 50);
    set_string_in_text(calc->t_font[2], "%", sfWhite, 40);
    set_string_in_text(calc->t_font[3], "/", sfWhite, 35);
    set_string_in_text(calc->t_font[4], "9", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[5], "8", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[6], "7", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[7], "*", sfWhite, 45);
    set_string_in_text(calc->t_font[8], "6", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[9], "5", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[10], "4", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[11], "-", sfWhite, 60);
    set_string_in_text(calc->t_font[12], "3", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[13], "2", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[14], "1", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[15], "+", sfWhite, SIZE_FONT);
    set_string_in_text(calc->t_font[16], "O", sfBlack, SIZE_FONT);
    set_string_in_text(calc->t_font[17], "(", sfBlack, 40);
    set_string_in_text(calc->t_font[18], ")", sfBlack, 40);
    set_string_in_text(calc->t_font[19], "=", sfWhite, 45);
}

void set_pos_font(calc_t *calc)
{
    sfVector2f pos = {0, 0};

    pos.x = calc->p_case[0].x + calc->r_case.width / 3 + 5;
    pos.y = calc->p_case[0].y + calc->r_case.height / 4;
    sfText_setPosition(calc->t_font[0], pos);
    pos.x = calc->p_case[1].x + calc->r_case.width / 4 + 5;
    pos.y = calc->p_case[1].y + calc->r_case.height / 4;
    sfText_setPosition(calc->t_font[1], pos);
    pos.x = calc->p_case[11].x + calc->r_case.width / 5 * 2;
    pos.y = calc->p_case[11].y + calc->r_case.height / 5;
    sfText_setPosition(calc->t_font[11], pos);
}

void set_font(calc_t *calc)
{
    sfVector2f pos = {0, 0};

    sfText_setFont(calc->text, calc->font);
    calc->p_text.x = 520;
    calc->p_text.y = 80;
    sfText_setPosition(calc->text, calc->p_text);
    set_string_in_text(calc->text, calc->str, sfWhite, 100);
    for (int i = 0; i < 20; i++) {
        calc->t_font[i] = sfText_create();
        sfText_setFont(calc->t_font[i], calc->font);
        pos.x = calc->p_case[i].x + calc->r_case.width / 5 * 2;
        pos.y = calc->p_case[i].y + calc->r_case.height / 3;
        sfText_setPosition(calc->t_font[i], pos);
    }
    set_font2(calc);
    set_pos_font(calc);
}
