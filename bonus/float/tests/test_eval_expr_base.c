/*
** EPITECH PROJECT, 2019
** test_eval_expr_base.c
** File description:
** test eval_expr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

void redirect_stdout(void);
int init_eval_expr(char **av, char *expr);

Test(eval_expr, test_eval_expr_binary_base, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "01", "()+-*/%"};
    char *expr = my_strdup("10101*10");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("101010");
}

Test(eval_expr, test_eval_expr_hexa_base, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789abcdef", "()+-*/%"};
    char *expr = my_strdup("ab+cd");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("178");
}

Test(eval_expr, test_eval_expr_custom_base, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0A@!;ie& ]", "()+-*/%"};
    char *expr = my_strdup("-(e@-(;*!@))");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("ee");
}

Test(eval_expr, test_eval_expr_custom_operators, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789abcdef", "*)+-(/%"};
    char *expr = my_strdup("5(10");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("50");
}

Test(eval_expr, test_eval_expr_mixed, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "812p456709", "()+3*/%"};
    char *expr = my_strdup("777777777377777777777");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-77888888888");
}
