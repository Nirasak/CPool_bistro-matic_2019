/*
** EPITECH PROJECT, 2019
** infindiv
** File description:
** infinite division
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

static void div_loop_end(
    expr_t *expr, nb_t *infin_nums[2], char *result, char *str
)
{
    char *stock = infin_nums[1]->nb;
    int i = my_strlen(str);
    int j = 0;

    infin_nums[1]->nb = str;
    infin_nums[1]->len = my_strlen(str);
    for (; my_strcmp_custom(infin_nums[1]->nb, stock, expr->base) >= 0; ) {
        if (my_strcmp_custom(infin_nums[0]->nb, infin_nums[1]->nb,
                            expr->base) >= 0) {
            infinsub(expr, infin_nums);
            result[j] = expr->base[get_index_base(result[j], expr->base) + 1];
        } else {
            infin_nums[1]->nb[--i] = '\0';
            infin_nums[1]->len--;
            j++;
        }
    }
    free(stock);
}

static void div_loop(expr_t *expr, nb_t *infin_nums[2], char *result)
{
    int len[2] = {infin_nums[0]->len, infin_nums[1]->len};
    char *str = malloc(sizeof(char) * (len[0] + 2));
    int i = 0;
    int j = 0;

    check_malloc(str);
    for (; i < len[0]; i++) {
        if (i >= len[1]) {
            str[i] = expr->base[0];
            result[j++] = expr->base[0];
        } else
            str[i] = infin_nums[1]->nb[i];
    }
    str[i] = '\0';
    if (my_strcmp_custom(infin_nums[0]->nb, str, expr->base) >= 0)
        result[j++] = expr->base[0];
    else
        str[i - 1] = '\0';
    result[j] = '\0';
    div_loop_end(expr, infin_nums, result, str);
}

void infindiv(expr_t *expr, nb_t *infin_nums[2])
{
    char *result = NULL;
    char final_sign = infin_nums[0]->sign + infin_nums[1]->sign == 0 ? -1 : 1;
    int tmp = 0;

    if (find_lowest(infin_nums, expr->base) == 1) {
        result = malloc(sizeof(char));
        check_malloc(result);
        result[0] = '\0';
        infin_nums[0]->sign = 1;
        infin_nums[0]->len = 0;
    } else {
        tmp = infin_nums[0]->len - infin_nums[1]->len + 2;
        result = malloc(sizeof(char) * tmp);
        check_malloc(result);
        div_loop(expr, infin_nums, result);
        infin_nums[0]->sign = final_sign;
    }
    free(infin_nums[0]->nb);
    infin_nums[0]->nb = result;
}
