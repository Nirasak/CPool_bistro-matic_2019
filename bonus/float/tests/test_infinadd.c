/*
** EPITECH PROJECT, 2019
** test_infinadd.c
** File description:
** tests infinadd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

void test_put_nbr_in_infin_nb(expr_t *expression, nb_t *infin_nb, char isneg)
{
    unsigned int nb_len = get_nb_size(expression);
    char const *expr = expression->expr;
    char *nb = malloc(sizeof(char) * (nb_len + 1));

    check_malloc(nb);
    infin_nb->sign = isneg;
    infin_nb->len = nb_len;
    infin_nb->nb = nb;
    while (nb_len--)
        *nb++ = *expr++;
    *nb = '\0';
    expression->expr = expr;
}

void test_get_number(expr_t *expr, nb_t *infin_nb)
{
    signed char isneg = 1;

    while (c_in_str(*(expr->expr), expr->base) == 0 &&
        *(expr->expr) != expr->ops[OP_OPEN_PARENT_IDX]) {
        if (*(expr->expr)++ == expr->ops[OP_NEG_IDX])
            isneg *= -1;
    }
    test_put_nbr_in_infin_nb(expr, infin_nb, isneg);
}

nb_t *init_low_op(char * const *av, char const *str)
{
    expr_t expr = {my_strlen(av[1]), av[1], av[2], str};
    nb_t *infin_nums[2] = {
        malloc(sizeof(nb_t)), malloc(sizeof(nb_t)),
    };

    test_get_number(&expr, infin_nums[0]);
    test_get_number(&expr, infin_nums[1]);
    do_low_op(&expr, infin_nums);
    free(infin_nums[1]);
    return (infin_nums[0]);
}

Test(infinadd, test_infinadd_simple_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "21+21"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "42");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_simple_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "18+24"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "42");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_size_handling_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "100+1"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "101");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_size_handling_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "1+100"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "101");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_with_remainder)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("9999999+1");
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(answer->nb, "10000000");
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_big_1)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999"
        "999999+22222222222222222222222222222222222222222222"
        "222222222222222222222222222222222222"
    );
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "222222222222222222222223222222222222222222222222222"
        "22222222222222222222222222221"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}

Test(infinadd, test_infinadd_big_2)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "5126748128762421244912841241278945921874128954297186"
        "428164521894612+658376982360812764086583601260491274"
        "9612784618752091649126478589214627164897252");
    nb_t *answer = init_low_op(av, expr);

    cr_assert_str_eq(
        answer->nb,
        "6583769823613254388994598433849825590854063564673965"
        "778080775775642791686791864"
    );
    cr_assert_eq(answer->sign, 1);
    free(answer->nb);
    free(answer);
}
