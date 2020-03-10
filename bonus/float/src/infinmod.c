/*
** EPITECH PROJECT, 2019
** infinmod
** File description:
** infinite mod
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static void mod_loop_end(expr_t *expr, nb_t *infin_nums[2], char *str)
{
    char *stock = infin_nums[1]->nb;
    int i = my_strlen(str);
    int j = 0;

    infin_nums[1]->nb = str;
    infin_nums[1]->len = my_strlen(str);
    while (my_strcmp_custom(infin_nums[0]->nb, stock, expr->base) >= 0) {
        if (my_strcmp_custom(infin_nums[0]->nb, infin_nums[1]->nb, expr->base)
            >= 0) {
            infinsub(expr, infin_nums);
            j++;
        } else {
            infin_nums[1]->nb[--i] = '\0';
            infin_nums[1]->len--;
        }
    }
    free(stock);
}

static void mod_loop(expr_t *expr, nb_t *infin_nums[2])
{
    int len[2] = {infin_nums[0]->len, infin_nums[1]->len};
    char *str = malloc(sizeof(char) * (len[0] + 2));
    int i = 0;

    check_malloc(str);
    for (; i < len[0]; i++) {
        if (i >= len[1]) {
            str[i] = expr->base[0];
        } else
            str[i] = infin_nums[1]->nb[i];
    }
    str[i] = '\0';
    if (my_strcmp_custom(infin_nums[0]->nb, str, expr->base) < 0)
        str[i - 1] = '\0';
    mod_loop_end(expr, infin_nums, str);
}

void infinmod(expr_t *expr, nb_t *infin_nums[2])
{
    char final_sign;

    if (find_lowest(infin_nums, expr->base) == 0) {
        final_sign = infin_nums[0]->sign;
        mod_loop(expr, infin_nums);
        infin_nums[0]->sign = final_sign;
    }
}
