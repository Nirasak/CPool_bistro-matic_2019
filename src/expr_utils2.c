/*
** EPITECH PROJECT, 2019
** expr_utils2
** File description:
** utils2 for eval_expr
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void check_malloc(void *item)
{
    if (item == NULL) {
        write(2, ERROR_MSG, 5);
        exit(EXIT_MALLOC);
    }
}

void invalid_op_exit(expr_t *expr, nb_t *infin_nums[2])
{
    free(infin_nums[0]->nb);
    free(infin_nums[1]->nb);
    free(infin_nums[0]);
    free(infin_nums[1]);
    free(expr);
    write(2, SYNTAX_ERROR_MSG, 12);
    exit(EXIT_SYNTAX_ERROR);
}

int c_in_str(char c, char const *str)
{
    while (*str != '\0' && c != *str)
        str++;
    return (*str != '\0');
}

unsigned int get_nb_size(expr_t *expr)
{
    char const *expression = expr->expr;
    char const *base = expr->base;
    unsigned int size = 0;

    while (*expression == base[0])
        expression++;
    expr->expr = expression;
    while (c_in_str(*expression++, base) == 1)
        size++;
    return (size);
}
