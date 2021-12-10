/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** malloc and set all to \0
*/

#include <stdlib.h>

char *my_calloc(int n)
{
    char *new = malloc(sizeof(char) * n);

    if (new == NULL)
        return (NULL);
    for (int i = 0; i < n; i++)
        new[i] = '\0';
    return (new);
}
