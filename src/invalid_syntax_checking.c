/*
** EPITECH PROJECT, 2019
** invalid_syntax_checking
** File description:
** check if expr is valid
*/

#include "bistromatic.h"

static int is_next_is_bad_op(char const *expr, char const *ops)
{
    if (*expr != ops[OP_CLOSE_PARENT_IDX]) {
        if ((c_in_str(*(expr + 1), ops) == 1 &&
            *(expr + 1) != ops[OP_PLUS_IDX] &&
            *(expr + 1) != ops[OP_SUB_IDX] &&
            *(expr + 1) != ops[OP_OPEN_PARENT_IDX]))
            return (1);
    } else if (*(expr + 1) == ops[OP_OPEN_PARENT_IDX])
        return (1);
    return (0);
}

static int check_braces(int *braces_count, char const *ops, char c)
{
    if (c == ops[OP_OPEN_PARENT_IDX])
        (*braces_count)++;
    else if (c == ops[OP_CLOSE_PARENT_IDX])
        (*braces_count)--;
    return (*braces_count < 0);
}

static int op_in_base(char const *ops, char const *base)
{
    char const *tmp = ops;

    while (*tmp != '\0') {
        if (c_in_str(*tmp, tmp + 1) == 1)
            return (1);
        tmp++;
    }
    tmp = base;
    while (*tmp != '\0') {
        if (c_in_str(*tmp, tmp + 1) == 1)
            return (1);
        tmp++;
    }
    while (*ops != '\0') {
        if (c_in_str(*ops++, base) == 1)
            return (1);
    }
    return (0);
}

static int check_end_syntax(char const *expr, char const *base, char const *ops)
{
    return (
        c_in_str(*(expr - 1), base) == 0 &&
        *(expr - 1) != ops[OP_CLOSE_PARENT_IDX]
    );
}

int invalid_syntax_checking(expr_t *expr)
{
    char const *ops = expr->ops;
    char const *base = expr->base;
    char const *xpr = expr->expr;
    int braces_count = 0;

    if (op_in_base(ops, base) == 1)
        return (1);
    for (unsigned int is_in_base = 0, is_in_ops = 0; *xpr != '\0'; ) {
        is_in_base = c_in_str(*xpr, base);
        is_in_ops = c_in_str(*xpr, ops);
        if ((is_in_base == 0 && is_in_ops == 0) ||
            (check_braces(&braces_count, ops, *xpr) == 1) ||
            (is_in_ops == 1 && is_next_is_bad_op(xpr, ops) == 1) ||
            (*xpr == ops[OP_CLOSE_PARENT_IDX] && c_in_str(*(xpr + 1), base)) ||
            (c_in_str(*(xpr), base) && *(xpr + 1) == ops[OP_OPEN_PARENT_IDX]))
            return (1);
        xpr++;
    }
    return (braces_count != 0 || check_end_syntax(xpr, base, ops));
}
