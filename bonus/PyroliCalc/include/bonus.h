/*
** EPITECH PROJECT, 2019
** bonus.h
** File description:
** bonus.h
*/

#ifndef BONUS_H_
#define BONUS_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include "bistromatic.h"

#define SIZE_FONT 50

typedef struct calc
{
    sfRenderWindow *wdw;
    int width;
    int height;
    sfTexture *t_ope;
    sfTexture *t_case;
    sfTexture *t_actu;
    sfTexture *t_click;
    sfSprite **s_case;
    sfSprite *s_actu;
    sfSprite *s_click;
    sfIntRect r_case;
    sfVector2f *p_case;
    sfVector2f p_actu;
    sfVector2f p_click;
    sfVector2f p_text;
    sfFont *font;
    sfText **t_font;
    sfText *text;
    char *str;
} calc_t;

int my_calc(void);
void create_window(calc_t *calc);
void set_sprites(calc_t *calc);
void set_font(calc_t *calc);
void events_calc(calc_t *calc, sfEvent event);
void init_struct(calc_t *calc);
char *replace_lt(char *str, char c, char z);
void events_calc_2(calc_t *calc, sfEvent event, int i);
void events_released(calc_t *calc, int i);
void events_released2(calc_t *calc, int i);
void events_released3(calc_t *calc, nb_t *result);
void init_struct2(calc_t *calc);
void display_calc(calc_t *calc);
void set_sprites2(calc_t *calc);
void set_pos_font(calc_t *calc);
void set_font2(calc_t *calc);
void set_string_in_text(sfText *txt, char *str, sfColor color, int size);

#endif /* !BONUS_H_ */
