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

int init_invalid_syntax_checking(char * const *av, char const *str)
{
    expr_t expr = {my_strlen(av[1]), av[1], av[2], str};

    return (invalid_syntax_checking(&expr));
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_operator_in_base
)
{
    char *av[3] = {"./calc", "0123456*89", "()+-*/%"};
    char *expr = my_strdup("64+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_identical_digit
)
{
    char *av[3] = {"./calc", "0123456709", "()+-*/%"};
    char *expr = my_strdup("64+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_two_identical_operators
)
{
    char *av[3] = {"./calc", "0123456789", "()*-*/%"};
    char *expr = my_strdup("4+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_unmatched_parenthesis_1
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+2)");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_unmatched_parenthesis_2
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("(4+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_invalid_expression_1
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+*2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_invalid_expression_2
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+ 2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_unknown_digit
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4a+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 1);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_correct_1
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+2");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 0);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_correct_2
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("-(62+++53-5*(+--+-3))");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 0);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_correct_3
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4+2++5-57+123%42-153/1");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 0);
}

Test(
    invalid_syntax_checking,
    test_invalid_syntax_checking_correct_4
)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("((((((((((((((12)+3)*4)-5)%2)-6)*3)/1)*10))))))");

    cr_assert_eq(init_invalid_syntax_checking(av, expr), 0);
}
