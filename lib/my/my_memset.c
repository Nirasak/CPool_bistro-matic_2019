/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** memset
*/

void my_memset(char *str, int n, char value)
{
    while (n-- > 0)
        *str++ = value;
}
