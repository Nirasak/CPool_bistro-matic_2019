/*
** EPITECH PROJECT, 2019
** test_eval_expr_div.c
** File description:
** test eval_expr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

void redirect_stdout(void);
void redirect_stderr(void);
int init_eval_expr(char **av, char *expr);

Test(eval_expr, test_eval_expr_div_simple_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("6/2");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("3");
}

Test(eval_expr, test_eval_expr_div_simple_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("2/10");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("0");
}

Test(eval_expr, test_eval_expr_div_size_handling_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("100/4");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("25");
}

Test(eval_expr, test_eval_expr_div_size_handling_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("99/2");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("49");
}

Test(eval_expr, test_eval_expr_div_size_handling_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("99/99");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("1");
}

Test(eval_expr, test_eval_expr_div_with_negative_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("-99/5");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-19");
}

Test(eval_expr, test_eval_expr_div_with_negative_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("-100/-6");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("16");
}

Test(eval_expr, test_eval_expr_div_big_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999/"
        "22222222222222222222222222222222222222222222222222"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("4");
}

Test(eval_expr, test_eval_expr_div_big_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "53287632572309573276537265092387529108652716490217508376595"
        "8619735783269562109874921861297664298769874621987642/124691"
        "28746012946286489376487367643765347268974691264126049261428"
        "16482154785276814527816489216"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("427356503070421071");
}

Test(eval_expr, test_eval_expr_div_big_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "-5328763257230957327653726509238752910865271649021750837659"
        "58619735783269562109874921861297664298769874621987642/12469"
        "12874601294628648937648736764376534726897469126412604926142"
        "816482154785276814527816489216"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("-427356503070421071");
}
