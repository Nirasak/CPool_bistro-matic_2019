/*
** EPITECH PROJECT, 2019
** test_eval_expr_mult.c
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

Test(eval_expr, test_eval_expr_mult_simple, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("2*3");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("6");
}

Test(eval_expr, test_eval_expr_mult_size_handling_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("4*5");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("20");
}

Test(eval_expr, test_eval_expr_mult_size_handling_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("5*200");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("1000");
}

Test(eval_expr, test_eval_expr_mult_size_handling_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("99*99");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("9801");
}

Test(eval_expr, test_eval_expr_mult_with_negative_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("-4*25");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-100");
}

Test(eval_expr, test_eval_expr_mult_with_negative_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("25*-4");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-100");
}

Test(eval_expr, test_eval_expr_mult_big_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999999*"
        "777777777777777777777777777777777777777777777777777777"
        "777777777777777777777777777777777777777777777777"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "7777777777777777777777777777777777777777777777777777699999999"
        "9999999999999999999999999999999999999999922222222222222222222"
        "222222222222222222222222222222223"
    );
}

Test(eval_expr, test_eval_expr_mult_big_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "53287632572309573276537265092387529108652716490217508376595861"
        "9735783269562109874921861297664298769874621987642*124691287460"
        "12946286489376487367643765347268974691264126049261428164821547"
        "85276814527816489216482517681"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "66445035111436110071108596936826219183602376400137394545409030"
        "81424585619751033345833286754768905400705056785235780574499920"
        "68166489130049050716326309713459239729318004006724554489005140"
        "242759251233530900628498202"
    );
}

Test(eval_expr, test_eval_expr_mult_big_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-53287632572309573276537265092387529108652716490217508376595861"
        "9735783269562109874921861297664298769874621987642*1246912874601"
        "294628648937648736764376534726897469126412604926142816482154785"
        "276814527816489216482517681"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "-66445035111436110071108596936826219183602376400137394545409030"
        "814245856197510333458332867547689054007050567852357805744999206"
        "816648913004905071632630971345923972931800400672455448900514024"
        "2759251233530900628498202"
    );
}
