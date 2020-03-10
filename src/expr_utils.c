/*
** EPITECH PROJECT, 2019
** expr_utils
** File description:
** utils for eval_expr
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

int is_op_high(char const *ops, char c)
{
    return (
        c == ops[OP_MULT_IDX] ||
        c == ops[OP_DIV_IDX] ||
        c == ops[OP_MOD_IDX]
    );
}

int is_op_low(char const *ops, char c)
{
    return (
        c == ops[OP_PLUS_IDX] ||
        c == ops[OP_SUB_IDX]
    );
}

void do_high_op(expr_t *expr, nb_t *infin_nums[2], char op)
{
    nb_t tmp;

    if (op == expr->ops[OP_MULT_IDX]) {
        if (find_lowest(infin_nums, expr->base) == 1) {
            tmp = *infin_nums[0];
            *(infin_nums[0]) = *(infin_nums[1]);
            *(infin_nums[1]) = tmp;
        }
        infinmult(expr, infin_nums);
    }
    else {
        if (*(infin_nums[1]->nb) == '\0')
            invalid_op_exit(expr, infin_nums);
        if (op == expr->ops[OP_DIV_IDX])
            infindiv(expr, infin_nums);
        else
            infinmod(expr, infin_nums);
    }
    free(infin_nums[1]->nb);
}

void do_low_op(expr_t *expr, nb_t *infin_nums[2])
{
    nb_t tmp;

    if (find_lowest(infin_nums, expr->base) == 1) {
        tmp = *infin_nums[0];
        *(infin_nums[0]) = *(infin_nums[1]);
        *(infin_nums[1]) = tmp;
    }
    if (infin_nums[0]->sign + infin_nums[1]->sign != 0)
        infinadd(expr, infin_nums);
    else
        infinsub(expr, infin_nums);
    free(infin_nums[1]->nb);
}
