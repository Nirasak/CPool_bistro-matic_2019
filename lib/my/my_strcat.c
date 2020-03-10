/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** strcat
*/

char *my_strcat(char *dest, char const *src);

char *my_strcat(char *dest, char const *src)
{
    int index = 0;

    while (dest[index] != '\0')
        index++;
    while (*src != '\0')
        dest[index++] = *src++;
    dest[index] = '\0';
    return (dest);
}
