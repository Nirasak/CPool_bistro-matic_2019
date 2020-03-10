/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** eval_expr
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static nb_t *sum(expr_t *expr);

static void put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg)
{
    unsigned int nb_len = get_nb_size(expression);
    char const *expr = expression->expr;
    char *nb = malloc(sizeof(char) * (nb_len + 1));

    check_malloc(nb);
    infin_nb->sign = isneg;
    infin_nb->len = nb_len;
    infin_nb->nb = nb;
    while (nb_len--)
        *nb++ = *expr++;
    *nb = '\0';
    expression->expr = expr;
}

static void get_number(expr_t *expr, nb_t *infin_nb)
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

static void product(expr_t *expr, nb_t *infin_nb)
{
    nb_t *infin_nums[2] = {infin_nb, malloc(sizeof(nb_t))};
    char op;

    check_malloc(infin_nums[1]);
    get_number(expr, infin_nums[0]);
    if (*(expr->expr) =='\0')
        return;
    op = *(expr->expr);
    while (is_op_high(expr->ops, op) == 1) {
        expr->expr++;
        get_number(expr, infin_nums[1]);
        do_high_op(expr, infin_nums, op);
        op = *(expr->expr);
    }
    free(infin_nums[1]);
}

static nb_t *sum(expr_t *expr)
{
    nb_t *infin_nums[2] = {malloc(sizeof(nb_t)), malloc(sizeof(nb_t))};

    check_malloc(infin_nums[0]);
    check_malloc(infin_nums[1]);
    product(expr, infin_nums[0]);
    while (is_op_low(expr->ops, *(expr->expr)) == 1) {
        product(expr, infin_nums[1]);
        do_low_op(expr, infin_nums);
    }
    free(infin_nums[1]);
    return (infin_nums[0]);
}

nb_t *eval_expr(char const *base, char const *ops, char const *expr)
{
    expr_t *expression = malloc(sizeof(expr_t));
    nb_t *result = NULL;

    check_malloc(expression);
    expression->base = base;
    expression->ops = ops;
    expression->expr = expr;
    expression->base_size = my_strlen(base);
    if (*expr != '\0' && invalid_syntax_checking(expression) == 0)
        result = sum(expression);
    free(expression);
    return (result);
}
