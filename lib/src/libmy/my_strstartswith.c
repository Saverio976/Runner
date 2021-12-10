/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** check is str starts with str
*/

#include "my_strings.h"

int my_strstartswith(char const *str, char const *s)
{
    int i = 0;
    int size = my_strlen(s);

    while (str[i] != '\0' && s[i] != '\0' && str[i] == s[i])
        i++;
    if (i == size)
        return (1);
    return (0);
}
