/*
** EPITECH PROJECT, 2019
** test_infindiv.c
** File description:
** tests infindiv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void test_put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg);
void test_get_number(expr_t *expr, nb_t *infin_nb);
nb_t *init_high_op(char * const *av, char const *str, char op);

Test(infindiv, test_infindiv_simple_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "6/2"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "3");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_simple_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "2/10"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_size_handling_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "100/4"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "25");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_size_handling_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99/2"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "49");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_size_handling_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99/99"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "1");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_with_negative_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-99/5"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "19");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_with_negative_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-100/-6"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(answer->nb, "16");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_big_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999/"
        "22222222222222222222222222222222222222222222222222"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(
        answer->nb,
        "4"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_big_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "53287632572309573276537265092387529108652716490217508376595"
        "8619735783269562109874921861297664298769874621987642/124691"
        "28746012946286489376487367643765347268974691264126049261428"
        "16482154785276814527816489216"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(
        answer->nb,
        "427356503070421071"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infindiv, test_infindiv_big_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-5328763257230957327653726509238752910865271649021750837659"
        "58619735783269562109874921861297664298769874621987642/12469"
        "12874601294628648937648736764376534726897469126412604926142"
        "816482154785276814527816489216"
    );
    nb_t *answer = init_high_op(av, expr, '/');

    cr_assert_str_eq(
        answer->nb,
        "427356503070421071"
    );
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}
