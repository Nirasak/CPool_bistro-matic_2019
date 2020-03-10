/*
** EPITECH PROJECT, 2019
** expr_utils3
** File description:
** utils3 for eval_expr
*/

#include "bistromatic.h"

int is_op_ultra_high(char const *ops, char c)
{
    return (
        c == ops[OP_POW_IDX]
    );
}

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
