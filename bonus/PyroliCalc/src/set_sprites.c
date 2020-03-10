/*
** EPITECH PROJECT, 2019
** create_sprites.c
** File description:
** create sprites
*/

#include "bonus.h"

void set_sprites2(calc_t *calc)
{
    sfIntRect rect = {0, 0, 0, 0};

    calc->p_actu.x = -500;
    calc->p_actu.y = -500;
    calc->p_click.x = -500;
    calc->p_click.y = -500;
    sfSprite_setTexture(calc->s_click, calc->t_click, sfTrue);
    sfSprite_setPosition(calc->s_click, calc->p_click);
    sfSprite_setTextureRect(calc->s_click, rect);
    sfSprite_setTexture(calc->s_actu, calc->t_actu, sfTrue);
    sfSprite_setPosition(calc->s_actu, calc->p_actu);
    sfSprite_setTextureRect(calc->s_actu, calc->r_case);
    sfSprite_setTexture(calc->s_case[19], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[15], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[11], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[7], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[3], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[2], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[1], calc->t_ope, sfTrue);
    sfSprite_setTexture(calc->s_case[0], calc->t_ope, sfTrue);
}

void set_sprites(calc_t *calc)
{
    int pos_x = 450;
    int pos_y = 700;

    for (int i = 19; i >= 0; i--) {
        calc->s_case[i] = sfSprite_create();
        calc->p_case[i].x = pos_x;
        calc->p_case[i].y = pos_y;
        pos_x -= 150;
        if (pos_x < 0) {
            pos_x = 450;
            pos_y -= 124;
        }
        sfSprite_setTexture(calc->s_case[i], calc->t_case, sfTrue);
        sfSprite_setPosition(calc->s_case[i], calc->p_case[i]);
        sfSprite_setTextureRect(calc->s_case[i], calc->r_case);
    }
    set_sprites2(calc);
}
