/*
** EPITECH PROJECT, 2019
** infinsub
** File description:
** infinite sub
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static unsigned int sub_floating_loop(expr_t *expr, nb_t *infin_nums[2])
{
    char *nb[2] = {
        infin_nums[0]->floating_point, infin_nums[1]->floating_point
    };
    char const *base = expr->base;
    unsigned int base_size = expr->base_size;
    int tmp = 0;

    for (unsigned int index = FLOAT_PRECISION, retenue; index != 0; ) {
        --index;
        tmp += get_index_base(nb[0][index], base)
            - get_index_base(nb[1][index], base);
        retenue = tmp < 0 ? 1 : 0;
        tmp += tmp < 0 ? base_size : 0;
        nb[0][index] = base[tmp];
        tmp = tmp / base_size - retenue;
    }
    return (tmp);
}

static unsigned int sub_loop(expr_t *expr, nb_t *infin_nums[2], char *result)
{
    int tmp = sub_floating_loop(expr, infin_nums);
    char *nb[2] = {infin_nums[0]->nb, infin_nums[1]->nb};
    char const *base = expr->base;
    char *temp = result;
    unsigned int base_size = expr->base_size;

    for (unsigned int index = infin_nums[0]->len, index2 = infin_nums[1]->len,
            retenue; index != 0; ) {
        tmp += get_index_base(nb[0][--index], base);
        if (index2 > 0)
            tmp -= get_index_base(nb[1][--index2], base);
        retenue = tmp < 0 ? 1 : 0;
        tmp += tmp < 0 ? base_size : 0;
        *result++ = base[tmp];
        tmp = tmp / base_size - retenue;
    }
    while (result > temp && *(result - 1) == expr->base[0])
        result--;
    *result = '\0';
    return (result - temp);
}

void infinsub(expr_t *expr, nb_t *infin_nums[2])
{
    char *result = malloc(sizeof(char) * (infin_nums[0]->len + 1));

    check_malloc(result);
    infin_nums[0]->len = sub_loop(expr, infin_nums, result);
    my_revstr(result);
    free(infin_nums[0]->nb);
    infin_nums[0]->nb = result;
}
