/*
** EPITECH PROJECT, 2019
** test_infinsub.c
** File description:
** tests infinsub
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void test_put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg);
void test_get_number(expr_t *expr, nb_t *infin_nb);
nb_t *init_low_op(char * const *av, char const *str);

Test(infinsub, test_infinsub_simple_positive)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "42-21"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "21");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_simple_negative_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "21-42"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "21");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_simple_negative_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-21-42"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "63");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_size_handling_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "100-1"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "99");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_size_handling_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "1-100"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "99");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_size_handling_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "100-95"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "5");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_with_remainder_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42-35");
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "7");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_with_remainder_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("35-42");
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "7");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_two_operators)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("42--21");
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "63");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_big_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "1-99999999999999999999999999999999999999999999999999999999999"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "99999999999999999999999999999999999999999999999999999999998"
    );
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_big_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-1-99999999999999999999999999999999999999999999999999999999999"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "100000000000000000000000000000000000000000000000000000000000"
    );
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_big_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999999999999-1"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "99999999999999999999999999999999999999999999999999999999998"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinsub, test_infinsub_big_4)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "127648274120784612897452017846298426198451208746012946128745207146"
        "12098-1247606126412948126497124601298460129846208714112487652412785"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "127648274108308551633322536581327180185"
        "46660744755085898762033062199313"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}
