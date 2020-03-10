/*
** EPITECH PROJECT, 2019
** test_eval_expr_add.c
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

Test(eval_expr, test_eval_expr_add_simple_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("21+21");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("42");
}

Test(eval_expr, test_eval_expr_add_simple_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("18+24");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("42");
}

Test(eval_expr, test_eval_expr_add_size_handling_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("100+1");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("101");
}

Test(eval_expr, test_eval_expr_add_size_handling_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("1+100");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("101");
}

Test(eval_expr, test_eval_expr_add_with_remainder, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup("9999999+1");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str("10000000");
}

Test(eval_expr, test_eval_expr_add_big_1, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "99999999999999999999999999999999999999999999999999"
        "999999+22222222222222222222222222222222222222222222"
        "222222222222222222222222222222222222"
    );

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "222222222222222222222223222222222222222222222222222"
        "22222222222222222222222222221"
    );
}

Test(eval_expr, test_eval_expr_add_big_2, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *expr = my_strdup(
        "5126748128762421244912841241278945921874128954297186"
        "428164521894612+658376982360812764086583601260491274"
        "9612784618752091649126478589214627164897252");

    init_eval_expr(av, expr);
    cr_assert_stdout_eq_str(
        "6583769823613254388994598433849825590854063564673965"
        "778080775775642791686791864"
    );
}
