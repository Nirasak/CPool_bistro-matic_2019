/*
** EPITECH PROJECT, 2019
** check_eval_expr.c
** File description:
** check ops, base before calling eval_expr
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

char const *SYNTAX_ERROR_MSG = "syntax error";
char const *ERROR_MSG = "error";

static char *get_expr(int size)
{
    char *expr;

    if (size < 0) {
        write(2, ERROR_MSG, 5);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (size + 1));
    check_malloc(expr);
    if (read(0, expr, size) != size) {
        free(expr);
        write(2, ERROR_MSG, 5);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

static void check_base_and_ops(char const *base, char const *ops)
{
    if (my_strlen(base) < 2) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_BASE);
    }
    if (my_strlen(ops) != 9) {
        write(2, SYNTAX_ERROR_MSG, 13);
        exit(EXIT_OPS);
    }
}

static void check_argc(int ac)
{
    if (ac != 4) {
        write(
            2,
            "USAGE\n"
            "./calc base operators size_read\n\n"
            "DESCRIPTION\n"
            "- base: all the symbols of the base\n"
            "- operators: the symbols for the parentheses and"
                " the 7 operators\n"
            "- size_read: number of characters to be read\n",
            197
        );
        exit(EXIT_USAGE);
    }
}

static void put_answer(nb_t *ans, char c)
{
    if (*(ans->nb) == '\0') {
        if (ans->sign == -1 && diff_c_in_str(c, ans->floating_point))
            my_putchar('-');
        my_putchar(c);
    } else {
        if (ans->sign == -1)
            my_putchar('-');
        my_putstr(ans->nb);
    }
    if (diff_c_in_str(c, ans->floating_point)) {
        my_putchar('.');
        my_putstr(ans->floating_point);
    }
}

int check_eval_expr(int ac, char **av)
{
    int size;
    char *expr;
    nb_t *ans;

    check_argc(ac);
    check_base_and_ops(av[1], av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    ans = eval_expr(av[1], av[2], expr);
    free(expr);
    if (ans == NULL) {
        write(2, SYNTAX_ERROR_MSG, 12);
        return (EXIT_SYNTAX_ERROR);
    }
    put_answer(ans, av[1][0]);
    free(ans->nb);
    free(ans);
    return (EXIT_SUCCESS);
}
