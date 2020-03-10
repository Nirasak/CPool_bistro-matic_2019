/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sort_int_array
*/
#include "my.h"

void my_sort_int_array(int *array , int size)
{
    int index = 0;
    int temp_int = 0;

    while (index < size - 1) {
        if (array[index] > array[index + 1]) {
            temp_int = array[index];
            array[index] = array[index + 1];
            array[index + 1] = temp_int;
            index = 0;
        } else {
            index++;
        }
    }
}
