/*
** EPITECH PROJECT, 2019
** test_eval_expr_error.c
** File description:
** test eval_expr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

void redirect_stdout(void);
void redirect_stderr(void);
int init_eval_expr(char **av, char *expr);

Test(eval_expr, test_eval_expr_error_multi_op, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "*++*/*"};
    char *expr = my_strdup("12");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_no_op_between_parent, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("(12+12)(2)");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_no_op_between_parent_nb, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("(12+12)2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_no_op_between_parent_2, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("2(12+12)");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_end_with_op, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("12+");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}
