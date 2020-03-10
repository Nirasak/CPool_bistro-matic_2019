/*
** EPITECH PROJECT, 2019
** init_struct.c
** File description:
** init struct
*/

#include <stdlib.h>
#include "bonus.h"

void init_struct2(calc_t *calc)
{
    calc->t_case = sfTexture_createFromFile("case.png", NULL);
    calc->t_ope = sfTexture_createFromFile("ope.png", NULL);
    calc->t_actu = sfTexture_createFromFile("actual.png", NULL);
    calc->t_click = sfTexture_createFromFile("click.png", NULL);
    calc->font = sfFont_createFromFile("Instruction.otf");
    calc->s_click = sfSprite_create();
    calc->s_actu = sfSprite_create();
    calc->text = sfText_create();
}

void init_struct(calc_t *calc)
{
    calc->width = 600;
    calc->height = 825;
    calc->str = malloc(sizeof(char) * 512);
    calc->s_case = malloc(sizeof(sfSprite *) * 21);
    calc->p_case = malloc(sizeof(sfVector2f) * 21);
    calc->t_font = malloc(sizeof(sfText *) * 21);
    calc->str[0] = 'O';
    calc->str[1] = '\0';
    calc->r_case.top = 0;
    calc->r_case.left = 0;
    calc->r_case.width = 150;
    calc->r_case.height = 124;
    calc->s_case[20] = NULL;
    calc->t_font[20] = NULL;
    calc->p_case[20].x = 0;
    calc->p_case[20].y = 0;
    init_struct2(calc);
}
