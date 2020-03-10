/*
** EPITECH PROJECT, 2019
** test_eval_expr_sub.c
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

Test(eval_expr, test_eval_expr_sub_simple_positive, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42-21");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("21");
}

Test(eval_expr, test_eval_expr_sub_simple_negative_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("21-42");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-21");
}

Test(eval_expr, test_eval_expr_sub_simple_negative_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("-21-42");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-63");
}

Test(eval_expr, test_eval_expr_sub_size_handling_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("100-1");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("99");
}

Test(eval_expr, test_eval_expr_sub_size_handling_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("1-100");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-99");
}

Test(eval_expr, test_eval_expr_sub_size_handling_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("100-95");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("5");
}

Test(eval_expr, test_eval_expr_sub_with_remainder_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42-35");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("7");
}

Test(eval_expr, test_eval_expr_sub_with_remainder_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("35-42");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-7");
}

Test(eval_expr, test_eval_expr_sub_two_operators, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42--21");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("63");
}

Test(eval_expr, test_eval_expr_sub_big_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "1-99999999999999999999999999999999999999999999999999999999999"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "-99999999999999999999999999999999999999999999999999999999998"
    );
}

Test(eval_expr, test_eval_expr_sub_big_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-1-99999999999999999999999999999999999999999999999999999999999"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "-100000000000000000000000000000000000000000000000000000000000"
    );
}

Test(eval_expr, test_eval_expr_sub_big_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999999999999-1"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "99999999999999999999999999999999999999999999999999999999998"
    );
}

Test(eval_expr, test_eval_expr_sub_big_4, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "127648274120784612897452017846298426198451208746012946128745207146"
        "12098-1247606126412948126497124601298460129846208714112487652412785"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "127648274108308551633322536581327180185"
        "46660744755085898762033062199313"
    );
}
