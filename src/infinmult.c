/*
** EPITECH PROJECT, 2019
** infinmult
** File description:
** infinite mult
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static unsigned int mult_loop(expr_t *expr, nb_t *infin_nums[2], char *res)
{
    char *nb[2] = {infin_nums[0]->nb, infin_nums[1]->nb};
    char const *base = expr->base;
    unsigned int len[2] = {infin_nums[0]->len, infin_nums[1]->len};
    unsigned int base_size = expr->base_size;
    unsigned int k;

    for (unsigned int i = len[0], tmp = 0; i != 0; ) {
        k = len[0] - i--;
        for (unsigned int j = len[1]; j != 0; ) {
            tmp += get_index_base(nb[0][i], base) *
                get_index_base(nb[1][--j], base) + get_index_base(res[k], base);
            res[k++] = base[tmp % base_size];
            tmp /= base_size;
        }
        if (tmp != 0) {
            res[k++] = base[tmp % base_size];
            tmp = 0;
        }
    }
    res[k] = '\0';
    return (k);
}

void infinmult(expr_t *expr, nb_t *infin_nbs[2])
{
    char *result = NULL;
    unsigned int len = infin_nbs[0]->len + infin_nbs[1]->len;

    result = malloc(sizeof(char) * (len + 1));
    check_malloc(result);
    my_memset(result, len, expr->base[0]);
    len = mult_loop(expr, infin_nbs, result);
    my_revstr(result);
    free(infin_nbs[0]->nb);
    infin_nbs[0]->nb = result;
    infin_nbs[0]->len = len;
    infin_nbs[0]->sign = infin_nbs[0]->sign + infin_nbs[1]->sign == 0 ? -1 : 1;
}
