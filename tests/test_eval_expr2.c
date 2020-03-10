/*
** EPITECH PROJECT, 2019
** test_eval_expr2.c
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

Test(eval_expr, test_eval_expr_operator_priority_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("3+4*2");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("11");
}

Test(eval_expr, test_eval_expr_operator_priority_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("3*4+2");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("14");
}

Test(eval_expr, test_eval_expr_operator_priority_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("3-4-2");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("-3");
}

Test(eval_expr, test_eval_expr_unary_operator_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("--++-6*12");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("-72");
}

Test(eval_expr, test_eval_expr_unary_operator_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("6*--++-12");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("-72");
}

Test(eval_expr, test_eval_expr_unary_operator_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("--+++++--6*--++--12");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("72");
}

Test(eval_expr, test_eval_expr_with_parenthesis_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("(2+5)*2");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("14");
}

Test(eval_expr, test_eval_expr_with_parenthesis_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("(18+42)+5*42");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("270");
}

Test(eval_expr, test_eval_expr_with_parenthesis_3, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("5+(((((2+4)*8+50*(10+1))+20)-42)+3*2)");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("587");
}

Test(eval_expr, test_eval_expr_with_parenthesis_4, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup("(-((5+(((((2+4)*8+50*(10+1))+20)-42)+3*2))))");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("-587");
}

Test(eval_expr, test_eval_expr_with_big_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup(
        "(91827816491287649812764219-912874698127694871264249876124)*(41"
        "2098741246217864918247019287492689219047012412*(984726104628948"
        "92714628176491274692814+-14712087012984702918740928131293761298"
        "376123)/18273687126387213)+1");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str(
        "302840505471185192375895180251526339706415827148180226071701791"
        "233396096402522152473050029302555762136581");
}

Test(eval_expr, test_eval_expr_with_big_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup(
        "--+(91827816491287649812764219-++912874698127694871264249876124"
        ")*-+-(-+412098741246217864918247019287492689219047012412*-(9847"
        "2610462894892714628176491274692814+-147120870129847029187409281"
        "31293761298376123)/-18273687126387213)+-1");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str(
        "-30284050547118519237589518025152633970641582714818022607170179"
        "1233396096402522152473050029302555762136581");
}
