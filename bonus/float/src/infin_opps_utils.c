/*
** EPITECH PROJECT, 2019
** infin_opps_utils
** File description:
** utils for infin operations
*/

#include "bistromatic.h"

int find_lowest(nb_t *infin_nums[2], char const *base)
{
    char *nb1;
    char *nb2;

    if (infin_nums[0]->len != infin_nums[1]->len)
        return (infin_nums[0]->len < infin_nums[1]->len);
    nb1 = infin_nums[0]->nb;
    nb2 = infin_nums[1]->nb;
    while (*nb1 == *nb2 && *nb1 != '\0') {
        nb1++;
        nb2++;
    }
    return (get_index_base(*nb1, base) < get_index_base(*nb2, base));
}

int get_index_base(char digit, char const *base)
{
    char const *tmp = base;

    while (*tmp != digit)
        tmp++;
    return (tmp - base);
}

int my_strcmp_custom(char const *s1, char const *s2, char const *base)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] != '\0')
        return (1);
    if (s2[i] != '\0')
        return (-1);
    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return (get_index_base(s1[i], base) - get_index_base(s2[i], base));
}
