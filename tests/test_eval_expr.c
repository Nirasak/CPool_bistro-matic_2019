/*
** EPITECH PROJECT, 2019
** test_eval_expr.c
** File description:
** test eval_expr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "my.h"
#include "bistromatic.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

void redirect_stderr(void)
{
    cr_redirect_stderr();
}

int init_eval_expr(char **av, char *expr)
{
    nb_t *ans;

    ans = eval_expr(av[1], av[2], expr);
    free(expr);
    if (ans == NULL) {
        write(2, "syntax error", 12);
        return (84);
    }
    if (*(ans->nb) == '\0')
        my_putchar(av[1][0]);
    else {
        if (ans->sign == -1)
            my_putchar('-');
        my_putstr(ans->nb);
    }
    free(ans->nb);
    free(ans);
    return (EXIT_SUCCESS);
}

Test(eval_expr, test_eval_expr_priority, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup(
        "00+-00-0-0+00+02*01*(5%(04+(3-(0010/(050)))))*"
        "(50+0012-0500%002--300%1)");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str("620");
}

Test(eval_expr, test_eval_expr_big_one, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup(
        "(91827816491287649812764219-9128746981276948712642498"
        "76124)*(412098741246217864918247019287492689219047012"
        "412*(98472610462894892714628176491274692814+-14712087"
        "012984702918740928131293761298376123)/182736871263872"
        "13)+1");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str(
        "302840505471185192375895180251526339706415827148"
        "1802260717017912333960964025221524730500293025557"
        "62136581");
}

Test(eval_expr, test_eval_expr_big_two, .init = redirect_stdout)
{
    char *av[3] = {"./calc", "0123456789", "()+-*/%"};
    char *ex = my_strdup(
        "--+(91827816491287649812764219-++91287469812769487126"
        "4249876124)*-+-(-+41209874124621786491824701928749268"
        "9219047012412*-(9847261046289489271462817649127469281"
        "4+-14712087012984702918740928131293761298376123)/-182"
        "73687126387213)+-1");

    init_eval_expr(av, ex);
    cr_assert_stdout_eq_str(
        "-302840505471185192375895180251526339706415827148"
        "1802260717017912333960964025221524730500293025557"
        "62136581");
}
