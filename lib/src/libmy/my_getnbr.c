/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** try to transform a string to an int
*/

#include "my_strings.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb_minus = 0;
    int result = 0;

    if (!*str)
        return (0);
    while (my_strinclude("\b\t\n\v\f\r ", str[i]))
        i++;
    while (my_strinclude("+-", str[i])) {
        i++;
        if (str[i] == '-')
            nb_minus++;
    }
    while (my_strinclude("0123456789", str[i])) {
        result = result * 10;
        result = result + (str[i] - '0');
        i++;
    }
    return (result);
}
