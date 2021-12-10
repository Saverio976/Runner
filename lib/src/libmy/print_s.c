/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and print str
*/

#include <stdarg.h>
#include "my_puts.h"

int print_s(va_list ap)
{
    return (my_putstr(va_arg(ap, char *)));
}
