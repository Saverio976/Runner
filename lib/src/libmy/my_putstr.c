/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put str to stdout
*/

#include <unistd.h>
#include "my_strings.h"

int my_putstr(char const *str)
{
    int size = my_strlen(str);

    return (write(1, str, size));
}
