/*
** EPITECH PROJECT, 2019
** get_number.c
** File description:
** get_number
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static void put_float_in_infin_nb(expr_t *expression, nb_t *infin_nb)
{
    char const *expr = expression->expr;
    char *nb = malloc(sizeof(char) * (FLOAT_PRECISION + 1));
    unsigned int nb_len = get_nb_size(expression);
    unsigned int total = 0;

    check_malloc(nb);
    infin_nb->floating_point = nb;
    while (total < nb_len && total < FLOAT_PRECISION) {
        *nb++ = *expr++;
        total++;
    }
    while (total++ < FLOAT_PRECISION) {
        *nb++ = expression->base[0];
    }
    *nb = '\0';
    expression->expr += nb_len;
}

static void put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg)
{
    char const *expr = expression->expr;
    unsigned int nb_len = get_nb_size(expression);
    char *nb = malloc(sizeof(char) * (nb_len + 1));

    check_malloc(nb);
    infin_nb->sign = isneg;
    infin_nb->len = nb_len;
    infin_nb->nb = nb;
    while (nb_len--)
        *nb++ = *expr++;
    *nb = '\0';
    expression->expr = expr + (*expr == '.');
    put_float_in_infin_nb(expression, infin_nb);
}

void get_number(expr_t *expr, nb_t *infin_nb)
{
    signed char isneg = 1;

    while (c_in_str(*(expr->expr), expr->base) == 0 &&
        *(expr->expr) != expr->ops[OP_OPEN_PARENT_IDX]) {
        if (*(expr->expr)++ == expr->ops[OP_NEG_IDX])
            isneg *= -1;
    }
    if (*(expr->expr) == expr->ops[OP_OPEN_PARENT_IDX]) {
        (expr->expr)++;
        *infin_nb = *sum(expr);
        (expr->expr)++;
        infin_nb->sign *= isneg;
        infin_nb->len = my_strlen(infin_nb->nb);
    } else
        put_nbr_in_infin_nb(expr, infin_nb, isneg);
}
