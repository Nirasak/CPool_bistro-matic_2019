/*
** EPITECH PROJECT, 2019
** infinadd
** File description:
** infinite add
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static unsigned char add_floating_loop(expr_t *expr, nb_t *infin_nums[2])
{
    char *nb[2] = {
        infin_nums[0]->floating_point, infin_nums[1]->floating_point
    };
    char const *base = expr->base;
    unsigned int base_size = expr->base_size;
    unsigned int tmp = 0;

    for (unsigned int index = FLOAT_PRECISION; index != 0; ) {
        --index;
        tmp += get_index_base(nb[0][index], base)
            + get_index_base(nb[1][index], base);
        nb[0][index] = base[tmp % base_size];
        tmp /= base_size;
    }
    return (tmp);
}

static unsigned char add_loop(expr_t *expr, nb_t *infin_nums[2], char *result)
{
    unsigned int tmp = add_floating_loop(expr, infin_nums);
    unsigned int base_size = expr->base_size;
    char *nb[2] = {infin_nums[0]->nb, infin_nums[1]->nb};
    char const *base = expr->base;

    for (unsigned int index = infin_nums[0]->len, index2 = infin_nums[1]->len;
            index != 0; ) {
        tmp += get_index_base(nb[0][--index], base);
        if (index2 > 0)
            tmp += get_index_base(nb[1][--index2], base);
        *result++ = base[tmp % base_size];
        tmp /= base_size;
    }
    if (tmp != 0)
        *result++ = base[tmp % base_size];
    *result = '\0';
    return (tmp != 0);
}

void infinadd(expr_t *expr, nb_t *infin_nums[2])
{
    unsigned int nb_len = infin_nums[0]->len;
    char *result = malloc(sizeof(char) * (nb_len + 2));

    check_malloc(result);
    nb_len += add_loop(expr, infin_nums, result);
    my_revstr(result);
    free(infin_nums[0]->nb);
    infin_nums[0]->len = nb_len;
    infin_nums[0]->nb = result;
}
