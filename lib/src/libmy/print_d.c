/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put decimal
*/

#include <stdarg.h>
#include "my_puts.h"

int print_d(va_list ap)
{
    return (my_putnbr(va_arg(ap, int)));
}
