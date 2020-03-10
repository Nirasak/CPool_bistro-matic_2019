/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** strncat
*/

char *my_strncat(char *dest, char const *src, int nb);

char *my_strncat(char *dest, char const *src, int nb)
{
    int index = 0;

    while (dest[index] != '\0')
        index++;
    while (nb-- > 0 && *src != '\0')
        dest[index++] = *src++;
    dest[index] = '\0';
    return (dest);
}
