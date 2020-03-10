/*
** EPITECH PROJECT, 2019
** test_infinmod.c
** File description:
** tests infinmod
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

Test(infinmod, test_infinmod_simple_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "6%2"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_simple_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "2%10"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "2");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_size_handling_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "100%4"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_size_handling_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99%2"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "1");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_size_handling_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99%99"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_with_negative_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-99%5"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "4");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_with_negative_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-100%-6"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(answer->nb, "4");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_big_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999%"
        "22222222222222222222222222222222222222222222222222"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(
        answer->nb,
        "11111111111111111111111111111111111111111111111111"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_big_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "53287632572309573276537265092387529108652716490217508376595"
        "8619735783269562109874921861297664298769874621987642%124691"
        "28746012946286489376487367643765347268974691264126049261428"
        "16482154785276814527816489216"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(
        answer->nb,
        "92016717695868382735940627546950693279789919135842608627813"
        "3629785907078296694601764571317306"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmod, test_infinmod_big_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-5328763257230957327653726509238752910865271649021750837659"
        "58619735783269562109874921861297664298769874621987642%12469"
        "12874601294628648937648736764376534726897469126412604926142"
        "816482154785276814527816489216"
    );
    nb_t *answer = init_high_op(av, expr, '%');

    cr_assert_str_eq(
        answer->nb,
        "9201671769586838273594062754695069327978991913584260862781"
        "33629785907078296694601764571317306"
    );
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}
