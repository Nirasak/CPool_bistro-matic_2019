/*
** EPITECH PROJECT, 2019
** test_infinmult.c
** File description:
** tests infinmult
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void test_put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg);
void test_get_number(expr_t *expr, nb_t *infin_nb);

nb_t *init_high_op(char * const *av, char const *str, char op)
{
    expr_t expr = {my_strlen(av[1]), av[1], av[2], str};
    nb_t *infin_nums[2] = {
        malloc(sizeof(nb_t)), malloc(sizeof(nb_t)),
    };

    test_get_number(&expr, infin_nums[0]);
    expr.expr++;
    test_get_number(&expr, infin_nums[1]);
    do_high_op(&expr, infin_nums, op);
    free(infin_nums[1]);
    return (infin_nums[0]);
}

Test(infinmult, test_infinmult_simple)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "2*3"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "6");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_size_handling_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "4*5"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "20");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_size_handling_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "5*200"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "1000");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_size_handling_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99*99"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "9801");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_with_negative_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-4*25"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "100");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_with_negative_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "25*-4"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(answer->nb, "100");
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_big_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999999*"
        "777777777777777777777777777777777777777777777777777777"
        "777777777777777777777777777777777777777777777777"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(
        answer->nb,
        "7777777777777777777777777777777777777777777777777777699999999"
        "9999999999999999999999999999999999999999922222222222222222222"
        "222222222222222222222222222222223"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_big_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "53287632572309573276537265092387529108652716490217508376595861"
        "9735783269562109874921861297664298769874621987642*124691287460"
        "12946286489376487367643765347268974691264126049261428164821547"
        "85276814527816489216482517681"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(
        answer->nb,
        "66445035111436110071108596936826219183602376400137394545409030"
        "81424585619751033345833286754768905400705056785235780574499920"
        "68166489130049050716326309713459239729318004006724554489005140"
        "242759251233530900628498202"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinmult, test_infinmult_big_3)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-53287632572309573276537265092387529108652716490217508376595861"
        "9735783269562109874921861297664298769874621987642*1246912874601"
        "294628648937648736764376534726897469126412604926142816482154785"
        "276814527816489216482517681"
    );
    nb_t *answer = init_high_op(av, expr, '*');

    cr_assert_str_eq(
        answer->nb,
        "66445035111436110071108596936826219183602376400137394545409030"
        "814245856197510333458332867547689054007050567852357805744999206"
        "816648913004905071632630971345923972931800400672455448900514024"
        "2759251233530900628498202"
    );
    cr_assert_eq(answer->sign, -1);
    free(answer->nb);
    free(answer);
}
