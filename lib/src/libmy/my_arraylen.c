/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** get length of array
*/

#include <stddef.h>

int my_arraylen(char **words)
{
    int i = 0;

    while (words[i] != NULL)
        i++;
    return (i);
}
