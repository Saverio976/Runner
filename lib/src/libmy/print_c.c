/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist, and print char
*/

#include <stdarg.h>
#include "my_puts.h"

int print_c(va_list ap)
{
    return (my_putchar(va_arg(ap, int)));
}
