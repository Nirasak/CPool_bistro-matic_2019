/*
** EPITECH PROJECT, 2019
** test_eval_expr_error2.c
** File description:
** test eval_expr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

void redirect_stderr(void);
int init_eval_expr(char **av, char *expr);

Test(eval_expr, test_eval_expr_operator_in_base, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456*89", "()+-*/%"};
    char *expr = my_strdup("64+2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_two_identical_digit, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456709", "()+-*/%"};
    char *expr = my_strdup("64+2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_two_identical_operators, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()*-*/%"};
    char *expr = my_strdup("4+2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_unmatched_parenthesis_1, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+2)");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_unmatched_parenthesis_2, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("(4+2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_invalid_expression_1, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+*2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_invalid_expression_2, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+ 2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_empty_expression, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_unknown_digit, .init = redirect_stderr)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4a+2");

    init_eval_expr(av, expr);
    cr_assert_stderr_eq_str("syntax error");
}

Test(eval_expr, test_eval_expr_div_by_0, .init = redirect_stderr,
    .exit_code = 84)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42/0");

    init_eval_expr(av, expr);
}

Test(eval_expr, test_eval_expr_mod_by_0, .init = redirect_stderr,
    .exit_code = 84)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42%0");

    init_eval_expr(av, expr);
}
