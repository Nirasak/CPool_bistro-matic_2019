/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** show_word_array
*/

#include <stdlib.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    if (tab == NULL)
        return (84);
    while (*tab != 0) {
        my_putstr(*tab);
        my_putchar('\n');
        tab++;
    }
    return (0);
}
