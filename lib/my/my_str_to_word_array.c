/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char const *str)
{
    int word_count = 0;
    char **word_array;
    int index = 0;

    while (*str != '\0' && isalphanum(*str) == 0)
        str++;
    if (*str == '\0') {
        word_array = malloc(sizeof(word_array));
        *word_array = 0;
        return (word_array);
    }
    word_count = count_valid_words(str);
    word_array = malloc(sizeof(word_array) * (word_count + 1));
    while (index < word_count && *str != '\0')
        str = put_word_in_array(word_array, str, index++);
    word_array[index] = 0;
    return (word_array);
}

char const *put_word_in_array(char **word_array, char const *str, int index)
{
    int word_length = 0;
    int index2 = 0;

    while (isalphanum(str[word_length]) == 1)
        word_length++;
    word_array[index] = malloc(sizeof(word_array[index]) * (word_length + 1));
    while (index2 < word_length && *str != '\0')
        word_array[index][index2++] = *str++;
    word_array[index][index2] = '\0';
    while (isalphanum(*str) == 0 && *str != '\0')
        str++;
    return (str);
}

int isalphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
        return (1);
    return (0);
}

int count_valid_words(char const *str)
{
    int last_isalphanum = 0;
    int word_count = 1;

    while (*str != '\0') {
        if (isalphanum(*str) == 0 && last_isalphanum == 1) {
            word_count++;
            last_isalphanum = 0;
        } else if (isalphanum(*str) == 1)
            last_isalphanum = 1;
        str++;
    }
    return (word_count);
}
